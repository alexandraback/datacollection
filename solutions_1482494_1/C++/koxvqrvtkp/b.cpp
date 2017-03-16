#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
	int nTests;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; ++test) {
		set<pair<int, int> > V1;
		set<pair<int, int> > V2;
		set<pair<int, int> > V2_;
		int n;
		scanf("%d", &n);
		int a[n], b[n];
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i], &b[i]);
			V1.insert(make_pair(a[i], i));
			V2.insert(make_pair(b[i], i));
		}
		int ok = 0;
		int ans = 0;
		int score = 0;
		while (ok < n) {
			if (!V2.empty() && V2.begin()->first <= score) {
				++ans;
				++ok;
				int i = V2.begin()->second;
				V1.erase(make_pair(a[i], i));
				score += 2;
				V2.erase(V2.begin());
			} else if (!V2_.empty() && V2_.begin()->first <= score) {
				++ans;
				++score;
				++ok;
				V2_.erase(V2_.begin());
			} else if (!V1.empty() && V1.begin()->first <= score){
				++ans;

				int i = -1;
				for (set<pair<int, int> >::iterator I = V1.begin(); I != V1.end() && I->first <= score; ++I) {
					if (i == - 1 || b[I->second] > b[i]) {
						i = I->second;
					}
				}
				++score;
				V1.erase(V1.find(make_pair(a[i], i)));
				V2_.insert(make_pair(b[i], i));
				V2.erase(V2.find(make_pair(b[i], i)));
			} else {
				break;
			}
		}
		if (ok == n) {
			printf("Case #%d: %d\n", test, ans);
		} else {
			printf("Case #%d: Too Bad\n", test);
		}
	}
	return 0;
}
