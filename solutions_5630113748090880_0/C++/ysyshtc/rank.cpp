#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

const int MAXN = 2511;

int cc[MAXN];

int main() {
	int task;
	scanf("%d", &task);
	for (int index = 1; index <= task; ++ index) {
		memset(cc, 0, sizeof cc);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n + n - 1; ++ i) {
			for (int j = 0; j < n; ++ j) {
				int x;
				scanf("%d", &x);
				++ cc[x];
			}
		}
		printf("Case #%d:", index);
		for (int i = 1; i < MAXN; ++ i) {
			if ((cc[i] & 1) == 1) {
				printf(" %d", i);
			}
		}
		puts("");
	}
	return 0;
}

