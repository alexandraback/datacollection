#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<long long> fs;
void fu()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    int x,y;
    x=lower_bound(fs.begin(),fs.end(),a)-fs.begin();
    y=upper_bound(fs.begin(),fs.end(),b)-fs.begin();
    printf("%d\n",(y-x));
}
bool pal(long long x)
{
    char s[100];
    sprintf(s,"%lld",x);
    int len=strlen(s);
    for(int i=0;i<=len/2;i++)
    {
        if(s[len-i-1]!=s[i])
            return 0;
    }
    return 1;
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("bo.out","w",stdout);
    for(long long i=1;i<10000010;i++)
        if(pal(i)&&pal(i*i))
            fs.push_back(i*i);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        fu();
    }
}
