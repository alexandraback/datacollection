#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool is_palindrome(long long input_value)
{
    char string_value[20];

    sprintf(string_value, "%lld", input_value);

    int string_half_length = strlen(string_value) / 2;
    int string_length = strlen(string_value);

    bool is_palindrome = true;

    for (int i = 0; i < string_half_length; i++)
    {
        if (string_value[i] != string_value[string_length - 1 - i])
            is_palindrome = false;
    }

    return is_palindrome;
}


int main(void)
{
    int total_dataset_number = 0;

    scanf("%d ", &total_dataset_number);

    int dataset_index = 0;

    vector<long long> fair_list;

    for (long long i = 0; i < 10000000; i++)
    {
         if (is_palindrome(i))
         {
            long long square_i = i * i;
            if (is_palindrome(square_i))
            {
                fair_list.push_back(square_i);
            }
         }
    }

    while(total_dataset_number--)
    {
        long long min = 0;
        long long max = 0;

        scanf("%lld ", &min);
        scanf("%lld ", &max);

        int fair_count = 0;

        for (int i = 0; i < fair_list.size(); i++)
        {
            if (fair_list[i] >= min &&
                fair_list[i] <= max)
            {
                fair_count++;
            }
        }

        printf("Case #%d: %d\n", ++dataset_index, fair_count);

    }
    return 0;
}
