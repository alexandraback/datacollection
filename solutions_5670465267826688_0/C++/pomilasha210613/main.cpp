#include <bits/stdc++.h>

using namespace std;

string s, s1;
int n, t;

char check(int &sum, char c1, char c2)
{
    if (c1 == '1')
        return c2;
    if (c2 == '1')
        return c1;
    if (c1 == c2)
    {
        sum = (sum + 1) % 2;
        return '1';
    }
    if (c1 == 'i')
    {
        if (c2 == 'j')
            return 'k';
        else {
                sum = (sum + 1) % 2;
                return 'j';
             }
    }
    if (c1 == 'j')
    {
        if (c2 == 'i')
        {
            sum = (sum + 1) % 2;
            return 'k';
        }
        else return 'i';
    }
    if (c2 == 'i')
        return 'j';
    else {
            sum = (sum + 1) % 2;
            return 'i';
         }
}

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i)
    {
        s1.clear();
        cin >> n >> t >> s;
        for (int j = 0; j < t; ++j)
            s1 += s;
        int sum = 0;
        char c = '1';
        bool flag1 = false, flag2 = false;
        for (int j = 0; j < s1.size(); ++j)
        {
            c = check(sum, c, s1[j]);
            if (!flag1 && c == 'i' && sum == 0)
            {
                flag1 = true;
                c = '1';
            }
            if (flag1 && c == 'j' && !flag2 && sum == 0)
            {
                flag2 = true;
                c = '1';
            }
        }
        if (flag1 && flag2 && c == 'k' && sum == 0)
            cout << "Case #" << i + 1 << ": YES" << '\n';
        else cout << "Case #" << i + 1 << ": NO" << '\n';
    }
    return 0;
}
