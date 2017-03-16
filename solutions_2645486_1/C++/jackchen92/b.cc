#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();

const int nmax = 10005;
int mine[nmax], maxe[nmax], v[nmax];
pii vs[nmax];
const bool DEBUG = false;

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		int E, R, n;
		scanf("%d%d%d", &E, &R, &n);
		R = min(E, R);
		for(int i=0;i<n;i++)
		{
			mine[i] = 0;
			maxe[i] = E;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d", v+i);
			vs[i] = pii(-v[i], i);
		}
		sort(vs, vs+n);
		ll V = 0;
		for(int k=0;k<n;k++)
		{
			int i = vs[k].second;
			int e = maxe[i] - mine[i];
			if(e == 0)
				continue;
			if(DEBUG)
				printf("Spending %d (%d -> %d) at %d\n", e, maxe[i], mine[i], i);

			V += (ll)e * v[i];
			
			e = mine[i] + R;
			for(int j = i + 1; j < n && e < E; j++, e += R)
			{
				assert(e <= maxe[j]);
				maxe[j] = e;
			}
			
			e = maxe[i] - R;
			for(int j = i - 1; j >= 0 && e > 0; j--, e -= R)
			{
				assert(e >= mine[j]);
				mine[j] = e;
			}

			if(DEBUG)
			{
				for(int q=0;q<n;q++)
					printf("%d | %d %d | %d\n", q, mine[q], maxe[q], v[q]);
				printf("\n");
			}
		}

		assert(V >= 0);
		printf("Case #%d: %lld\n", test_case, V);
	}
	return 0;
}
