#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double p[100000];
double s[100000];
int a,b;
int main()
{
    freopen("C:\\Users\\James\\Desktop\\in.txt","r",stdin);freopen("C:\\Users\\James\\Desktop\\out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        for(int i=1;i<=a;i++)
        scanf("%lf",&p[i]);
        double ans=b+2;
        s[0]=1;
        for(int i=1;i<=a;i++)
        s[i]=s[i-1]*p[i];
        ans=min(ans,s[a]*(b-a+1)+(1-s[a])*(b-a+1+b+1));
        for(int i=1;i<=a;i++)
        {
            ans=min(ans,s[a-i]*(i+b-a+i+1)+(1-s[a-i])*(i+b-a+i+1+b+1));
        }
        printf("Case #%d: %.10f\n",++cas,ans);
    }
}
