#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
   // freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    int t, k = 0;
    scanf("%d",&t);
    while(t--)
    {
        int n, s, p;
        int mod[200];
        int ans = 0;
        int mcnt = 0;
        scanf("%d%d%d",&n, &s, &p);
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp == 1 || tmp == 0)
            {
                if(tmp >= p) ans++;
                continue;
            }
            if(tmp % 3 == 0)
            {
                int x = tmp / 3;
                if(x >= p) {ans++; continue;}
                if( x + 1 <= 10 && x + 1 >= p)
                    mod[mcnt++] = x + 1;
            }
            else if(tmp % 3 == 1)
            {
                int x = tmp / 3 + 1;
                if(x >= p)
                       ans++;
                //if(x >= p)
                 //   mod[mcnt++] = x;
            }
            else
            {
                int x = tmp / 3 + 1;
                if(x >= p) {ans++; continue;}
                if( x + 1 <= 10 && x + 1 >= p)
                    mod[mcnt++] = x + 1;
            }
        }
        if(mcnt != 0) sort(mod, mod + mcnt);
        if(mcnt != 0 && mcnt <= s) ans += mcnt;
        if(mcnt > s)
        {
            ans += s;
            for(int i = s; i < mcnt; ++i)
            {
                if(mod[i] - 1 >= p) ans++;
            }
        }
        printf("Case #%d: %d\n",++k,ans);
    }
    return 0;
}
