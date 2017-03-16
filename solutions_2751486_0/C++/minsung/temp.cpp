#include<cstdio>
#include<cstring>

#define N 100005
using namespace std;

int tc;
char str[N];
int n,m;
long long ans;
bool tt[256];
int t[N];
int main() {
	int i,j,k;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &tc);
	tt['a'] = tt['e'] = tt['i'] = tt['o'] = tt['u'] = true;
	for(int tcc = 1; tcc<= tc; tcc++){
		scanf("%s %d ", &str, &n);
		ans = 0;
		m = strlen(str);
		int cnt = 0;
		int p = m;
		for(i = m-1; i>= 0; i--) {
			if (tt[str[i]]) {
				cnt = 0;
				ans += m-p;
			} else {
				cnt++;
				if (cnt >= n) {
					p = i + n - 1;
				}
				ans += m-p;
			}
		}
		printf("Case #%d: %lld\n", tcc, ans);
	}
	return 0;
}