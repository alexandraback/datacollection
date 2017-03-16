#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#define SIZE 1005
#define EPS 1e-8
#define MX 100000

using namespace std;

int nao[SIZE],ken[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			double d;
			scanf("%lf",&d);
			nao[i]=floor(d*MX+EPS);
		}
		for(int i=0;i<n;i++)
		{
			double d;
			scanf("%lf",&d);
			ken[i]=floor(d*MX+EPS);
		}
		sort(nao,nao+n);
		sort(ken,ken+n);
		int s=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(nao[i]>ken[s])
			{
				cnt++;
				s++;
			}
		}
		//for(int i=0;i<n;i++) printf("%d %d\n",nao[i],ken[i]);
		int cnt2=0;
		s=n-1;
		for(int i=n-1;i>=0;i--)
		{
			if(nao[i]<ken[s]) s--;
			else cnt2++;
		}
		printf("Case #%d: %d %d\n",t,cnt,cnt2);
	}
	return 0;
}
