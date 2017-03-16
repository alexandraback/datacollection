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

        char table[4][4] = {0};

        bool not_finished = false;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char input_char = 0;
                scanf("%c ", &input_char);

                switch(input_char)
                {
                    case '.':
                        table[i][j] = 0;
                        not_finished = true;
                        break;
                    case 'X':
                        table[i][j] = 1;
                        break;
                    case 'O':
                        table[i][j] = 2;
                        break;
                    case 'T':
                        table[i][j] = 3;
                        break;
                }

            }
        }

        bool test_case_won[2] = {false};

        for (char test_case = 1; test_case <= 2; test_case++)
        {
            char and_table[4][4] = {0};
            
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    and_table[i][j] = table[i][j] & test_case;
                }
            }

            int test_case_equal = 4 * test_case;

            test_case_won[test_case - 1] = false;

            for (int i = 0; i < 4; i++)
            {
                int horizontal_sum = 0;
                int vertical_sum = 0;

                for (int j = 0; j < 4; j++)
                {
                    horizontal_sum += and_table[i][j];
                    vertical_sum += and_table[j][i];
                }

                if (horizontal_sum == test_case_equal ||
                    vertical_sum == test_case_equal)
                {
                    test_case_won[test_case - 1] = true;
                }
            }

            //diagonal

            int diagonal_sum = 0;
            int diagonal_sum_2 = 0;

            for (int i = 0; i < 4; i++)
            {
                diagonal_sum += and_table[i][i];
                diagonal_sum_2 += and_table[i][4 - i - 1];
            }

            if (diagonal_sum == test_case_equal || diagonal_sum_2 == test_case_equal)
            {
                test_case_won[test_case - 1] = true;
            }

        }

        printf("Case #%d:", ++dataset_index);
        
        if (test_case_won[0])
        {
            printf(" X won\n");
        }
        else if (test_case_won[1])
        {
            printf(" O won\n");
        }
        else if (not_finished)
        {
            printf(" Game has not completed\n");
        }
        else
        {
            printf(" Draw\n");
        }


    }
    return 0;
}
