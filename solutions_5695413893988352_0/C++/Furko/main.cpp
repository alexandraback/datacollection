#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y0 smthngy0
#define y1 smthngy1
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define str fuck2
#define ld long double
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1000000000; //1e9
const int inf = 1e9+1;
const double eps = 1e-9;
long long toInt(string r) {
	long long ret = 0;
	REP(i, sz(r)) ret = ret * 10 + r[i] - '0';
	return ret;
}
bool good(string &a) {
	for (auto e : a) {
		if (e == '?') {
			return false;
		}
	}
	return true;
}
long long ans=-1;
string ansA, ansB;
void run(string a, string b) {
	if (good(a) && good(b)) {
		long long dif = toInt(a) - toInt(b);
		dif = abs(dif);
		if (ans == -1 || (dif < ans || (dif == ans && a < ansA))) {
			ans = dif;
			ansA = a;
			ansB = b;
		}
	}
	bool was=false;
	REP(i, sz(a)) {
		if (a[i] == '?') {
			was=true;
			REP(d, 10) {
				a[i] = (char)(d + '0');
				run(a, b);
				a[i] = '?';
			}
			break;
		}
	}
	if (was)return;
	REP(i, sz(b)) {
		if(b[i]=='?'){
			REP(d,10){
				b[i]=(char)(d+'0');
				run(a,b);
				b[i]='?';
			}
			break;
		}
		
	}
}
void solve() {
	string a,b;
	cin>>a>>b;
	ans=-1;
	run(a, b);
	cout<<ansA<<" "<<ansB<<endl;
}
int main(){
  FREIN("input.txt");
	FREOUT("output.txt");
	int tests;
	scanf("%d", &tests);
	REP(it, tests) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}
