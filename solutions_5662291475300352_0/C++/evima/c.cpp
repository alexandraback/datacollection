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



void main2(){
	int N;
	cin >> N;
	assert(N <= 2);
	vi D, M;
	rep(i, N){
		int d, h, m;
		cin >> d >> h >> m;
		assert(h <= 2);
		rep(j, h){
			D.pb(d);
			M.pb(m + j);
		}
	}
	assert(sz(D) <= 2);
	if(sz(D) == 1){
		cout << 0 << endl;
		return;
	}
	long d1, m1, d2, m2;
	d1 = D[0], m1 = M[0];
	d2 = D[1], m2 = M[1];
	if(m1 == m2){
		cout << 0 << endl;
		return;
	}
	if(m1 > m2){
		swap(m1, m2);
		swap(d1, d2);
	}
	if(d2 * (m2 - m1) + m1 * (d2 - d1 + 360) <= 360 * (m2 - m1)){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
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
