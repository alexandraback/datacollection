#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char s[100];
    bool flag;
    int m=0;
    long long ans[40];
    for(long long x=1;x<=10000000;x++)
    {
        flag=0;
        sprintf(s,"%I64d",x);
        for(int i=strlen(s)-1,j=0;i>j;i--,j++)
            if(s[i]!=s[j])flag=1;
        if(flag)continue;
        sprintf(s,"%I64d",x*x);
        for(int i=strlen(s)-1,j=0;i>j;i--,j++)
            if(s[i]!=s[j])flag=1;
        if(flag)continue;
        ans[m++]=x*x;
    }
    int t,sum;
    long long a,b;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%I64d%I64d",&a,&b);
        sum=0;
        for(int i=0;i<m;i++)
            if(a<=ans[i] && ans[i]<=b)sum++;
        printf("Case #%d: %d\n",cas,sum);
    }
    return 0;
}
