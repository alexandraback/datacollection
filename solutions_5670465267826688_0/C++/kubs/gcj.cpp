#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compute(char a, char b, bool &m)
{
    if (a == '1')
        return b;
    else if (b == '1')
        return a;
    else if (a == b)
    {
        m = !m;
        return '1';
    }
    else if (a == 'i')
    {
        if (b == 'j')
            return 'k';
        else
        {
            m = !m;
            return 'j';
        }
    }
    else if (a == 'j')
    {
        if (b == 'k')
            return 'i';
        else
        {
            m = !m;
            return 'k';
        }
    }
    else if (a == 'k')
    {
        if (b == 'i')
            return 'j';
        else
        {
            m = !m;
            return 'i';
        }
    }
    return 'e';
}


int solve()
{
    int l;
    int x;
    string s;
    cin >> l;
    cin >> x;
    cin >> s;
    char q = '1';
    bool I = false;
    bool m = false;
    for (int i = 0; i < l; i++)
    {
        q = compute(q, s[i], m);
    }
    if (q == '1')
    {
        if (!m || (x % 2 == 0))
            return 0;
    }

    else if (x % 4 != 2)
        return 0;
    int i = 0;
    while(true)
    {
        q = compute(q, s[i], m);
        if (!I && q == 'i' && !m)
        {
            q = '1';
            I = true;
        }
        else if(I && q == 'j' && !m)
            return 1;
        i++;
        if (i == l)
        {
            if (x > 0)
            {
                x--;
                i = 0;
            }
            else
                return 0;
        }
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s = solve();
        if (s)
            cout << "Case #" << i << ": " << "YES" << endl;
        else
            cout << "Case #" << i << ": " << "NO" << endl;
    }
    return 0;
}
