#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<bitset>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
using namespace std;

#define PB push_back
#define MP make_pair
#define SIZE(X) (int)(X).size()

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, l, h) for(int i = (l); i < (h); i++)
#define RREP(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define FORD(i, l, h) for(int i = (int)(h-1); i >= (l); i--)

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string>VS;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef long long ll;

const ll oo = (1LL)<<40;
const int MAXN = 105;
const int MOD = 1000000007;
const double eps = 1e-8;
int N;

char s[MAXN][MAXN];
char min_str[MAXN];
int cnt[MAXN][MAXN];


void strip(char *src, char *dst)
{
	int n = strlen(src);
	char pre = '#';
	REP(i, n){
		if(src[i] != pre) {
			*dst = src[i];
			pre = src[i];
			dst++;
		}
	}
	*dst = 0;
}

void gao(int t)
{
	int n = strlen(s[t]);
	char pre = '#';
	int j = 0;
	cnt[t][0] = 1; pre = s[t][0];
	FOR(i, 1, n+1) {
		if(pre == s[t][i]) cnt[t][j]++;
		else{
			j++;
			cnt[t][j] = 1;
			pre = s[t][i];
		}
	}
}

int vabs(int t)
{
	return t > 0 ? t : (-t);
}

int calc(int t)
{
	int ret1 = 0, ret2 = 0;
	int tmp[MAXN];
	REP(i, N){
		tmp[i] = cnt[i][t];
	}
	sort(tmp, tmp+N);
	REP(i, N) {
		ret1 += vabs(tmp[i]-tmp[N/2]);
		ret2 += vabs(tmp[i]-tmp[(N+1)/2]);
	}
	int ret = ret1;
	REP(i, N) {
		int cs = 0;
		REP(j, N) {
			cs += vabs(tmp[i]-tmp[j]);
		}
		ret = min(ret, cs);
	}
	if(ret != min(ret1, ret2)) {
		printf("%d %d %d\n", ret, ret1, ret2);
	}
	return min(ret1, ret2);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int T;
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	cin >> T;
	int A, B, K;
	FOR(_, 1, T+1) {
		cin >> A >> B >> K;
		int ans = 0;
		REP(i, A){
			REP(j, B){
				if((i&j) < K){
					ans++;
				}
			}
		}
		cout << "Case #" << _ << ": ";
		cout << ans << endl;
	}
	return 0;
}

/*

*/