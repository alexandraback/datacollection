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

const int MAXN = 0;
const int MAXM = 0;
const int P = 1000000007;

// =====================================================
// Code goes here.
// main_solve() should return if it has seen EOF if (MULTI_TESTCASE && ! TESTCASE_NUM_GIVEN).
// The return value doesn't matter otherwise.

int p[3];
int v[3];

bool main_solve(){
	int n, N = 0;
	cin >> n;
	while(n--){
		int d, m, h;
		cin >> d >> h >> m;
		rep(i, 0, h - 1){
			++N;
			p[N] = d;
			v[N] = m + i;
		}
	}
	if(N == 1 || v[1] == v[2]){
		puts("0");
		return 0;
	}
	if(v[1] > v[2]){
		swap(v[1], v[2]);
		swap(p[1], p[2]);
	}
	double t, dv = (360.0 / v[1]) - (360.0 / v[2]);
	double dp;
	if(p[1] >= p[2])
		dp = 360 - (p[1] - p[2]);
	else
		dp = 720 - (p[2] - p[1]);
	t = dp / dv;
	t = p[1] + t * (360.0 / v[1]);
	if(t <= 360.0)
		puts("1");
	else
		puts("0");
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
