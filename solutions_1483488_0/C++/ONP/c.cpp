#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = 3.1415926535;
const double eps = 1e-6;

int a, b, tot, L[110];
vector <pair<int, int> > ans;
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	for (int i = 1; i <= 2000000; i++) {
		tot = 0;
		int tmp = i;
		while (tmp) {
			L[++tot] = tmp % 10;
			tmp /= 10;
		}
		for (int j = 0; j < tot; j++) {
			int s = 0;
			for (int k = tot; k; k--)
				s = s * 10 + L[k];
			if (s > i) ans.PB(MP(i, s));
			tmp = L[1];
			for (int k = 2; k <= tot; k++)
				L[k - 1] = L[k];
			L[tot] = tmp;
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &a, &b);
		int l = lower_bound(ans.begin(), ans.end(), MP(a, 0)) - ans.begin(), r = upper_bound(ans.begin(), ans.end(), MP(b, 1992837465)) - ans.begin();
		int cou = 0;
		if (l < ans.size())
			for (int j = l; j < r; j++)
				if (a <= ans[j].first && ans[j].first <= b && a <= ans[j].second && ans[j].second <= b)
					cou++;
		printf("Case #%d: %d\n", ++ca, cou);
	}
}
