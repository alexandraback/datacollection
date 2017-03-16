// Enjoy your stay.

#include <bits/stdc++.h>

#define long long long
#define LOOPVAR_TYPE long

#define all(x) (x).begin(), (x).end()
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define sz(x) ((LOOPVAR_TYPE)(x).size())
#define foreach(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i, n) _rep2(i, 0, n)
#define _rep2(i, a, b) for(LOOPVAR_TYPE i = (LOOPVAR_TYPE)(a); i < (LOOPVAR_TYPE)(b); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)

#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pb push_back

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long INF = 1070000000LL;
const long MOD = 1000000007LL;

using namespace std;

typedef istringstream iss;
typedef stringstream sst;
typedef pair<LOOPVAR_TYPE, LOOPVAR_TYPE> pi;
typedef vector<LOOPVAR_TYPE> vi;

#include <sys/time.h>
long getTime(){
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec * 1000000LL + t.tv_usec;
}

int K, L, S;
string s, t;
int nx[111][128];

double dp[111][111];
double f(int cur, int state){
	double& res = dp[cur][state];
	if(res > -1) return res;
	if(cur == S) return res = 0;
	res = 0;
	rep(i, K){
		res += (nx[state][s[i]] == L) + f(cur+1, nx[state][s[i]]);
	}
	return res /= K;
}

void main2(){
	cin >> K >> L >> S >> s >> t;
	int c1[128] = {}, c2[128] = {};
	rep(i,K){
		c1[s[i]] = 1;
	}
	rep(i,L){
		c2[t[i]] = 1;
	}
	rep(i,128){
		if(!c1[i] && c2[i]){
			cout<<0<<endl;
			return;
		}
	}
	rep(i,L+1){
		string cur = t.substr(0, i);
		rep(c,'A','Z'+1){
			string newS = cur + (char)c;
			while(1){
				if(newS == t.substr(0, sz(newS))){
					break;
				}
				newS = newS.substr(1);
			}
			nx[i][c] = sz(newS);
		}
	}
	int maxscore = 0;
	int state = 0;
	rep(i,S){
		int next = 0;
		rep(c,'A','Z'+1){
			next = max(next, nx[state][c]);
		}
		if(next == L) maxscore++;
		state = next;
	}
	rep(i,111)rep(j,111)dp[i][j] = -2;
	cout<<setprecision(16)<<maxscore - f(0,0)<<endl;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	
	
	int T;
	cin >> T;
	long start = getTime(), pre = start;
	rep(tc, 1, T + 1){
		cout << "Case #" << tc << ": ";
		main2();
		long now = getTime();
		cerr << tc << "/" << T << ": " << (now - pre) / 1000000. << endl;
		if(tc == T){
			cerr << "Total: " << (now - start) / 1000000. << endl;
			cerr << "  Ave: " << (now - start) / 1000000. / T << endl;
		}
		pre = now;
	}
}
