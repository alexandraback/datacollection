#include <iostream>
#include <cstdio>

using namespace std;

int p[101][101];

int MaxHang[101];
int MaxLie[101];

int main() {
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	int c = T;
	while (T --) {
		int n, m;
		//int Min = 101, Max = 0;
		memset(MaxHang, 0, sizeof(int) * 101);
		memset(MaxLie, 0, sizeof(int) * 101);
		scanf("%d %d", &n, &m);
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				scanf("%d", &p[i][j]);
				//if (p[i][j] < Min) Min = p[i][j];
				//if (p[i][j] > Max) Max = p[i][j];
				if (p[i][j] > MaxHang[i]) MaxHang[i] = p[i][j];
				if (p[i][j] > MaxLie[j]) MaxLie[j] = p[i][j];
			}
		}

		bool Ans = true;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < m ; j ++) {
				if (MaxHang[i] != p[i][j] && MaxLie[j] != p[i][j]) {
					Ans = false;
					break;
				}
			}
			if (!Ans) break;
		}
		if (Ans) printf("Case #%d: YES\n", c - T);
		else printf("Case #%d: NO\n", c - T);
	}
	//system("pause");
	return 0;
}
