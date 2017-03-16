#include <iostream>
#include <cstring>

using namespace std;

int p[101][101];

int main() {
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d", &T);
	int c = T;
	while (T --) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				scanf("%d", &p[i][j]);
			}
		}
		bool flagAns = true;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				if (p[i][j] == 1) {
					bool flag = true;
					for (int l = 0 ; l < m ; l ++) {
						if (p[i][l] != 1) {
							flag = false;
							break;
						}
					}
					if (!flag) {
						flag = true;
						for (int l = 0 ; l < n ; l ++) {
							if (p[l][j] != 1) {
								flag = false;
								break;
							}
						}
					}
					if (!flag) {
						flagAns = false;
						break;
					}
				}
			}
			if (!flagAns) break;
		}
		if (flagAns) printf("Case #%d: YES\n", c - T);
		else printf("Case #%d: NO\n", c - T);
	}
	//system("pause");
}