#include <cstdio>
#include <algorithm>

#define eps 0.0001

using namespace std;
int N;
double t1,t2,d1,d2;

int Solve()
{
    scanf("%d",&N);
    long long a,b,c;
    if(N == 1)
        return 0;
    scanf("%lld%lld%lld",&a,&b,&c);
    t1 = c;
    d1 = a;

    scanf("%lld%lld%lld",&a,&b,&c);
    t2 = c;
    d2 = a;

    if(d1 > d2)
    {
        swap(t1,t2);
        swap(d1,d2);
    }

    t1 = t1 * (360.0-d1*1.0)/360.0;
    t2 = t2*(360 + 360 - d2*1.0)/360.0;
    if(t1 + eps < t2)
        return 0;
    return 1;

}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    int tst;
    scanf("%d",&tst);
    for(int i = 1; i <= tst; ++i)
    {

        printf("Case #%d: %d\n",i,Solve());
    }

    return 0;
}
