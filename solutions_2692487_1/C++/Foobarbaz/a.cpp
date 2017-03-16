#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;

int64 INF = 1000*1000*1001;

ll a[128], a0;
int n;

int main(void)	{
	int T;
	
	cin >> T;
	FOR (nc, 1, T+1) {
		cin >> a0 >> n;
		FOR (i, 0, n)	{
			cin >> a[i];
		}
		sort(a, a+n);
		int best = n;

		if (a0 > 1)	{
			FOR (last, 0, n + 1)	{
				int cost = n - last;
				ll tot = a0;
				FOR (i, 0, last)	{	//deleting [last, n - 1]
					while (tot <= a[i])	{
						tot += tot - 1;
						cost++;
					}
					tot += a[i];
				}
				if (best > cost)	best = cost;
			}
		}
		printf("Case #%d: %d\n", nc, best);
	}
}
