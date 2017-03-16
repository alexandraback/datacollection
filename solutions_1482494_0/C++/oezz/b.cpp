#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 1010

using namespace std;

int n, mk[MAXN];

struct node
{
    int a, b;
    void rd(){scanf("%d%d", &a, &b);}
    bool operator < (const node &x) const{
        return a<x.a||a==x.a&&b>x.b;
    }
} s[MAXN];

void init()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i) s[i].rd();
    sort(s, s+n);
    memset(mk, 0, sizeof(mk));
    int cnt=0, ans=0;
    for (int i=0; i<n*2; ++i)
    {
        int maxt=0, u=-1, rk;
        for (int j=0; j<n; ++j)
            if (mk[j]<2)
            {
                if (cnt>=s[j].b)
                {
                    if (maxt<2-mk[j]) maxt=2-mk[j], rk=2, u=j;
                }
                else if (mk[j]<1 && cnt>=s[j].a)
                {
                    if (maxt<1) maxt=1, rk=1, u=j;
                }
            }
        if (u==-1) break;
        mk[u]=rk;
        cnt+=maxt;
        ++ans;
    }
    if (cnt < n*2) puts("Too Bad");
    else printf("%d\n", ans);
}

int main()
{
    int T;
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i)
    {
        printf("Case #%d: ", i);
        init();
    }
    return 0;
}
