#include <iostream>

using namespace std;

int t, n, s, p;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {   
        cin >> n >> s >> p;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            int x = tmp / 3;
            if(tmp % 3 == 0)
            {
                if(x >= p)
                    ans++;
                else if(x !=0 && x + 1 >= p && s > 0)
                {
                    ans++;
                    s--;
                }
            }
            else if(tmp % 3 == 1)
            {
                if(x + 1 >= p)
                    ans++;
            }
            else if(tmp % 3 == 2)
            {
                if(x + 1 >= p)
                    ans++;
                else if(x + 2 >= p && s > 0)
                {
                    ans++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}

