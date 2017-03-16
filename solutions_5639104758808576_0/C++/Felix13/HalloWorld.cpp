#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_tree;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define INF 1000000001
#define LINF 1000000000000000001ll
#define PB push_back
#define EPS 1e-7
#define X first
#define Y second
#define MP make_pair
#define ITER(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()

int main() {
	//ios::sync_with_stdio(0);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t;
	cin >> t;
	FOR(ttt,0,t)
	{
		int n;
		string s;
		cin >> n >> s;
		int lack = 0;
		int sum = s[0] - '0';
		FOR(i,1,s.size())
		{
			int xi = s[i] - '0';
			if (xi) {
				lack = max(lack, i - sum);
				sum += xi;
			}
		}
		printf("Case #%d: %d\n", ttt + 1, lack);
	}
	return 0;
}
