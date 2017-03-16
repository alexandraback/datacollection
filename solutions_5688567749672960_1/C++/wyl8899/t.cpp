#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define mp make_pair
#define X first
#define Y second

#define pb push_back
#define forI_(i,V,_) for(__typeof(V.end())i=_;i!=V.end();++i)
#define forI(i,V) forI_(i,V,V.begin())

#define rep(i,l,r) for(int i = l; i <= r; ++i)
#define per(i,r,l) for(int i = r; i >= l; --i)
#define rep_(i,l,r) for(int i = l; i < r; ++i)
#define per_(i,r,l) for(int i = r; i > l; --i)

// =====================================================
// Settings

string prob = "t";

const int OUTPUT_TO_FILE = 1;
const int MULTI_TESTCASE = 1;
const int TESTCASE_NUM_GIVEN = 1;
const int OUTPUT_CASE_NUM = 1;

const int MAXN = 1000100;
const int MAXM = 0;
const int P = 1000000007;

// =====================================================
// Code goes here.
// main_solve() should return if it has seen EOF if (MULTI_TESTCASE && ! TESTCASE_NUM_GIVEN).
// The return value doesn't matter otherwise.

ll rev(ll x){
	ll y = 0;
	while(x){
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

inline int digit(ll x){
	int s = 0;
	while(x){
		x /= 10;
		++s;
	}
	return s;
}

bool bad(ll x){
	while(x >= 10){
		if(x % 10 != 0)
			return 0;
		x /= 10;
	}
	return x == 1LL;
}

ll sol(ll x){
	if(x <= 20LL)
		return x;
	int d = (digit(x) + 1) / 2;
	ll m = 1;
	while(d--) // x != 0
		m *= 10;
	ll y;
	if(bad(x)){
		y = x - m / 10;
	}else{
		y = (x - 1) / m * m;
		if(bad(y))
			y = y - m / 10;
	}
	//printf("%lld -> %lld, %lld\n", x, m, y * m);
	return (x - y) + sol(rev(y + 1));
}

bool main_solve(){
	static bool havePre = 0;
	if(!havePre){
		havePre = 1;
		/*rep(i, 1, 1000000){
			printf("%d %d\n", i, (int)sol(i));
			fflush(stdout);
		}*/
	}
	ll n;
	cin >> n;
	cout << sol(n) << endl;
}

// =====================================================

int main(){
#ifdef ONLINE_JUDGE
	if(prob == "t")
		prob = "";
#endif
	if(prob != ""){
		freopen((prob+".in").c_str(), "r", stdin);
		if(OUTPUT_TO_FILE)
			freopen((prob+".out").c_str(), "w", stdout);
	}
	if(MULTI_TESTCASE){
		if(TESTCASE_NUM_GIVEN){
			int TC;
			scanf("%d\n", &TC);
			rep(T, 1, TC){
				if(OUTPUT_CASE_NUM)
					printf("Case #%d: ", T);
				main_solve();
			}
		}else{
			while(main_solve());
		}
	}else{
		main_solve();
	}
	return 0;
}
