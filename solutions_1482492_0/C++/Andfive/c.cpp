#include<cstdio>
#include<math.h>
using namespace std;

#define npsdgfs 2010
#define mpdddd 1e-8
double mpsdd[npsdgfs];
double mpsmfwe[npsdgfs],mpeedcfvh;
int main()
{
	int i,j,mpvrgec;
	double D,cp,v;
	double nmpde,dnpger,p;
	int N,A,casenum=0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("df.out","w",stdout);
	scanf("%d",&mpvrgec);
	while(mpvrgec--)
	{
		scanf("%lf%d%d",&D,&N,&A);


for(i=0;i<N;i++)

			scanf("%lf%lf",&mpsdd[i],&mpsmfwe[i]);
		printf("Case #%d:\n",++casenum);
		for(i=0;i<A;i++)
		{
			scanf("%lf",&mpeedcfvh);
if(mpsmfwe[0]>D)
{
				nmpde=sqrt(2.0*D/mpeedcfvh);
				printf("%lf\n",nmpde);
			}
			else
			{
				v=(double)((mpsmfwe[1]-mpsmfwe[0])/(mpsdd[1]-mpsdd[0]));
				dnpger=(D-mpsmfwe[0])/v;
				nmpde=sqrt(2.0*D/mpeedcfvh);
				if(nmpde>dnpger)
					printf("%lf\n",nmpde);
else
					printf("%lf\n",dnpger);}
		}
	}
	return 0;
}
