#include <cstdio>

const int MAXN=500;

int N,sum;
int score[MAXN];

bool check(int nowi,double mid,double now)
{
	double left=1-mid;
	for(int i=0;i<N;i++)
		if (i!=nowi && score[i]<now)
		{
			double need=(now-score[i])/double(sum);
			if (need>left)
				return true;
			else
				left-=need;
		}
	return false;
}

void solve()
{
	scanf("%d",&N);
	sum=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&score[i]);
		sum+=score[i];
	}
	for(int i=0;i<N;i++)
	{
		double l=0,r=1;
		while(r-l>1e-10)
		{
			double mid=(l+r)/2;
			if (check(i,mid,score[i]+mid*sum))
				r=mid;
			else
				l=mid;
		}
		printf(" %lf",r*100);
	}
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d:",i);
		solve();
		printf("\n");
	}
	return 0;
}