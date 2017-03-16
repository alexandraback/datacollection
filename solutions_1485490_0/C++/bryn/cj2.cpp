#include <cstdio>
#define maxn 110
#define maxm 110
#define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#define min(a,b) ( ((a) < (b)) ? (a) : (b) )

long t[maxn][maxm];
long N_count[maxn];
long N_type[maxn];
long M_count[maxm];
long M_type[maxm];

void solve(long cnr)
{
	long n,m;
	for(long i = 0; i < maxn; i++)
	{
		for(long j = 0; j < maxm; j++)
		{
			t[i][j] = 0;
		}
	}
	scanf("%ld%ld",&n,&m);
	for(long i = 0; i < n; i++) scanf("%ld%ld",&N_count[i],&N_type[i]);
	for(long i = 0; i < m; i++) scanf("%ld%ld",&M_count[i],&M_type[i]);
	for(long i = n-1; i >= 0; i--)
	{
		for(long j = m-1; j >= 0; j--)
		{
			long c = 0;
			long I = i;
			long J = j;
			long NC = N_count[i];
			long MC = M_count[j];
			long prev = 0;
			while((NC > 0 || MC > 0) && I < n && J < m && N_type[I] == M_type[J])
			{
				long curr = min(NC, MC);
				NC -= curr;
				MC -= curr;
				prev += curr;
				c = max(c, prev+t[I+1][J+1]);
				if(NC == 0)
				{
					do { I++; } while(I < n && N_type[I] != M_type[J]);
					if(I >= n) break;
					else NC += N_count[I];
				}
				else // (MC == 0)
				{
					do { J++; } while(J < m && M_type[J] != N_type[I]);
					if(J >= m) break;
					else MC += M_count[J];
				}
			}
			c = max(c, t[i][j+1]);
			c = max(c, t[i+1][j]);
			
			t[i][j] = c;
		}
	}
	printf("Case #%ld: %ld\n", cnr, t[0][0]);
}

int main()
{
	long z;
	scanf("%ld",&z);
	for(long i = 0; i < z; i++) solve(i+1);
	return 0;
}