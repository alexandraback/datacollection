//bcw0x1bd2 {{{
#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FILEIO(name)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
	    scanf("%d",&head);
			    RI(tail...);
}

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}
// Let's Fight! }}}

typedef long long LL;

const LL MUL = 101;
const LL MOD = 999997771ll; 

int K,N,M;
int cnt[30];
long double dp[105][105];
int done[105][105];
int match[105];
int bestMatch;
LL preHash[105], pw[105];
char goal[105];

void input(){
	scanf("%d%d%d", &K, &M, &N);
	FZ(cnt);
	char keys[105];
	scanf("%s", keys);
	for (int i=0; i<K; i++){
		int ch = keys[i] - 'A';
		cnt[ch]++;
	}
	scanf("%s", goal);
	LL h = 0;
	for (int i=0; i<M; i++){
		goal[i] -= 'A';
		h = (h * MUL + goal[i]) % MOD;
		preHash[i] = h;
	}
}
long double go(int p, int isM){
	if (p >= N) return 0;
	if (done[p][isM]) return dp[p][isM];
	long double ret = 0;
	for (int v=0; v<26; v++){
		if (cnt[v] == 0) continue;
		LL h = v;
		if (isM > 0) h = (preHash[isM-1] * MUL + v) % MOD;
		int nxtM = 0;
		for (int i = isM+1; i>0; i--){
			
			LL newH;
			if (isM+1-i == 0) newH = h;
			else {
				newH = (h - preHash[isM-i] * pw[i] % MOD) % MOD;
				if (newH < 0) newH += MOD;
			}
			if (preHash[i-1] == newH){
				nxtM = i;
				break;
			}
		}
		if (nxtM == M){
			nxtM = bestMatch;
			ret += (1.0*cnt[v]/K) * (1 + go(p+1, nxtM));
		} else {
			ret += (1.0*cnt[v]/K) * go(p+1, nxtM);
		}
	}
	done[p][isM] = 1;
	return dp[p][isM] = ret;
}
void solve(int t){
	FZ(done);
	long double ret = 0;
	int fail = 0;
	for (int i=0; i<M; i++)
		if (!cnt[(int)goal[i]]) fail = 1;
	bestMatch = 0;
	if (!fail){
		ret = 1;
		int ok=0;
		for (int i=M-1; i>0; i--){
			fail = 0;
			for (int j=0; j<i; j++){
				if (goal[j] != goal[M-i+j]) fail = 1;
			}
			if (!fail){
				bestMatch = i;
				ok = 1;
				ret += (N-M)/(M-i);
				break;
			}
		}
		if (!ok){
			ret = N / M;
		}
	}
	ret -= go(0,0);
	printf("Case #%d: %.10f\n", t, (double)ret);
}
int main(){
	pw[0] = 1;
	for (int i=1; i<105; i++)
		pw[i] = (pw[i-1] * MUL) % MOD;
	int nT;
	scanf("%d", &nT);
	for (int t=1; t<=nT; t++){
		input();
		solve(t);
	}
	return 0;
}

