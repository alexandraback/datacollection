#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int LIMIT = 2501;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int N;
		//vector<string> v;
		graph occ(LIMIT, vector<int>());

		printf("Case #%d: ", tc);
		scanf("%d", &N);

		//v.assign((2*N)-1, "");
		for(int i=0; i < (2*N)-1; i++)
		{
			for(int j=0; j < N; j++)
			{
				int current;
				cin >> current;
				occ[current].push_back(i);
			}
		}

		for(int i=1; i < LIMIT; i++)
		{
			if (occ[i].size() > 0)
			{
				if (occ[i].size() % 2 != 0)
					printf("%d ", i);
				/*print("\n%d: ", i);
				for(auto &el : occ[i])
				{
					print("%d ", el);
				}*/
			}
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

void print(const char* msg, ...)
{
	#ifndef ONLINE_JUDGE
		va_list argptr;
		va_start(argptr, msg);
		vfprintf(stderr, msg, argptr);
		va_end(argptr);
	#endif
}