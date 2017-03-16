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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

bool check (char ch)
{
	if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
		return true;
	return false;
}

void solve()
{
	char s[1000010];
	int n;
	vector <int> b, e;
	scanf("%s%d", s, &n);
	int now = -1, len = strlen(s);
	for (int i = 0; i < len; ++i) {
		if (now == -1) {
			if (check(s[i]))
				now = i;
		}
		else {
			if (!check(s[i])) {
				if (i - now >= n) {
					b.push_back(now);
					e.push_back(i - 1);
				}
				now = -1;
			}
		}
	}
	if (now != -1 && len - now >= n) {
		b.push_back(now);
		e.push_back(len - 1);
	}
	//for (int i = 0; i < b.size(); ++i)
	//	printf("%d %d\n", b[i], e[i]);
	int ans = 0, j = 0;
	for (int i = 0; i < len; ++i) {
		if (j == b.size())
			break;
		if (i + n - 1 > e[j])
			++j;
		if (j == b.size())
			break;
		if (i <= b[j])
			ans += len - (b[j] + n - 1);
		else
			ans += len - (i + n - 1);
	}
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
