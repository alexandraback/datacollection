#include <cstdio>
#include <cstring>
const int N = 110;
int T, c, d, v, a[N];
bool f[N];
/*void tr(int x){
	memset(f[x], 0, sizeof(f[x]));
	for (int i = 1; i <= v; ++i) if (f[x - 1][i] == 0){
		for (int j = 0; j <= v; ++j){
			f[x][j] |= f[x - 1][j];
			if (j + i <= v) f[x][j + i] |= f[x - 1][j];
		}
		tr(x + 1);
		
	}
}*/
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d%d%d", &c, &d, &v);
		for (int i = 1; i <= d; ++i) scanf("%d", &a[i]);
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 1; i <= d; ++i){
			for (int j = v - a[i]; j >= 0; --j) f[j + a[i]] |= f[j];
		}
		int ans = 0;
		for (; ; ){
			bool succ = true;
			int pos;
			for (pos = 1; pos <= v; ++pos) if (f[pos] == 0){
				succ = false;
				break;
			}
			if (succ) break;
			for (int i = v - pos; i >= 0; --i) f[i + pos] |= f[i];
			++ans;
		}
		printf("Case #%d: %d\n", Ti, ans);
	}
	return 0;
}
