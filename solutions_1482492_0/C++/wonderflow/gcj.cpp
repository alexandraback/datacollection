#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define Node 2010
#define eps 1e-8
double rec[Node],mzc[Node],dub;
	int i,j,T,n,ast,icas=0;
	double dd,cp,v,ans,tempt,p;
int main()
{

	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%d%d",&dd,&n,&ast);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&rec[i],&mzc[i]);
		printf("Case #%d:\n",++icas);
		for(i=0;i<ast;i++)
		{
			scanf("%lf",&dub);
			if(mzc[0]>dd)
			{
				ans=sqrt(2.0*dd/dub);
				printf("%lf\n",ans);
			}
			else
			{		
				v=(double)((mzc[1]-mzc[0])/(rec[1]-rec[0]));					
				tempt=(dd-mzc[0])/v;
				ans=sqrt(2.0*dd/dub);
				if(ans>tempt)
					printf("%lf\n",ans);
				else
					printf("%lf\n",tempt);
			}
		}
	}
	return 0;
}

