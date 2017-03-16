#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=8000;
int sum[N+10];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	fo(cas,1,T)
	{
		memset(sum,0,sizeof sum);
		int n;
		scanf("%d",&n);
		fo(i,1,2*n-1)
		{
			fo(j,1,n)
			{
				int x;
				scanf("%d",&x);
				sum[x]++;
			}
		}
		printf("Case #%d:",cas);
		fo(i,1,N)
		if (sum[i]%2) printf(" %d",i);
		printf("\n");
	}
} 
