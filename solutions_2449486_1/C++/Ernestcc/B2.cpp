#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int total_dataset_number = 0;

    scanf("%d ", &total_dataset_number);

    int dataset_index = 0;
    
    while(total_dataset_number--)
    {
        int width = 0;
        int height = 0;

        scanf("%d ", &height);
        scanf("%d ", &width);

        char table[100][100] = {0};

        char vertical_max[100] = {0};
        char horizontal_max[100] = {0};

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int input_value = 0;
                scanf("%d ", &input_value);
                table[i][j] = input_value;
            }
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (horizontal_max[i] < table[i][j])
                    horizontal_max[i] = table[i][j];
            }
        }

        for (int j = 0; j < width; j++)
        {
            for (int i = 0; i < height; i++)
            {
                if (vertical_max[j] < table[i][j])
                    vertical_max[j] = table[i][j];
            }
        }

        if (width == 1 || height == 1)
        {
            printf("Case #%d: YES\n", ++dataset_index);
        }
        else
        {
            bool is_case_valid = true;

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (table[i][j] < horizontal_max[i] &&
                        table[i][j] < vertical_max[j])
                    {
                        is_case_valid = false;
                        break;
                    }

                }

                if (!is_case_valid)
                    break;
            }

            
            if (is_case_valid)
            {
                printf("Case #%d: YES\n", ++dataset_index);
            }
            else
            {
                printf("Case #%d: NO\n", ++dataset_index);
            }

        }

    }
    return 0;
}
