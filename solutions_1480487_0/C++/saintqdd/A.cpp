#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int dt[210];
double ans[210],tmp[210];
#define inf 0.00000001
int main()
{
	freopen("A-small-attempt4.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas = 1;
	int T,N,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		sum = 0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",dt+i);
			sum += dt[i];
		}
		memset(ans,0,sizeof(ans));
		for(int i=0;i<N;i++)
		{
			double l = 0,r = 1.0;
			while(r-l>0.000000001)
			{
				double mid = (l+r)/2;
				double va = dt[i]+sum*mid;
				double va2 = 0;
				vector<int> tp;
				for(int j=0;j<N;j++)
				{
					if(j!=i) tp.push_back(dt[j]);
				}
				sort(tp.begin(),tp.end());
				double tsum = 0;
				for(int j=0;j<N-1;j++)
				{
					tsum += tp[j];
					double cura = (tsum+sum*(1-mid))/(j+1);
					va2 = cura;
					if(j+1<N-1)
					{
						if( cura<=tp[j+1]+0.0 ) break;
					}
					
				}

				if(va>=va2 || abs(va-va2)<0.000001 )
				{
					ans[i] = mid;
					r = mid;
				}
				else
				{
					l = mid;
				}
			}
		}
		//printf("2\n");
		printf("Case #%d: ",cas++);
		for(int i=0;i<N;i++)
		{
			printf("%.6f ",ans[i]*100);
		}
		printf("\n");
	}
	return 0;
}