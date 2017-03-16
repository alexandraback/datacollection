#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

#define inf 1000100
#define maxn 4040

int ds;
int n;
string d[530000];
char s[maxn];
int T[maxn][6];

int test() {
	scanf("%s", s);
	for (n = 0; s[n]; n++) ;
	for (int i = 0; i < 5; i++) {
		T[n][i] = 0;
	}
	for (int p = n-1; p >= 0; p--) {
		for (int r = 4; r >= 0; r--) {
			T[p][r] = T[p][r+1];
			if (r == 4) {
				T[p][r] = inf;
			}
			for (int i = 0; i < ds; i++) {
				bool ok = true;
				int last = r-5;
				int c = 0;
				int l = d[i].size();
				if (p+l > n) {
					continue;
				}
				for (int j = 0; j < l; j++) {
					if (d[i][j] != s[p+j]) {
						if (j-last < 5) {
							ok = false;
							break;
						}
						c++;
						last = j;
					}
				}
				if (!ok) {
					continue;
				}
				int nr = max(0, last+5-l);
				nr = max(nr, r-l);
				T[p][r] = min(T[p][r], c+T[p+l][nr]);
			}
		}
	}
	return T[0][0];
}

int main() {
	FILE *dict = fopen("dictionary.txt", "r");
	while (fscanf(dict, "%s", s) != -1) {
		d[ds++] = s;
	}
	int tt;
	scanf("%d", &tt);
	for (int ttt = 1; ttt <= tt; ttt++) {
		printf("Case #%d: %d\n", ttt, test());
	}
	return 0;
}
