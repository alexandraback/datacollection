#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define int long long
const int MAXN = 10000007;

int hmt[MAXN];
char buff [1000];
bool isPalin()
{
    int n=strlen(buff);
    for(int i=0;i<n;i++)
        if(buff[i]!=buff[n-1-i])
            return false;
    return true;
}
main()
{
    for(int i=1;i<MAXN;i++)
    {
        hmt[i]=hmt[i-1];
        sprintf(buff,"%lld\0",i);
        if(isPalin())
        {
            sprintf(buff,"%lld\0",i*i);
            if(isPalin())
                hmt[i]++;
        }
    }
    int z;
    scanf("%lld",&z);
    for(int zz=1;zz<=z;zz++)
    {
        int a,b;
        scanf("%lld %lld",&a,&b);
        a = ceil(sqrt((double)a));
        b= floor(sqrt((double)b));
        printf("Case #%lld: %lld\n",zz,hmt[b]-(a>0 ? hmt[a-1] :0));
    }
}
