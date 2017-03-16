#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

const int MAX_DIGITS = 102;

bool big_number_greater_than(const char a[], const char b[])
{
    if (strlen(a) < strlen(b))
    {
        return false;
    }
    else if (strlen(a) > strlen(b))
    {
        return true;
    }
    else
    {
        int i = 0;
        while (a[i] != '\0' && a[i] == b[i])
        {
            i++;
        }
        return a[i] > b[i];
    }
}

bool big_number_equal_to(const char a[], const char b[])
{
    if (strlen(a) < strlen(b))
    {
        return false;
    }
    else if (strlen(a) > strlen(b))
    {
        return false;
    }
    else
    {
        int i = 0;
        while (a[i] != '\0' && a[i] == b[i])
        {
            i++;
        }
        return a[i] == b[i];
    }
}

bool big_number_greater_than_or_equal_to(const char a[], const char b[])
{
    if (strlen(a) < strlen(b))
    {
        return false;
    }
    else if (strlen(a) > strlen(b))
    {
        return true;
    }
    else
    {
        int i = 0;
        while (a[i] != '\0' && a[i] == b[i])
        {
            i++;
        }
        return a[i] >= b[i];
    }
}

bool big_number_less_than(const char a[], const char b[])
{
    return !big_number_greater_than_or_equal_to(a, b);
}

bool big_number_less_than_or_equal_to(const char a[], const char b[])
{
    return !big_number_greater_than(a, b);
}

void big_number_multiply(char a[], char b[], char o[])
{
    int r[MAX_DIGITS + 1];
    memset(r, 0, sizeof(r[0]) * (MAX_DIGITS + 1));
    int string_length_a = strlen(a);
    int string_length_b = strlen(b);
    int string_length_r = string_length_a + string_length_b;
    for (int i = string_length_b - 1; i >= 0; i--)
    {
        for (int j = string_length_a - 1; j >= 0; j--)
        {
            r[(string_length_b - i - 1) + (string_length_a - j - 1)] += (b[i] - '0') * (a[j] - '0');
        }
    }
//    printf("r[]: %d, %d, %d\n", r[0], r[1], r[2]);
    for (int i = 0; i < string_length_r; i++)
    {
        r[i + 1] += r[i] / 10;
        r[i] = r[i] % 10;
    }
//    printf("r[]: %d, %d, %d\n", r[0], r[1], r[2]);
    while (r[string_length_r] == 0)
    {
        string_length_r--;
    }
    string_length_r++;
//    printf("string_length: %d\n", string_length_r);
    for (int i = string_length_r - 1; i >=0; i--)
    {
        o[string_length_r - i - 1] = r[i] + '0';
    }
    o[string_length_r] = '\0';
}

void next_fair_number(char a[], char o[])
{
    strcpy(o, a);
    int string_length = strlen(o);
    int center_index = (string_length - 1) >> 1;
    o[center_index]++;
    bool need_to_extend = false;
    for (int i = center_index; i >= 0; i--)
    {
        if (o[i] > '9')
        {
            o[i] = '0';
            if (i > 0)
            {
                o[i - 1]++;
            }
            else
            {
                need_to_extend = true;
                break;
            }
        }
    }
    if (need_to_extend)
    {
        o[0] = o[string_length] = '1';
        o[string_length + 1] = '\0';
        for (int i = 1; i < (string_length >> 1) + 1; i++)
        {
            o[i] = o[string_length - i] = '0';
        }
    }
    else
    {
        for (int i = center_index + 1; i < string_length; i++)
        {
            o[i] = o[string_length - i - 1];
        }
    }
}

bool is_fair(char a[])
{
    int string_length = strlen(a);
    for (int i = string_length >> 1; i >= 0; i--)
    {
        if (a[i] != a[string_length - i - 1])
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> lookup_table;

void generate_lookup_table()
{
    char boundary[MAX_DIGITS + 1] = "10000000";
    char fair_number[MAX_DIGITS + 1] = "1";
    while (big_number_greater_than_or_equal_to(boundary, fair_number))
    {
        char fair_number_square[MAX_DIGITS + 1];
//        printf("fair_number: %s\n", fair_number);
        big_number_multiply(fair_number, fair_number, fair_number_square);
//        printf("fair_number_square: %s\n", fair_number_square);
        if (is_fair(fair_number_square))
        {
            lookup_table.push_back(fair_number_square);
//            if (big_number_greater_than_or_equal_to("1000", fair_number_square))
//            {
//                printf("%s\n", fair_number_square);
//            }
        }
        next_fair_number(fair_number, fair_number);
    }
}

int main(void)
{
//    char fair_number[MAX_DIGITS + 1] = "1";
//    char fair_number_square[MAX_DIGITS + 1];
//    for (int i = 0; i < 15; i++)
//    {
//        next_fair_number(fair_number, fair_number);
//        big_number_multiply(fair_number, fair_number, fair_number_square);
//        printf("[%d]fair_number: %s, %s\n", i, fair_number, fair_number_square);
//    }
    // preparation
    generate_lookup_table();
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d: %s\n", i, lookup_table[i].c_str());
//    }

    int T = 0;
    scanf("%d", &T);

    for (int t = 1; t < T + 1; t++)
    {
        char A[MAX_DIGITS + 1];
        char B[MAX_DIGITS + 1];
        scanf("%s %s", A, B);

        // binary search
        int index_a = 0;
        int index_b = 0;

        int index_l = 0;
        int index_r = lookup_table.size() - 1;

        // left boundary
        index_l = 0;
        index_r = lookup_table.size() - 1;
        index_a = (index_l + index_r) >> 1;
        while (index_l < index_r)
        {
            if (big_number_greater_than_or_equal_to(lookup_table[index_a].c_str(), A))
            {
                index_r = index_a;
                index_a = (index_l + index_r) >> 1;
//                printf("1: %d(%s) %d(%s) %d(%s)\n", index_l, lookup_table[index_l].c_str(), index_a, lookup_table[index_a].c_str(), index_r, lookup_table[index_r].c_str());
            }
            if (big_number_less_than(lookup_table[index_a].c_str(), A))
            {
                index_l = index_a + 1;
                index_a = (index_l + index_r + 1) >> 1;
//                printf("2: %d(%s) %d(%s) %d(%s)\n", index_l, lookup_table[index_l].c_str(),  index_a, lookup_table[index_a].c_str(), index_r, lookup_table[index_r].c_str());
            }
        }
        
        // right boundary
        index_l = 0;
        index_r = lookup_table.size() - 1;
        index_b = (index_l + index_r) >> 1;
        while (index_l < index_r)
        {
            if (big_number_greater_than(lookup_table[index_b].c_str(), B))
            {
                index_r = index_b - 1;
                index_b = (index_l + index_r) >> 1;
//                printf("3: %d(%s) %d(%s) %d(%s)\n", index_l, lookup_table[index_l].c_str(), index_b, lookup_table[index_b].c_str(), index_r, lookup_table[index_l].c_str());
            }
            if (big_number_less_than_or_equal_to(lookup_table[index_b].c_str(), B))
            {
                index_l = index_b;
                index_b = (index_l + index_r + 1) >> 1;
//                printf("4: %d(%s) %d(%s) %d(%s)\n", index_l, lookup_table[index_l].c_str(), index_b, lookup_table[index_b].c_str(), index_r, lookup_table[index_l].c_str());
            }
        }

        // output
        printf("Case #%d: %d\n", t, (index_a > index_b) ? 0 : index_b - index_a + 1);
    }

    return 0;
}
