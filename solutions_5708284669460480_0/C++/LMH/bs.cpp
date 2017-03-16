#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(int i=a;i<=b;i++)
#define FD(i,a, b) for(int i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 2000000000
#define MAXN ?
#define MAXE ?
#define ll long long
using namespace std;
int q, n, m, k, l, s, K, ma, sum;
double ans = 0;
char cur[1000], key[1000], tar[1000];
int add(int x){
	if(x + 1 < l) return 0;
	FI(i, x - l + 1, x){
		if(cur[i] != tar[i - (x - l + 1)]) return 0;
	}
	return 1;
}
void dfs(int x, int y){
	ma = max(y, ma);
	if(x == s){
		sum += y;
		return;
	}
	FI(i, 0, k - 1){
		cur[x] = key[i];
		dfs(x + 1, y + add(x));
		cur[x] = 0;
	}

}
int main(){
	scanf("%d", &K);
	FI(q, 1, K){
		scanf("%d%d%d", &k, &l, &s);
		scanf("%s%s", key, tar);
		sum = 0;
		ma = 0;
		dfs(0, 0);
		ans = (1.0 * sum);
		FI(i, 1, s) ans /= k;
		ans = ma - ans;
		printf("Case #%d: %.8lf\n", q, ans);

	}
}
