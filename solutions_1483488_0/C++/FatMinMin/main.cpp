#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{   
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int i = a; i <= b; i++)
        {
            int tmp = i, len = 0, dig = 1;
            while(tmp)
            {
                len ++;
                dig *= 10;
                tmp /= 10;
            }
            int base = 10;
            set<int> s;
            while(len--)
            {
                int x = (i % base) * (dig / base) + (i / base);
                if(x > i && x <= b && s.find(x) == s.end())
                {
                    s.insert(x);
                    ans++;
                }
                base *= 10;
            }
        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
