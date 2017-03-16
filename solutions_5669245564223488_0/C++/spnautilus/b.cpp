#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (128)
#define MAXS (128)
#define MAXC (128)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int N;
char S[MAXN][MAXS];
int A[MAXN];
int r[MAXN];
int V[MAXC];
int rit;

int sol;

void gen(int depth)
{
	if(depth < N)
	{
		int i;
		for(i = 0; i < N - depth; ++i)
		{
			r[depth] = A[i];
			A[i] = A[N - depth - 1];
			gen(depth + 1);
			A[i] = r[depth];
		}
	}
	else
	{
		++rit;
		int i, j;
		char last = 0;
		int okay = 1;

/*
		for(i = 0; i < N; ++i)
			printf("%d", r[i]);
		putchar('\n');
//*/

		for(i = 0; i < N && okay; ++i)
		{
			int a = r[i];
			for(j = 0; S[a][j] && okay; ++j)
			{
				int c = S[a][j];
				if(V[c] != rit)
				{
					V[c] = rit;
					last = c;
				}
				else
				{
					if(last != c)
					{
						okay = 0;
						break;
					}
				}
			}
		}

		sol += okay;
	}
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i;
		scanf("%d", &N);
		for(i = 0; i < N; ++i)
			scanf("%s", S[i]);

		for(i = 0; i < N; ++i)
			A[i] = i;

		sol = 0;
		gen(0);

		printf("Case #%d: %d\n", TT, sol);
	}

	return 0;
}
