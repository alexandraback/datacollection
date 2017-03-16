#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector < int > numbers[2000003];

void create(int x, int len, int ten) {
	int ix = x;
	for (int i = 1; i < len; ++i) {
		int d = x % 10;
		x /= 10;
		x += d * ten;
		if (x > ix) {
			numbers[ix].push_back(x);
		}
	}
}

void prepare() {
	int len = 1;
	int ten = 10;
	for (int i = 1; i <= 2000000; ++i) {
		if (i == ten) {
			++len;
			ten *= 10;			
		}	
		create(i, len, ten / 10);
	}
}

set < pair < int, int > > q;

void solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	q.clear();
	for (int i = A; i <= B; ++i) {
		for (int j = 0; j < numbers[i].size(); ++j) {
			if (numbers[i][j] >= A && numbers[i][j] <= B) {
				q.insert(make_pair(i, numbers[i][j]));
			}
		}	
	}
	printf("%d\n", q.size());
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	prepare();
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}