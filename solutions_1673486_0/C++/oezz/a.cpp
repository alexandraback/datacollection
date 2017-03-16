#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100000

using namespace std;

double p[MAXN];

void init()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i=0; i<a; ++i) scanf("%lf", p+i);
    double ans=b+1;
    for (int i=0; i<a; ++i) ans*=p[i];
    ans=min(2*b-a+2-ans, b+2.0);
    double cur=p[0];
    for (int i=0; i<a; ++i)
    {
        ans=min(ans, b-a+2*(a-i-1)+1+(1-cur)*(b+1));
        if (i<a-1) cur *=p[i+1];
    }
    printf("%.7f\n", ans);
}

int main()
{
    int T;
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i)
    {
        printf("Case #%d: ", i);
        init();
    }
    return 0;
}
