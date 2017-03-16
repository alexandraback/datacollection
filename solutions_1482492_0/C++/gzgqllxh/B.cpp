#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 2010
#define eps 1e-8
double ti[maxn],xi[maxn],aai;
int main()
{
	int i,j,tcase,N,A,casenum=0;
	double D,cp,v,ans,tempt,p;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&tcase);
	while(tcase--)
	{
		scanf("%lf%d%d",&D,&N,&A);
		for(i=0;i<N;i++)
			scanf("%lf%lf",&ti[i],&xi[i]);
		printf("Case #%d:\n",++casenum);
		for(i=0;i<A;i++)
		{
			scanf("%lf",&aai);
			if(xi[0]>D)
			{
				ans=sqrt(2.0*D/aai);
				printf("%lf\n",ans);
			}
			else
			{		
				v=(double)((xi[1]-xi[0])/(ti[1]-ti[0]));					
				tempt=(D-xi[0])/v;
				ans=sqrt(2.0*D/aai);
				if(ans>tempt)
					printf("%lf\n",ans);
				else
					printf("%lf\n",tempt);
			}
		}
	}
	return 0;
}
