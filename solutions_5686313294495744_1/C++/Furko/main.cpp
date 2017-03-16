#include <bits/stdc++.h>
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
int M1,M2;
map < string, int > book1;
map < string, int > book2;
int id1(string s) {
	if(!book1.count(s)) {
		book1[s] = M1++;
	}
	return book1[s];
}
int id2(string s) {
	if(!book2.count(s)) {
		book2[s] = M2++;
	}
	return book2[s];
}
pii t[N];
vi g[2005];
int dp[(1 << 17)];
bool c1[20005], c2[20005];
bool bit(int mask, int x) {
	mask &= (1 << x);
	return mask > 0;
}
bool used[2005];
int P[2005];
bool kuhn(int v) {
	if(used[v])return false;
	used[v]=true;
	REP(i,sz(g[v])) {
		int to=g[v][i];
		if(P[to]==-1 || kuhn(P[to])) {
			P[to]=v;
			return true;
		}
	}
	return false;
}
void solve() {
	M1=0;
	M2=0;
	book1.clear();
	book2.clear();
	int n;
	cin>>n;
	REP(i, n) used[i]=false;
	REP(i, n) g[i].clear();
	REP(i,n){
		string a,b;
		cin>>a>>b;
		int ia,ib;
		ia=id1(a);
		ib=id2(b);
		g[ia].pb(ib);
	}
	REP(i, n) P[i]=-1;
	int result=0;
	REP(i, n) {
		memset(used,false,sizeof(used));
		if (kuhn(i)) {
			result++;
		}
	}
	cout<<n-(result+(M1-result)+(M2-result))<<endl;
}
int main(){
  FREIN("input.txt");
	FREOUT("output.txt");
	int tests;
	cin>>tests;
	REP(it, tests) {
		cout << "Case #" << it+1 << ": ";
		solve();
	}
	return 0;
}
