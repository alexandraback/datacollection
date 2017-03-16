#include<iostream>

using namespace std;

double p[1000], ans[1000];

int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);

	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		int n;
		cin>>n;
		double sum = 0;
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
			sum+=p[i];
		}

		for(int i=0;i<n;i++)
			p[i]/=sum;

		for(int i=0;i<n;i++)
		{
			double l = 0.0, r = 1.0, mid, all;
			while(r-l>1e-9)
			{
				mid = (r+l)/2;
				all = p[i] + mid;
				double rem = 1.0 - mid;
				bool enough = true;
				for(int k=0;k<n;k++)
				{
					if (k==i) continue;
					if (p[k]<all)
					{
						rem-=all-p[k];
						if (rem<0)
						{
							enough = false;
							break;
						}
					}
				}
				if (enough) l = mid; else r = mid;
			}
			ans[i] = mid;
		}

		printf("Case #%d:",tt);
		for(int i=0;i<n;i++)
			printf(" %.6f", ans[i]*100.0);
		printf("\n");
	}
	return 0;
}