#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define INF 1000000000
#define MAX_N 10005
#define PA pair<int, int>
#define PA2 pair<PA, int>

using namespace std;

int tests;
int n, n2;
int t, s;
bool is[MAX_N];
int a[MAX_N], b[MAX_N];
multiset<PA > S1, S2;
multiset<PA >::iterator it, it2;

int main() {
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &tests);
	for (int test = 1; test <= tests ; test ++) {
		scanf("%d", &n);
		S1.clear();
		S2.clear();
		for (int i = 0 ; i < n ; i ++) {
			scanf("%d %d", &a[i], &b[i]);
			is[i] = 0;
			S1.insert(PA(a[i], i));
			S2.insert(PA(b[i], i));
		}
		n2 = 0;
		t = 0;
		s = 0;
		while (n2 != n) {
			//printf("XXX");
			t ++;
			if (!S2.empty() and S2.begin()->first <= s) {
				n2 ++;
				it = S2.begin();
				if (is[it->second]) s ++;
				else s += 2;
				S1.erase(PA(a[it->second], it->second));
				S2.erase(it);
			} else if (!S1.empty() and S1.begin()->first <= s) {
				it = S1.begin();
				for (it2 = S1.begin() ; it2 != S1.end() ; it2 ++) {
					if (it2->first <= s) {
						if (b[it2->second] > b[it->second]) {
							it = it2;
						}
					}
				}
				s ++;
				is[it->second] = true;
				S1.erase(it);
			} else {
				break;
			}
		}
		//printf("KK %d\n", s);
		printf("Case #%d: ", test);
		if (n2 != n) printf("Too Bad\n");
		else printf("%d\n", t);
	}
	return 0;
}