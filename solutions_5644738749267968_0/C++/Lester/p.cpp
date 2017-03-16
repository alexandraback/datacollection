#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sz(x) (int)(x).size()

typedef long long ll;

void init() {
	ios_base::sync_with_stdio(false);
}

double a[1111], b[1111];
bool used[1111];

int main() {
	init();
	int tests;
	cin >> tests;
	cout.precision(3);
	cout.setf(ios::fixed);
	for(int t = 1;t <= tests;t++) {
		int n;
		cin >> n;
		for(int i = 0;i < n;i++) {
			cin >> a[i];
		}
		for(int i = 0;i < n;i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);

		int best = 0, worst = 0;
		int ptr1 = 0, ptr2 = n - 1;
		for(int i = n - 1;i >= 0;i--) {
			if(b[i] > a[ptr2]) {
				ptr1++;
			} else {
				ptr2--;
				best++;
			}
		}
		memset(used, 0, sizeof(used));
		for(int i = 0;i < n;i++) {
			int ind = -1;
			for(int j = 0;j < n;j++) {
				if(!used[j] && b[j] > a[i]) {
					ind = j;
					break;
				}
			}
			if(ind == -1) {
				worst++;
			} else {
				used[ind] = true;
			}
		}
		cout << "Case #" << t << ": " << best << ' ' << worst << endl;
	}
	return 0;
}
