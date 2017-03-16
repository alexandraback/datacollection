#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define maxn 100005


int main()
{
    int t,a,b,i,j,cas=0;
    double p[maxn],p1,p2,ans;

    freopen("A-large.in","r",stdin);
	freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        p1=1;
        for(i=0;i<a;i++)
        {
            scanf("%lf",&p2);
            p1*=p2;
            p[i]=1-p1;
        }
        //cout<<"1"<<endl;
        ans=b+2;
        for(i=0;i<a;i++)
        {
            p1=(i*2+b-a+1)*(1-p[a-i-1])+(i*2+2*b-a+2)*p[a-i-1];
            if (p1<ans) ans=p1;
        }
        printf("Case #%d: %.6lf\n",++cas,ans);
    }
    return 0;
}
