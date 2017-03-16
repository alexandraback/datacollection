#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

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
		string current;
		string n = "";

		printf("Case #%d: ", tc);
		cin >> current;

		for(unsigned i=0; i < current.size(); i++)
		{
			char c = current[i];
			if (n == "")
			{
				n += c;
				continue;
			}

			if (c <= n.back())
				n += c;
			else
			{
				if (c >= n[0])
					n = c + n;
				else
					n += c;
			}
		}
		printf("%s\n", n.c_str());
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