#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
double p[205],ans[205],pp[205];
bool bo[205];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,tt=0,num,n,i;
    double sum,ssum,tmp;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        scanf("%d",&n);
        sum=0;
        memset(bo,0,sizeof(bo));
        for(i=0;i<n;i++)
        {
            scanf("%lf",p+i);
            sum+=p[i];
        }
        ssum=sum;
        num=n;
        printf("Case #%d:",tt);
        for(i=0;i<n;i++)
            pp[i]=p[i]/sum;
        //for(i=0;i<n;i++)cout<<pp[i]<<endl;
        tmp=2.0/n;
        for(i=0;i<n;i++)
            if(tmp<=pp[i])
            {
                ans[i]=0;
                bo[i]=1;
                num--;
                ssum-=p[i];
                //cout<<ssum<<' '<<tmp<<' '<<pp[i]<<endl;
            }
        tmp=(sum+ssum)/num;
        //cout<<tmp<<endl;
        for(i=0;i<n;i++)
            if(!bo[i])
                ans[i]=(tmp-p[i])/sum;
        for(i=0;i<n;i++)
            printf(" %.6lf",ans[i]*100.0);
        puts("");
    }
	return 0;
}
