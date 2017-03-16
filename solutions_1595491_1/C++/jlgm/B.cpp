#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int n, t, s, p, sum[105], cont, resp;
bool can[105];

bool isSol(int a, int b, int c, int r, int d) {
	int hi = max(a, max(b, c));
	int lo = min(a, min(b, c));
	
	if (a+b+c == r && hi-lo < 2) return true;
	else if (a+b+c == r) {
		if (hi-lo == 2) {
			if (cont+1 <= s) {
				can[d] = true;
				return false;
			}
			else return false;
		}
		else return false;
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	
	for (int caso = 1; caso <= n; caso++) {
		cont = resp = 0;
		memset(can, 0, sizeof(can));
		scanf("%d %d %d", &t, &s, &p);
		for (int i = 0; i < t; i++) scanf("%d", &sum[i]);
		
		for (int c = 0; c < t; c++) {
			for (int i = -10; i <= 10; i++)
				for (int j = -10; j <= 10; j++)
					for (int k = -10; k <= 10; k++) {
						bool tmp = false;
						if (max(p+i, max(p+j, p+k)) >= p && p+i >= 0 && p+j >= 0 && p+k >= 0 && p+i <=10 && p+j <= 10 && p+k <= 10) {
							if (isSol(p+i, p+j, p+k, sum[c], c)) {
								resp++;
								i = j = k = 10;
								tmp = true;
							}
						}
						
						if (i == 10 && j == 10 && k == 10 && !tmp) {
							if (can[c]) resp++, cont++;
						}
					}
		}
		printf("Case #%d: %d\n", caso, resp);
	}
	return 0;
}
