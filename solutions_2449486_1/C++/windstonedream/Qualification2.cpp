#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int cas, c = 1;
	int w, h;
	int d[128][128];
	bool rows[128], cols[128];
	int nfin = 0;
	int minlen = 128, maxlen = -1;
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	for(scanf("%d", &cas);  cas; -- cas, ++ c) {
		printf("Case #%d: ", c);
		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; ++ i) {
			for(int j = 0; j < w; ++ j) {
				scanf("%d", &d[j][i]);
				maxlen = max(maxlen, d[j][i]);
				minlen = min(minlen, d[j][i]);
			}
		}
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));
		bool modify = true;
		nfin = 0;
		for (int cri = minlen; cri <= maxlen; ++ cri) {
			modify = false;
			for(int i = 0; i < h; ++ i) {
				bool erase = true;
				for(int j = 0; j < w; ++ j) {
					if(d[j][i] != -1 && d[j][i] != cri) {
						erase = false;
						break;
					}
				}
				if (erase) {
					modify = true;
					rows[i] = true;
					for(int j = 0; j < w; ++ j) {
						if(d[j][i] != -1) {
							d[j][i] = -1;
							nfin ++;
						}
					}
				}
			}

			for(int i = 0; i < w; ++ i) {
				bool erase = true;
				for(int j = 0; j < h; ++ j) {
					if(d[i][j] != -1 && d[i][j] != cri) {
						erase = false;
						break;
					}
				}
				if (erase) {
					modify = true;
					cols[i] = true;
					for(int j = 0; j < h; ++ j) {
						if(d[i][j] != -1) {
							d[i][j] = -1;
							nfin ++;
						}
					}
				}
			}
		}
		if (nfin >= w * h) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}