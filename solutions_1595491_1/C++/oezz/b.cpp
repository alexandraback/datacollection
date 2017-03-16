#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 200

using namespace std;

void init()
{
    int cas, n, s, p, a[MAXN];
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &cas);
    for (int T=1; T<=cas; ++T)
    {
        scanf("%d%d%d", &n, &s, &p);
        for (int i=0; i<n; ++i) scanf("%d", a+i);
        sort(a, a+n);
        int ans=0;
        for (int i=n-1; i>=0; --i)
        {
            int x=a[i]/3+(a[i]%3>0);
            if (x<p)
            {
                if(!s) break;
                --s;
                if ((3*p-4<=a[i]) && (3*p-4>=0)) ++ans;
            }
            else ++ans;
        }
        printf("Case #%d: %d\n", T, ans);
    }
    fclose(stdin);
    fclose(stdout);
}

int main()
{
    init();
    return 0;
}
