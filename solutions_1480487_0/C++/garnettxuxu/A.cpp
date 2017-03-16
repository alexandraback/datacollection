
#include <stdio.h>

const int maxn = 210;
const double eps = 1e-9;
double p[maxn];
double sum;
int n;

double max(double a,double b)
{
	return a>b?a:b;
}
double f(double a)
{
	return a<0?0:a;
}

double ans[maxn];
double cpt;

bool f(int id, double s)
{
    int i;
	double cur = 0;
	for(i=0;i<n;i++)
	{
		if(i==id) continue;
		double need;
		if(p[i]>=cpt) need = 0;
		else 
			need = (cpt-p[i]) / sum;
		cur += need;
		if(cur > s)
			return false;
	}
	return true;
}

bool ok(int id,double s)
{
    s = 1 - s;
	return !f(id,s);
}

double getans(int k)
{
	double low=0,high=1,mid;
	while(high-low>eps)
	{
		mid = (low + high) / 2;
		 cpt = p[k] + sum * mid;
         if(ok(k,mid))
			 high = mid;
		 else 
			 low = mid;
	}
	return (low+high)/2;
}

void solve()
{
	 
 	 int i,j;
	 
	 sum = 0;
	 for(i=0;i<n;i++) sum += p[i];

	 for(i=0;i<n;i++)
         ans[i] = getans(i);
	 
	 for(i=0;i<n-1;i++)
		 printf("%.5lf ",100*ans[i]);
	 printf("%.5lf\n",100*ans[i]);
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.txt","w",stdout);
	int ct,caset = 1;
	scanf("%d",&ct);
	while(ct--)
	{
		printf("Case #%d: ",caset++);
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
        scanf("%lf",&p[i]);
		solve();
	}
	return 0;
}