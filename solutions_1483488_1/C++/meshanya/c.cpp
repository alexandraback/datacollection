#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "c"
using namespace std;

int t, a, b, d[10], k, num;
long long ans;
set<int> used;

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &a, &b);
		ans = 0;
		for (int i = a; i <= b; ++i) {
			k = 0, num = i;
			while (num > 0) {
				d[k++] = num % 10;
				num /= 10;
			}
			used.clear();
			for (int j = 0; j < k; ++j) {
				d[k] = d[0];
				for (int l = 0; l < k; ++l)
					d[l] = d[l + 1];
				num = 0;
				for (int l = k - 1; l >= 0; --l)
					num = num * 10 + d[l];
				if ((num > i) && (num >= a) && (num <= b) && !used.count(num)) {
					used.insert(num);
					++ans;
				}
			}
		}
		printf("Case #%d: %lld\n", it + 1, ans);
	}
	return 0;
}