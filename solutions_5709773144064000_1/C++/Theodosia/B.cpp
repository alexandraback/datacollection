#include <cstdio>
#include <cstring>

double c,f,x;
int test;
double ans,tmp;
int k;
double hd;
double F[1000005];

double make(int k)
{
	double a = F[k - 1];
	double nf = 2 + f * (k - 1);
	for (int i = k - 1; i < k; i++)
	{
		a += c / nf;
		nf += f;
	}
	F[k] = a;
	return a + x / nf;
}

int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		k = 0;
		ans = x / 2.0;
		F[0] = 0;
		while ((tmp = make(k + 1)) < ans)
		{
			//printf("%d %.7lf\n",k,ans);
			k++;
			ans = tmp;
		}
		printf("Case #%d: %.7lf\n",T,ans);
	}
}
