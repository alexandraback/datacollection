#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

typedef __int64 I;

const int N = -1;
const double eps = 0.00001;
const int INF = 0x3fffffff;

map<int, int> tbl;

int main() {
	FILE* stream;
	freopen_s(&stream, "B-small-attempt1.in", "r", stdin);
	freopen_s(&stream, "B-small-attempt1.out", "w", stdout);
	int t;
	scanf_s("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		tbl.clear();
		int n;
		scanf_s("%d", &n);
		for (int i = 0; i < n*2-1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf_s("%d", &x);
				if (tbl.find(x) == tbl.end()) {
					tbl[x] = 1;
				}
				else {
					tbl.erase(x);
				}
			}
		}

		printf("Case #%d:", cas);
		for (map<int, int>::iterator it = tbl.begin(); it != tbl.end(); it++) {
			int val = it->first;
			printf(" %d", val);
		}
		printf("\n");
	}
	return 0;
}