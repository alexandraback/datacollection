#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
//typedef __int64 LL;

int vis[200], num[100];
int R, N, M, K;

int check()
{
	int i;
	for(i = 0; i < K; i++)
		if(!vis[num[i]])
			return 0;
	return 1;
}

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
//	freopen("C-large.in", "r", stdin);
//	freopen("C-large.out", "w", stdout);
	int ks, T, i, j, k;
	 
	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		scanf("%d %d %d %d", &R, &N, &M, &K);

		printf("Case #%d:\n", ks);

		while(R--)
		{
			for(i = 0; i < K; i++)
				scanf("%d", &num[i]);

			for(i = 2; i <= M; i++)
				for(j = 2; j <= M; j++)
					for(k = 2; k <= M; k++)
					{
						CLR(vis);

						vis[1] = 1;
						vis[i] = 1;
						vis[j] = 1;
						vis[k] = 1;
						vis[i*j] = 1;
						vis[j*k] = 1;
						vis[i*k] = 1;
						vis[i*j*k] = 1;

						if(check())
							goto done;
					}

			done:
			printf("%d%d%d\n",i,j,k);
		}
	}

	return 0;
}
