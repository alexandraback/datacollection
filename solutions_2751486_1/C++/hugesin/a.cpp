#include<iostream>
using namespace std;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c ==  'i' || c == 'o' || c == 'u';
}
int main()
{
    int case_num, n;
    cin >> case_num;
    for (n = 1; n <= case_num; n++)
    {
        string str;
        long long m, i, len;
        long long count = 0;
        long long last_begin(-1), last_count;
        cin >> str >> m;
        len = str.length();
        long long* res = new long long[len];
        if (is_vowel(str[0]))
        {
            res[0] = 0;
        }
        else
        {
            res[0] = 1;
        }
        for (i = 1; i < len; i ++)
        {
            if (!is_vowel(str[i]))
            {
                res[i] = res[i-1] + 1;
            }
            else
            {
                res[i] = 0;
            }
        }
        for (i = 0; i < len ; i++)
        {
            if (res[i] >= m)
            {
                last_begin = i - m + 1;
                last_count = 1 + last_begin;
                count += last_count;
            }
            else if (last_begin != -1)
            {
                count += last_count;
            }
        }
        cout << "Case #" << n << ": " << count << endl;
        delete[] res;
    }
    return 0;
}
