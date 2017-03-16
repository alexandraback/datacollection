#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

#define N 1000010

using namespace std;

struct Node {
	int mask;
	int sum;
	Node() {
		sum = 0;
	}
	bool operator <(const Node &a) const {
		return sum < a.sum;
	}
}f[1<<20];

int n, a[20];

void output(int k) {
	bool first = true;
	for(int i = 0; i < n; ++i) {
		if((1<<i) & k) {
			if(!first) {
				cout << " ";
			} else {
				first = false;
			}
			cout << a[i];
		}
	}
	cout << endl;
}
int main() 
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	cin >> T;
	for(int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ":" << endl;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < (1<<n); ++i) {
			f[i].mask = i;
			for(int j = 0; j < n; ++j) {
				if(i & (1<<j)) {
					f[i].sum = f[i - (1<<j)].sum + a[j];
					break;
				}
			}
		}
		sort(f, f + (1<<n));
		bool has_ans = false;
		for(int i = 0; i < (1<<n) && !has_ans; ++i) {
			for(int j = i + 1; j < (1<<n) && f[i].sum == f[j].sum; ++j) {
				if(!(f[i].mask & f[j].mask)) {
					has_ans = true;
					output(f[i].mask), output(f[j].mask);
					break;
				}
			}
		}
		if(!has_ans) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}

