#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector <int> vi;

int main() {
	int T;
	scanf("%d", &T);
	for (int TT = 0; TT < T; ++TT) {
		int A, N;
		scanf("%d%d", &A, &N);
		priority_queue <int, vi, greater <int> > a;
		for (int i = 0; i < N; ++i) {
			int x;
			scanf("%d", &x);
			a.push(x);
		}

		while (!a.empty() && a.top() < A) {
			A += a.top();
			a.pop();
		}

		int mn = a.size();
		int ops = 0;
		while (A != 1 && !a.empty()) {
			++ops;
			A += A - 1;

			while (!a.empty() && a.top() < A) {
				A += a.top();
				a.pop();
			}

			mn = min(mn, ops + (int)a.size());
		}

		printf("Case #%d: %d\n", TT + 1, mn);
	}

	return 0;
}