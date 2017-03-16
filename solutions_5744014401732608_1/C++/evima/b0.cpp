// Enjoy your stay.

#include <bits/stdc++.h>

#define long long long
#define LOOPVAR_TYPE long

#define all(x) (x).begin(), (x).end()
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
#define eb emplace_back

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

int B;
long M;

void main2(){
	cin >> B >> M;
	if(M > (1LL << (B-2))){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	char c[55][55];
	rep(i, B) rep(j, B){
		c[i][j] = '0';
	}
	if(M == (1LL << (B-2))){
		rep(i, B-1) rep(j, i+1, B){
			c[i][j] = '1';
		}
		rep(i, B){
			rep(j, B) cout << c[i][j];
			cout<<endl;
		}
		return;
	}
	rep(i, B-1) rep(j, i+1, B-1){
		c[i][j] = '1';
	}
	rep(i, B-2) if(M >> i & 1){
		c[i+1][B-1] = '1';
	}
	rep(i, B){
		rep(j, B) cout << c[i][j];
		cout<<endl;
	}
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
