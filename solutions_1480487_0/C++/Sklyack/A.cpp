#include <cstdio>
#include <cstring>

const int MAXN=200;
int S[MAXN];
double ans[MAXN];
bool found[MAXN];
int main()
{
	int t, T, n0, n, n1, i, X0, X;
	bool exz;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d", &n0);
		for(X0=i=0; i<n0; ++i)
		{
			scanf("%d", S+i);
			X0+=S[i];
		}
		memset(found, 0, sizeof(found));
		n1=n=n0;
		X=X0;
		do
		{
			n=n1;
			for(i=0; i<n; ++i)
				if(!found[i] && S[i]*n>=X0+X)
				{
					ans[i]=0.0;
					found[i]=1;
					--n1;
					X-=S[i];
				}
		}while(n1!=n);
		for(i=0; i<n0; ++i)
			if(!found[i])
				ans[i]=100*(((double)(X0+X))/(n*X0)-((double)S[i])/X0);
		printf("Case #%d:", t);
		for(i=0; i<n0; ++i)
			printf(" %.7lf", ans[i]);
		printf("\n");
	}
	return 0;
}
