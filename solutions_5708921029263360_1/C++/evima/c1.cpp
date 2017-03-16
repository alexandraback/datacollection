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

int A, B, C, K;

bool check(vector<tuple<int,int,int>> V){
	int c01[11][11] = {};
	int c02[11][11] = {};
	int c12[11][11] = {};
	rep(i, sz(V)){
		c01[get<0>(V[i])][get<1>(V[i])]++;
		c02[get<0>(V[i])][get<2>(V[i])]++;
		c12[get<1>(V[i])][get<2>(V[i])]++;
	}
	rep(i, A) rep(j, B){
		if(c01[i][j] > K) goto fail;
	}
	rep(i, A) rep(k, C){
		if(c02[i][k] > K) goto fail;
	}
	rep(j, B) rep(k, C){
		if(c12[j][k] > K) goto fail;
	}
	return true;
	fail:;
	return false;
}

void main2(){
	cin >> A >> B >> C >> K;
	if(K >= C){
		cout<<A*B*C<<endl;
		rep(i, A) rep(j, B) rep(k, C){
			cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
		}
		return;
	}
	vector<tuple<int,int,int>> ans;
	rep(ia, A){
		rep(i, B*K){
			ans.eb(ia, i/K, (i + K*ia) % C);
		}
	}
	assert(check(ans));
	cout<<sz(ans)<<endl;
	rep(i, sz(ans)){
		cout<<get<0>(ans[i])+1<<" "<<get<1>(ans[i])+1<<" "<<get<2>(ans[i])+1<<endl;
	}


/*
	vector<tuple<int,int,int>> V;
	rep(i, J) rep(j, P) rep(k, S){
		V.eb(i, j, k);
	}
	int ans = 0;
	rep(mask, 1<<sz(V)) if(__builtin_popcount(mask) > __builtin_popcount(ans)){
		int c01[3][3] = {};
		int c02[3][3] = {};
		int c12[3][3] = {};
		rep(i, sz(V)) if(mask >> i & 1){
			c01[get<0>(V[i])][get<1>(V[i])]++;
			c02[get<0>(V[i])][get<2>(V[i])]++;
			c12[get<1>(V[i])][get<2>(V[i])]++;
		}
		rep(i, J) rep(j, P){
			if(c01[i][j] > K) goto fail;
		}
		rep(i, J) rep(k, S){
			if(c02[i][k] > K) goto fail;
		}
		rep(j, P) rep(k, S){
			if(c12[j][k] > K) goto fail;
		}
		ans = mask;
		fail:;
	}
	cout << __builtin_popcount(ans) << endl;
	rep(i, sz(V)) if(ans >> i & 1){
		cout << get<0>(V[i])+1 << " " << get<1>(V[i])+1 << " " << get<2>(V[i])+1 << endl;
	}*/
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
