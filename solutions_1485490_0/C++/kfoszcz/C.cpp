#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int MAXM = 101;

struct field
{
	long long value, takenA, takenB;
	int which;
	
	field(){}
	
	field(long long v, long long tA, long long tB, int w)
	{
		value = v;
		takenA = tA;
		takenB = tB;
		which = w;
	}
};

struct thing
{
	long long int amount; 
	int type;
	
	thing(){}
	
	thing(long long int a, int t)
	{
		amount = a;
		type = t;
	}
};

field tab[MAXN][MAXM];

thing A[MAXN];
thing B[MAXM];

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld%d", &A[i].amount, &A[i].type);
		for (int i = 1; i <= m; i++)
			scanf("%lld%d", &B[i].amount, &B[i].type);
			
		for (int i = 0; i <= n; i++)
			tab[i][0] = field(0, 0, 0, 0);
		for (int j = 0; j <= m; j++)
			tab[0][j] = field(0, 0, 0, 0);
			
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (A[i].type != B[j].type)
				{
					//printf("!!! %d %d\n", i, j);
					if (tab[i][j-1].value > tab[i-1][j].value)
					{
						tab[i][j] = tab[i][j-1];
						tab[i][j].takenB = 0;
					}
					else
					{
						tab[i][j] = tab[i-1][j];
						tab[i][j].takenA = 0;
					}
				}
				else  // the same type
				{
					long long val1, val2;
					val1 = tab[i-1][j].value;
					val2 = tab[i][j-1].value;
					long long am1 = (B[j].type == tab[i-1][j].which) ? B[j].amount - tab[i-1][j].takenB : B[j].amount;
					long long am2 = (A[i].type == tab[i][j-1].which) ? A[i].amount - tab[i][j-1].takenA : A[i].amount;
					long long fr1 = A[i].amount;
					long long fr2 = B[j].amount;
					
					long long poss1 = val1 + min(am1, fr1);
					long long poss2 = val2 + min(am2, fr2);
					if (poss1 > poss2)
					{
						long long tkn = min(am1, fr1);
						tab[i][j] = field(poss1, tkn, tkn, A[i].type);
					}
					else
					{
						long long tkn = min(am2, fr2);
						tab[i][j] = field(poss2, tkn, tkn, B[j].type);
					}
				}
			}
		}
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%lld ", tab[i][j].value);
			printf("\n");
		}*/
		printf("Case #%d: %lld\n", nr, tab[n][m].value);
	}
	return 0;
}
