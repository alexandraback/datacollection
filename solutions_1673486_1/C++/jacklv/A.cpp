#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
double p[maxn],ans;
int a,b;
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tttt=1; tttt<=T; tttt++)
    {
        scanf("%d%d",&a,&b); p[0]=1;
        ans=2+b;
        for (int i=1; i<=a; i++)
        {
            double pp;
            scanf("%lf",&pp);
            p[i]=p[i-1]*pp;
        }
        double tt;
        for (int i=0; i<=a; i++)
        {
            double ttt=0;
            //for (int j=0; j<=i; j++)
            ttt=p[a-i];
            tt=ttt*(b-a+i*2+1)+(1-ttt)*(b-a+i*2+1+b+1);
            //cout<<ttt<<endl;
            if (tt<ans) ans=tt;
        }
        printf("Case #%d: %.6lf\n",tttt,ans);
    }
}
