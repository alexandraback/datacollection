#include <cstdio>
#define eps 1e-9
int T,cas,K,L,S,i,j,k,t,k1,j1,mx,nx[111],tag,flg,has[260];
double qw,f[105][105][105];
char kb[111],a[111];

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	for (cas=1; cas<=T; ++cas)
	{
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", kb+1);
		scanf("%s", a+1);
		
		++tag;
		flg = 0;
		for (i=1; i<=K; ++i) has[kb[i]] = tag;
		for (i=1; i<=L; ++i)
		if (has[a[i]] != tag) flg = 1;
		if (flg)
		{
			printf("Case #%d: 0.0\n", cas);
			continue;
		}
		
		nx[1] = 0;
		for (i=2; i<=L; ++i)
		{
			for (j=nx[i-1]; j>0 && a[j+1]!=a[i]; j=nx[j]);
			nx[i] = j+(a[j+1]==a[i]);
		}
		mx = (S-L)/(L-nx[L])+1;
		
		for (i=0; i<=S; ++i)
		for (j=0; j<L; ++j)
		for (k=0; k<=mx; ++k) f[i][j][k] = 0;
		f[0][0][0] = 1;
		for (i=0; i<S; ++i)
		for (j=0; j<L; ++j)
		for (k=0; k<=mx; ++k)
		if (f[i][j][k] > eps)
		{
			for (t=1; t<=K; ++t)
			{
				for (j1=j; a[j1+1]!=kb[t] && j1!=0; j1=nx[j1]);
				if (a[j1+1] == kb[t]) ++j1;
				if (j1 == L)
				{
					k1 = k+1;
					j1 = nx[L];
				}
				else k1 = k;
				f[i+1][j1][k1] += f[i][j][k]/K;
			}
		}
		qw = 0;
		for (j=0; j<L; ++j)
		for (k=1; k<=mx; ++k) qw += f[S][j][k]*k;
		printf("Case #%d: %.7lf\n", cas, mx-qw+eps);
	}
	return 0;
}
