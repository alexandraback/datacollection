#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define N 200

int n,sum;
int score[N];

void init()
{
	scanf("%d",&n);
	sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
		sum+=score[i];
	}
}

bool OK(int k,double rate)
{
	vector<int> a;
	for(int i=0;i<n;i++) if(i!=k) a.push_back(score[i]);
	sort(a.begin(),a.end());
	int s=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]*i-s>sum*(1-rate))
			return (score[k]+sum*rate)*i>=s+sum*(1-rate);
		s+=a[i];
	}
	return (score[k]+sum*rate)*a.size()>=s+sum*(1-rate);
}

double calc(int k)
{
	double l=0.0,r=100.0;
	while(r-l>1e-9)
	{
		double mid=(l+r)/2;
		if(OK(k,mid)) r=mid;
		else l=mid;
	}
	return l;
}

void work()
{
	for(int i=0;i<n;i++) printf(" %f",calc(i)*100);
	printf("\n");
}

int main()
{
	int t,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:",++cnt);
		init();
		work();
	}
	return 0;
}

