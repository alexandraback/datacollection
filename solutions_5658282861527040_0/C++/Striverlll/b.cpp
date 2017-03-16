#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;

int main()
{
	int tt, cas = 0, i, j, k, ans, a, b;
	freopen("binput", "r", stdin);
	freopen("boutput", "w", stdout);
	cin >> tt;
	while (tt --) {	
		cin >> a >> b >> k;
		ans = 0;
		FOR(i, 0, a - 1) 
			FOR(j, 0, b - 1)
			if ((i & j) < k) ans ++;
		printf("Case #%d: ", ++cas);
		cout << ans << endl;
	}
	return 0;
}
