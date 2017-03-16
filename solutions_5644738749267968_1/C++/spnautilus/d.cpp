#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN (1024)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

int T;
double A[MAXN];
double B[MAXN];
set <double> S;

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt)
	{
		int N;
		scanf("%d", &N);

		int i;
		for(i = 0; i < N; ++i)
			scanf("%lf", A + i);
		for(i = 0; i < N; ++i)
		{
			scanf("%lf", B + i);
			S.insert(B[i]);
		}

		sort(A, A + N);
		sort(B, B + N);

		int solw = 0;
		int soldw = 0;

		for(i = 0; i < N; ++i)
		{
			auto si = S.lower_bound(A[i]);
			if(si != S.end())
				S.erase(si);
			else
			{
				S.erase(S.begin());
				++solw;
			}
		}

		int j = 0;
		for(i = 0; i < N; ++i)
		{
			if(A[i] > B[j])
			{
				++soldw;
				++j;
			}
		}

		printf("Case #%d: %d %d\n", tt, soldw, solw);

		S.clear();
	}

	return 0;
}
