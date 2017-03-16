#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int multiply(int first , int last)
{
    int sign = 1;
    if(first * last < 0)
        sign = -1;

    first = abs(first);
    last = abs(last);

    if(first == 1)
        return last * sign;

    if(last == 1)
        return first * sign;

    if(first == last)
        return -1 * sign;

    if(first == 2)
    {
        if(last == 3)
            return 4 * sign;

        if(last == 4)
            return -3 * sign;
    }
    if(first == 3)
    {
        if(last == 2)
            return -4 * sign;

        if(last == 4)
            return 2 * sign;
    }

    if(first == 4)
    {
        if(last == 2)
            return 3 * sign;

        if(last == 3)
            return -2 * sign;
    }
    cout << "uasldaskldjaksldjkasldjklasjdklasjdlkasjdlkasjdlkasjdlaksjdwoijoiejwd";
    return -1;
}

int main()
{
    freopen("C-small-attempt1.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T , c = 0;
    cin >> T;
    while(T--)
    {
        ++c;
        long long L , X;
        cin >> L >> X;

        string s , ss;
        cin >> s;

        for(int i = 0;i < X;++i)
            ss += s;

        bool ok = false;
        if(ss.size())
        {
            bool flag1 = false;
            bool flag2 = false;

            int mul = 1;
            for(int i = 0;i < ss.size();++i)
            {
                mul = multiply(mul , ss[i] - 'i' + 2);

                if(mul == 2 && !flag1)
                {
                    flag1 = true;
                    mul = 1;
                }

                if(mul == 3 && flag1 && !flag2)
                {
                    flag2 = true;
                    mul = 1;
                }
            }
            if(mul == 4 && flag1 && flag2)
            {
                ok = true;
            }
        }
        if(!ok)
            cout << "Case #" << c << ": NO\n";

        else
            cout << "Case #" << c << ": YES\n";
    }
    return 0;
}
