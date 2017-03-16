#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull pow(ull a, ull b)
{
    if (b == 0)
        return 1;
    return a * pow(a,b-1);
}

ull find(ull k, ull c, ull i)
{
    if (c == 1)
        return i;
    return (i-1) * pow(k,c-1) + find(k,c-1,i);
}

int main()
{
    int t;
    cin >> t;
    for (int x = 1; x <= t; ++x)
    {
        ull k, c, s;
        cin >> k >> c >> s;
        if (k == s)
        {
            cout << "Case #" << x << ":";
            for (int i = 1; i <= k; ++i)
                cout << " " << find(k,c, i);
            cout << endl;
        }
    }
}
