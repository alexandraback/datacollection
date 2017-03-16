#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int a[33],ans[12];

int main()
{
	srand(time(0));
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;scanf("%d",&test);
	for (int T=1;T<=test;T++)
	{
		printf("Case #%d:\n",T);
		int n,K;scanf("%d%d",&n,&K);
		a[0]=a[n-1]=1;
		while (K)
		{
			for (int i=1;i<n-1;i++) a[i]=rand()%2;
			bool ok=1;
			for (int i=2;i<11;i++)
			{
				ans[i]=0;
				for (int j=0;j<25;j++)
				{
					int t=0;
					for (int k=0;k<n;k++) t=(t*i+a[k])%prime[j];
					if (!t) {ans[i]=prime[j];break;}
				}
				if (!ans[i]) {ok=0;break;}
			}
			if (ok)
			{
				for (int i=0;i<n;i++) putchar(a[i]+48);
				for (int i=2;i<11;i++) printf(" %d",ans[i]);
				puts("");K--;
			}
		}
	}
	return 0;
}

