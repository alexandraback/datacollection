#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int			n;
int			list	[50];

const int			ZERO = 2500000;
bool			optm		[21][ZERO * 2];
char			prevm		[21][ZERO * 2];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", list + i);
}

//#define opt(i,j) optm[i][ZERO+j]
//#define prev(i,j) prevm[i][ZERO+j]

bool& opt(int i, int j){ return optm[i][ZERO+j]; }
char& prev(int i, int j){ return prevm[i][ZERO+j]; }

int			A[50], ca;
int			B[50], cb;

void trace(int i, int s)
{
	if(!i) return;
	if (prev(i,s) == 3)
	{
	}
	else if (abs(prev(i,s)) == 1)
	{
		A[ca ++] = list[i-1];
		s -= list[i-1];		
	}
	else if (abs(prev(i,s)) == 2)
	{
		B[cb ++] = list[i-1];
		s += list[i-1];
	}

	if (prev(i,s) > 0)
		trace(i-1, s);
}

void solve1()
{
	memset(optm, 0, sizeof(optm));
	int sum = 0;

	for (int i = 0; i < n; i ++)
	{
		opt(i+1, list[i]) = 1;
		prev(i+1, list[i]) = -1;

		opt(i+1, -list[i]) = 1;
		prev(i+1, -list[i]) = -2;

		for (int s = -sum; s <= sum; s ++)
			if (opt(i,s))
			{
				opt(i+1,s) = 1;
				prev(i+1, s) = 3;

				opt(i+1,s+list[i]) = opt(i+1,s-list[i]) = 1;
				prev(i+1,s+list[i]) = 1;
				prev(i+1,s-list[i]) = 2;
			}
		sum += list[i];

		if (opt(i+1,0))
		{
			ca = cb = 0;
			trace(i+1, 0);
			
			for (int p = 0; p < ca; p ++)
			{
				printf("%d%c", A[p], p + 1 == ca ? '\n' : ' ');
			}
			for (int p = 0; p < cb; p ++)
			{
				printf("%d%c", B[p], p + 1 == cb ? '\n' : ' ');
			}
			return;
		}
	}

	printf("Impossible\n");
}

bool dfs(int i, int pa, int pb, int diff)
{
	if (i && pa && pb && diff == 0)
	{
		for (int p = 0; p < pa; p ++)
			printf("%d%c", A[p], p + 1 == pa ? '\n' : ' ');
		for (int p = 0; p < pb; p ++)
			printf("%d%c", B[p], p + 1 == pb ? '\n' : ' ');
		return 1;
	}
	if (i == n) return 0;

	A[pa] = list[i];
	if (dfs(i + 1, pa + 1, pb, diff + list[i])) return 1;
	B[pb] = list[i];
	if (dfs(i + 1, pa, pb + 1, diff - list[i])) return 1;
	if (dfs(i + 1, pa, pb, diff)) return 1;

	return 0;
}

void solve()
{
	if( !dfs(0, 0, 0, 0))
		printf("Impossible\n");
}

int main()
{
//	freopen("in.txt", "r", stdin);
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-2.out", "w", stdout);

//	freopen("A-large.out", "w", stdout);

	int caseNo;
	scanf("%d", &caseNo);

	for (int t = 1; t <= caseNo; t ++)
	{
		printf("Case #%d:\n", t);

		init();
		solve1();
	}
	return 0;
}