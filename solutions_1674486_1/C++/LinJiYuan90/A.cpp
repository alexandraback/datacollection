#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <vector>
#include <bitset>
#include <string>


using namespace std;

typedef pair<int, int> pii;

int w[1010][1010];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		int n;
		scanf("%d", &n);
		memset(w, 0, sizeof w);
		for (int i = 0; i < n; i++) {
			int k, v;
			for (scanf("%d", &k); k--;) {
				scanf("%d", &v);
				w[i][v-1] ++;
			}
		}
		bool flag = false;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				if (w[i][k]) {
					for (int j = 0; j < n; j++) {
						w[i][j] += w[i][k] * w[k][j];
						if (w[i][j] >= 2) {
							flag = true;
							goto end;
						}
					}
				}
end:
		puts(flag ? "Yes" : "No");
	}
	return 0;
}



