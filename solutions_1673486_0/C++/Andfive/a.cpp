#include<cstdio>
using namespace std;
double m[100005];
int main ()
{
    freopen("A-small-attempt0.in","r",stdin);
	freopen("sun.out","w",stdout);
	int nn,a,b;
	double ans,tmp,tmp2;
	scanf("%d",&nn);
	for(int i=1;i<=nn;++i)
	{
	    scanf("%d%d",&a,&b);
	    for(int j=1;j<=a;++j)
	        scanf("%lf",&m[j]);
        printf("Case #%d: ",i);
        ans=b+2;
        tmp=1;
        for(int j=1;j<=a;++j)
            tmp*=m[j];
        tmp2=tmp*(b-a+1)+(1-tmp)*(2*b-a+2);
        if(tmp2<ans)
            ans=tmp2;
        for(int j=1;j<=a;++j)
        {
            if(j==1)
                tmp=1;
            else
                tmp=tmp*m[j-1];
            tmp2=tmp*(a-j+1+b-j+2)+(1-tmp)*(a-j+1+2*b-j+3);
            if(tmp2<ans)
                ans=tmp2;
        }
        printf("%.6lf\n",ans);
	}
    return 0;
}
