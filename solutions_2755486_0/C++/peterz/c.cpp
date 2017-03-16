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
#define INF 1LL << 16
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
int N, m;
LL d[1010], n[1010], w[1010], e[1010], s[1010], dd[1010], dp[1010], ds[1010];
LL D[1010 * 1010], sz;
int sus[1010 * 1010];
struct atk{
	LL s, lo, hi, d;
	atk(){}
	atk(LL w, LL x, LL y, LL z){
		s = w; lo = x; hi = y; d = z;
	}
	bool operator < (atk p) const{
		if (d != p.d) return d < p.d;
		return s < p.s;
	}
};
vector<atk> A;
LL ST[2000 * 2000];

void upd(LL l, LL r, LL v){
	FOE(i,2 * l,2 * r) ST[i] = max(ST[i], v);
}
LL que(LL l, LL r){
	LL ret = INF;
	FOE(i,2 * l,2 * r) ret = min(ret, ST[i]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		scanf("%d", &N);
		FOR(i,0,N) scanf("%lld%lld%lld%lld%lld%lld%lld%lld", 
								d + i,	n + i, w + i, e + i, s + i, dd + i, dp + i, ds + i);
		sz = 0;
		A.clear();
		memset(ST, 0, sizeof(ST));

		FOR(i,0,N) FOR(j,0,n[i]){
			LL tmp = dp[i];
			D[sz++] = w[i] + j * tmp;
			D[sz++] = e[i] + j * tmp;
		}
		sort(D, D + sz);
		m = unique(D, D + sz) - D;

		FOR(i,0,N) FOR(j,0,n[i]){
			LL x = lower_bound(D, D + m, w[i] + j * dp[i]) - D;
			LL y = lower_bound(D, D + m, e[i] + j * dp[i]) - D;
			A.PB(atk(s[i] + j * ds[i], x, y, d[i] + j * dd[i]));
		}
		sort(A.begin(), A.end());

		LL ans = 0, pre = 0;
		FOR(i,0,A.size()){
			if (que(A[i].lo, A[i].hi) < A[i].s) sus[i] = 1;
			else sus[i] = 0;
			if (i == (A.size() - 1) || A[i].d != A[i + 1].d){
				FOE(j,pre,i){
					if (!sus[i]) continue;
	//				printf("%d\n", A[j].d);
					ans++;
					upd(A[i].lo, A[i].hi, A[i].s);
				}
				pre = i + 1;
			}
		}

		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

