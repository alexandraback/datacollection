#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int total_dataset_number = 0;

    scanf("%d ", &total_dataset_number);

    int dataset_index = 0;

    int total_square[5] = {1, 4, 9, 121, 484};


    while(total_dataset_number--)
    {
        int min = 0;
        int max = 0;

        scanf("%d ", &min);
        scanf("%d ", &max);

        int number_of_square = 0;

        for (int i = 0; i < 5; i++)
        {
            if (total_square[i] >= min && total_square[i] <= max)
            {
                number_of_square++;
            }
        }

        printf("Case #%d: %d\n", ++dataset_index, number_of_square);

    }
    return 0;
}
