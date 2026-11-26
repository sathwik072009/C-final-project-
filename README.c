#include <stdio.h>

#define MAX 5   // Maximum number of products

int main()
{
    
    int ids[MAX];
    char names[MAX][20];
    float prices[MAX];
    int quantities[MAX];

    
    int count = 0;    
    int choice;       
    int i;            
    int id;           
    int pos;          
    int newqty;       

    
    do
    {
        printf("\n====================================\n");
        printf("       PRODUCT INVENTORY SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Display All Products\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");

        printf("====================================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

       
        switch(choice)
        {
            
            case 1:

                if(count == MAX)
                {
                    printf("\nInventory is full!\n");
                }
                else
                {
                    printf("Enter Product ID: ");
                    scanf("%d", &ids[count]);

                    printf("Enter Product Name: ");
                    scanf(" %19[^\n]", names[count]);

                    printf("Enter Product Price: ");
                    scanf("%f", &prices[count]);

                    printf("Enter Product Quantity: ");
                    scanf("%d", &quantities[count]);

                    count++;

                    printf("\nProduct added successfully!\n");
                }

                break;

            
            case 2:

                if(count == 0)
                {
                    printf("\nInventory is empty!\n");
                }
                else
                {
                    printf("Enter Product ID to search: ");
                    scanf("%d", &id);

                    
                    pos = -1;

                    for(i = 0; i < count; i++)
                    {
                        if(ids[i] == id)
                        {
                            pos = i;
                            break;
                        }
                    }

                    if(pos == -1)
                    {
                        printf("\nProduct not found!\n");
                    }
                    else
                    {
                        printf("\nProduct found!\n");
                        printf("==============================\n");

                        printf("ID       : %d\n", ids[pos]);
                        printf("Name     : %s\n", names[pos]);
                        printf("Price    : %.2f\n", prices[pos]);
                        printf("Quantity : %d\n", quantities[pos]);

                        printf("==============================\n");
                    }
                }

                break;

            
            case 3:

                if(count == 0)
                {
                    printf("\nInventory is empty!\n");
                }
                else
                {
                    printf("\n%-8s %-20s %-12s %-10s\n",
                           "ID", "Name", "Price", "Quantity");

                    printf("--------------------------------------------------\n");

                    
                    for(i = 0; i < count; i++)
                    {
                        printf("%-8d %-20s %-12.2f %-10d\n",
                               ids[i], names[i],
                               prices[i], quantities[i]);
                    }
                }

                break;

            
            case 4:

                if(count == 0)
                {
                    printf("\nInventory is empty!\n");
                }
                else
                {
                    printf("Enter Product ID to update: ");
                    scanf("%d", &id);

                   
                    pos = -1;

                    for(i = 0; i < count; i++)
                    {
                        if(ids[i] == id)
                        {
                            pos = i;
                            break;
                        }
                    }

                    if(pos == -1)
                    {
                        printf("\nProduct not found!\n");
                    }
                    else
                    {
                        printf("Current Quantity: %d\n",
                               quantities[pos]);

                        printf("Enter new quantity: ");
                        scanf("%d", &newqty);

                        quantities[pos] = newqty;

                        printf("\nQuantity updated successfully!\n");
                    }
                }

                break;

            
            case 5:

                printf("\nExiting Program. Goodbye!\n");
                break;

           
            default:

                printf("\nInvalid choice! Enter 1 to 5.\n");
        }

    } while(choice != 5);

    return 0;
}
