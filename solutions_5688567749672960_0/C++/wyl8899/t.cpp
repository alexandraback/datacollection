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

const int OUTPUT_TO_FILE = 0;
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

int q[MAXN], f[MAXN];

int rev(int x){
	int y = 0, t = x;
	while(x){
		y = y * 10 + x % 10;
		x /= 10;
	}
	//printf("rev : %d -> %d\n", t, y);
	return y;
}

void pre(int n){
	int l = 1, r = 1;
	q[1] = 1, f[1] = 1;
	while(l <= r){
		int u = q[l++];
		//printf("pre : proc %d\n", u);
		int t;
		t = u + 1;
		if(t >= 1 && t <= n && !f[t]){
			f[t] = f[u] + 1;
			q[++r] = t;
		}
		t = rev(u);
		if(t >= 1 && t <= n && !f[t]){
			f[t] = f[u] + 1;
			q[++r] = t;
		}
	}
}

bool main_solve(){
	static bool havePre = 0;
	if(!havePre){
		havePre = 1;
		pre(1000000);
	}
	int n;
	scanf("%d", &n);
	//printf("solve : %d\n", n);
	printf("%d\n", f[n]);
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
			freopen((prob+".out").c_str(), "w", stdin);
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
