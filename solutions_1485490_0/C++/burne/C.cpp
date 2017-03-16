#include<stdio.h>
#include<string.h>
#define MAXD 110
int N, M;
__int64 a[MAXD], b[MAXD], f[MAXD][MAXD], t[MAXD];
int A[MAXD], B[MAXD];
void init()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; i ++)
		scanf("%I64d%d", &a[i], &A[i]);
	for(i = 1; i <= M; i ++)
		scanf("%I64d%d", &b[i], &B[i]);	
}
void solve()
{
	int i, j, k, l;
	__int64 ans, temp;
	memset(f, 0, sizeof(f));
	for(i = 1; i <= N; i ++)
		for(j = 1; j <= M; j ++)
		{
			f[i][j] = f[i - 1][j];
			ans = 0;
			for(k = j; k >= 1; k --)
			{
				if(B[k] == A[i])
					ans += b[k];
				t[k] = ans;
			}
			ans = 0;
			for(l = i; l >= 1; l --)
			{
				if(A[l] == A[i])
					ans += a[l];
				for(k = j; k >= 1; k --)
				{
					temp = f[l - 1][k - 1] + (ans < t[k] ? ans : t[k]);
					if(temp > f[i][j])
						f[i][j] = temp;
				}
			}
		}
	printf("%I64d\n", f[N][M]);
}
int main()
{
	int t, tt;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d", &t);
	for(tt = 0; tt < t; tt ++)
	{
		init();
		printf("Case #%d: ", tt + 1);
		solve();	
	}
	return 0;	
}
