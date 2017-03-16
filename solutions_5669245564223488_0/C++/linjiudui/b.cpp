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
typedef __int64 ll;

const ll oo = (1LL)<<40;
const int MAXN = 105;
const int MOD = 1000000007;
const double eps = 1e-8;
int N;
ll P, Q;

ll gcd(ll a, ll b) {
	if(a == 0 || b == 0) return a+b;
	//cout << b << " " << a << endl;
	return gcd(b, a%b);
}
 bool link[MAXN][MAXN];
 string s[MAXN];
 vector<string> ts;
 int du[MAXN];
 bool vis[MAXN];
 
void dfs(int t) 
{
 	vis[t] = true;
 	REP(i, N) {
 		if(!vis[i] && link[t][i]) {
 			dfs(i);
		}
	}
}

bool same(const string& a)
{
	int sz = a.length();
	REP(i, sz) {
		if(a[i] != a[0]) return false;
	}
	return true;
}

ll fact(int t) {
	ll  ret = 1;
	FOR(i, 1, t+1) {
		ret = (ret*i)%MOD;
	}
	//cout << ret << endl;
	return ret;
}

bool check(int t) {
	int l = 1, r = s[t].length()-1;
	int sz = s[t].length();
	while(l < sz && s[t][l] == s[t][0]) l++;
	while(r >= 0 && s[t][sz-1] == s[t][r]) r--;
	//cout << l << " lr " << r << endl;
	for(int i = l; i <= r; i++) {
		for(int j = 0; j < N; j++) {
			if(j == t) continue;
			for(int k = 0; k < s[j].length(); k++)
				if(s[j][k] == s[t][i]){
					//cout << "fuck" << endl;
				 return false;
				}
		}
	}
	return true;
}

int g[MAXN][MAXN];
bool topsort()
{
	memset(g, 0, sizeof(g));
	REP(i, N) {
		REP(j, N) g[i][j] = (int)link[i][j];
	}
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++)
				if(i != j && i != k && k != j && g[i][k] && g[k][j]) {
					g[i][j] = 1;
					if(g[j][i] == 1) return false;
				}
		}
	}
	return true;
}


int main()
{
	int T;
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	cin >> T;
	FOR(_, 1, T+1) {
		memset(du, 0, sizeof(du));
		memset(link, 0, sizeof(link));
		cin >> N;
		REP(i, N) {
			cin >> s[i];
		}
		sort(s, s+N);
		
		int i = 0;
		ll ans = 1;
		ts.clear();
		while(i < N) {
			ts.push_back(s[i]);
			if(!same(s[i])){ i++; continue; }
			int cnt = 1;
			int k = i;
			i++;
			for(int j = i; j < N; j++) {
				if(same(s[j]) && s[k][0] == s[j][0]) {
					cnt++;
					i = j+1;
				} else {
					i = j;
					break;
				}
			}
			//cout << cnt << "cnt" << endl;
			ans = (ans*fact(cnt))%MOD;
		} 
		N = ts.size();
		REP(i, N) s[i] = ts[i];
		//REP(i, N) cout << s[i] << endl;
		REP(i, N) {
			REP(j, N) {
				if(i == j) continue;
				int sz = s[i].length();
				if(s[i][sz-1] == s[j][0]) {
					link[i][j] = true;
					du[j]++;
				}
			}
		}
		bool OK = false;
		REP(i, N) {
			if(du[i] == 0) OK = true;
		}
		//if(!OK) cout << "du" << endl;
		REP(i, N) {
			if(!check(i)) OK = false;
		}
		//if(!OK) cout << "check" << endl;
		if(!topsort()) OK = false;
		//if(!OK) cout << "topsort" << endl;
		cout << "Case #" << _ << ": ";		
		if(OK == false) {
			cout << "0" << endl;
		} else {
			memset(vis, false, sizeof(vis));
			int zone = 0;
			REP(i, N) {
				if(du[i] == 0) {
					zone++;
					dfs(i);
				}
			}
			//cout << ans << " z" << zone << endl;
			ans = (ans*fact(zone))%MOD;
			cout << ans << endl;
		}
	}
	return 0;
}

/*
10
5
a aa b bb bc
*/
