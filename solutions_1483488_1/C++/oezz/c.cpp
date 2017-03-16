#include <cstdio>
#include <cstring>

#define LL long long

using  namespace std;

int a, b, d[7]={1,10,100,1000,10000,100000,1000000};
bool mk[2000010];

int calc(int x, int l)
{
    int ret=1;
    mk[x]=1;
    for (int i=1; i<l; ++i)
    {
        int y=x%d[i]*d[l-i]+x/d[i];
        if(y>=a && y<=b&&!mk[y])
        {
            ++ret;
            mk[y]=1;
        }
    }
    return ret*(ret-1)/2;
}

int main()
{
    int cas;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &cas);
    for (int T=1; T<=cas; ++T)
    {
        memset(mk, 0, sizeof(mk));
        scanf("%d%d", &a, &b);
        int x=a, l=0, ans=0;
        while (x) x/=10,++l;
        for (int i=a; i<=b; ++i)
            if(!mk[i]) ans += calc(i,l);
        printf("Case #%d: %d\n", T, ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
