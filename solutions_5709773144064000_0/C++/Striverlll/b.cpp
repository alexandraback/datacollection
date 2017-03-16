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
	int tt, cas = 0;
	double c, f, x, speed, tmp, ans;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	cin >> tt;
	while (tt --) {
		cin >> c >> f >> x;
		printf("Case #%d: ", ++cas);
		ans = x / 2; speed = 2; tmp = 0;
		while (true) {
			tmp += c / speed; speed += f;
			if (x / speed + tmp < ans) ans = x / speed + tmp;
			if (tmp > ans) break;
		}
		printf("%.7lf\n", ans);
	}
	return 0;
}