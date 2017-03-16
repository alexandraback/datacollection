#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = 233333;
const int trans[7][7] = {{0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};

char s[maxn], c[maxn];

int Sgn(int u){
	return u < 0? -1: u > 0;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int len;
		long long X;
		scanf("%d%lld", &len, &X);
		X = min(X, 8LL + X % 4LL);
		int x = (int)X;
		scanf("%s", c);
		for (int i = 1, j = 0; i <= x; ++i, j += len)
			strcpy(s + j, c);
		int n = len * x;
		int now = 1;
		int firsti = n;
		for (int i = 0; i < n; ++i){
			now = Sgn(now) * trans[abs(now)][s[i] - 'i' + 2];
			if (now == 2) firsti = min(firsti, i);
		}
		if (now != -1){
			printf("Case #%d: NO\n", TI);
			continue;
		}
		now = 1;
		bool flag = 0;
		for (int i = n - 1; i >= 0; --i){
			now = Sgn(now) * trans[s[i] - 'i' + 2][abs(now)];
			if (now == 4 && i > firsti + 1) flag = 1;
		}
		printf("Case #%d: %s\n", TI, flag? "YES": "NO");
	}
	return 0;
}
