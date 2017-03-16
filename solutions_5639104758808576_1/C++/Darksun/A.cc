#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
const int MAXN = 2e5 + 7, Mo = 1e9 + 7;

char ss[MAXN];
int n;

int main(){							
	int t; scanf("%d", &t);
	for (int cas = 1; cas <=t; cas++){
		printf("Case #%d: ", cas);
		scanf("%d%s", &n, ss);
		int rst = 0, tot = 0;
		for (int i=0; i<=n; i++){
			if (tot < i){
				rst += i-tot;
				tot += i-tot;
			}
			if (tot >= i) tot += ss[i] - '0';
		}
		printf("%d\n", rst);
	}
	return 0;
}
