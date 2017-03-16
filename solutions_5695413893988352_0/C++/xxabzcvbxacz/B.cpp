#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 18
#define INF (1<<30)

struct edge
{
	int s, e;
	bool operator < (const edge &a) const
	{
		return (e < a.e);
	}
};

char buff[MAX_N+5];

char A[2][MAX_N+5];
char C[2][MAX_N+5];
long long mind;
long long mina, minb;

void brute(int i, int a)
{
	if (!A[0][a])
	{
		if (i)
		{
			long long a,b;
			sscanf(C[0], "%lld", &a);
			sscanf(C[1], "%lld", &b);
			long long diff = a-b;
			if (diff < 0)
				diff = -diff;
			if (mind > diff)
			{
				mind = diff;
				mina = a;
				minb = b;
			}
		}
		else
			brute(1, 0);
		return;
	}
	if (A[i][a] == '?')
	{
		for (int j=0; j<10; ++j)
		{
		C[i][a] = '0'+j;
		brute(i, a+1);
		}
		/*C[i][a] = '9';
		brute(i, a+1);
		if (A[i^1][a] != '?')
		{
			C[i][a] = A[i^1][a];
			brute(i, a+1);
		}*/
	}
	else
	{
		C[i][a] = A[i][a];
		brute(i, a+1);
	}
}
int cnta[26];
int res[10];

int main()
{
	int T;
	int N;
	scanf("%d\n", &T);

	char fmt[100];
	for (int t=0; t<T; ++t)
	{
		scanf("%s %s\n", A[0], A[1]);
		//printf("%s %s\n", A[0], A[1]);

		mind = 1LL<<62;
		memset(C, 0, sizeof(C));
		brute(0,0);

		sprintf(fmt, "Case #%%d: %%0%dlld %%0%dlld\n", strlen(A[0]), strlen(A[0]));

		//printf("%s", fmt);
		printf(fmt, t+1, mina, minb);
	}
	return 0;
}
