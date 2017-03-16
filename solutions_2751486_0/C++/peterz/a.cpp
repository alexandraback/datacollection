#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define LL long long
#define EPS 1e-9
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
#define N 1001000
int n, m;
char s[N];
int p[N], a[N];
int vow[300] = {0};
int main(){
	int T;
	vow['a'] = 1;
	vow['e'] = 1;
	vow['i'] = 1;
	vow['o'] = 1;
	vow['u'] = 1;
	scanf("%d", &T);
	FOE(cc,1,T){
		int tmp = -1;
		LL ans = 0;
		memset(p, 0, sizeof(p));
		scanf("%s%d", s, &n);
		m = strlen(s);
		for (int i = m - 1; i >= 0; i--){
			if (vow[s[i]]) p[i] = 0;
			else p[i] = p[i + 1] + 1;
			if (p[i] >= n) tmp = i;
			if (tmp != -1){
				ans += m - (tmp + n - 1);
			}
		}
		printf("Case #%d: %lld\n", cc, ans);
	}
	return 0;
}

