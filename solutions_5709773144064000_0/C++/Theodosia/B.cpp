#include <cstdio>
#include <cstring>

double c,f,x;
int test;
double ans,tmp;
int k;
double hd;

double make(int k)
{
	double a = 0;
	double nf = 2;
	for (int i = 0; i < k; i++)
	{
		a += c / nf;
		nf += f;
	}
	return a + x / nf;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		k = 0;
		ans = x / 2.0;
		while ((tmp = make(k + 1)) < ans)
		{
			k++;
			ans = tmp;
		}
		printf("Case #%d: %.7lf\n",T,ans);
	}
}
