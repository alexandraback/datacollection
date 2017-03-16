#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/malzantot/Documents/codingspace/gcj/B-large.in.txt", "r", stdin);
	freopen("/Users/malzantot/Documents/codingspace/gcj/B1-large-out.txt", "w", stdout);

	#endif

	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		int n;
		int x;
		cin >> n;
		int heightCount[2501];
		memset(heightCount, 0, 2501*sizeof(int));
		for (int j = 0; j < 2*n-1; j++) {
			for (int k = 0; k < n; k++) {
				cin >> x;
				heightCount[x]++;
			}
		}

		vector<int> h;
		for (int j = 1; j <= 2500; j++) {
			if (heightCount[j]%2==1) {
				h.push_back(j);
			}
		}
		sort(h.begin(), h.end());
		printf("Case #%d:", i);
		for (int j = 0; j < h.size(); j++) {
			printf(" %d", h[j]);
		}
		puts("");
	}
	
	return 0;

}
