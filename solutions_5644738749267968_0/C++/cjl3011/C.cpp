#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int main(int argc,char *argv[])
{
    
    freopen("D-small-attempt1.in","r",stdin);
    freopen("D.out","w",stdout);
    int t,n;
    double a[1010],b[1010],v1[1010],v2[1010];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lf",&b[i]);
        printf("Case #%d: ",cas);
        int sum1=0,sum2=0;
        if(n==1&&a[1]<b[1]) printf("0 0\n");
        else if(n==1&&a[1]>b[1]) printf("1 1\n");
        else {
            sort(a+1,a+n+1);
            sort(b+1,b+n+1);
            //for(int i=1;i<=n;i++) printf("%lf ",a[i]);printf("\n");
            //for(int i=1;i<=n;i++) printf("%lf ",b[i]);printf("\n");
            memset(v1,0,sizeof(v1));
            memset(v2,0,sizeof(v2));
            for(int i=1;i<=n;i++)
            {
                if(a[i]>b[n]) sum2++;
                else
                {
                    int j;
                    for(j=1;j<=n;j++)
                    {
                        if(b[j]>a[i]&&!v2[j]&&!v1[i])
                        {
                            v2[j]=1;v1[i]=1;break;
                        }
                    }
                    if(j==n+1)
                        sum2++;
                }
            }
            memset(v1,0,sizeof(v1));
            memset(v2,0,sizeof(v2));
            int j=1,k=n;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<b[j])
                {
                    v1[i]=1;v2[k]=1;k--;
                }
                else
                {
                    v1[i]=1;v2[j]=1;j++;
                    sum1++;
                }
            }
            printf("%d %d\n",sum1,sum2);
        }
    }
    return 0;
}

