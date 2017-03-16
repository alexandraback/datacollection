#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1000005];
long long rev(long long x)
{
    long long t=0;
    if (x%10==0)
        return x-1;
    while (x>0)
    {
        t=t*10;
        t=t+x%10;
        x=x/10;
    }
    return t;
}
int main(void)
{
    int ca,cases;
    int n;
    int i;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("As1.txt","w",stdout);
    memset(f,0x3f,sizeof(f));
    f[1]=1;
    for (i=2;i<=1000000;i++)
        f[i]=min(f[i-1],f[rev(i)])+1;
    scanf("%d",&cases);
    for (ca=1;ca<=cases;ca++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",ca,f[n]);

    }
    return 0;
}
