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
int M;
map < string, int > book;
int id(string s) {
	if(!book.count(s)) {
		book[s] = M++;
	}
	return book[s];
}
pii t[N];
int dp[(1 << 17)];
bool c1[20005], c2[20005];
bool bit(int mask, int x) {
	mask &= (1 << x);
	return mask > 0;
}
void solve() {
	M=0;
	book.clear();
	int n;
	cin>>n;
	REP(i,n){
		string a,b;
		cin>>a>>b;
		int ia,ib;
		ia=id(a);
		ib=id(b);
		t[i]=mp(ia,ib);
	}
	REP(i,(1<<n))dp[i]=-n*100;
	dp[0]=0;
	REP(i,(1<<n)){
		REP(j,M){
			c1[j]=false;
			c2[j]=false;
		}
		REP(j,n){
			if(bit(i,j)){
				c1[t[j].x]=true;
				c2[t[j].y]=true;
			}
		}
		REP(j,n){
			if(!bit(i,j)){
				int r=c1[t[j].x]&c2[t[j].y];
				dp[i+(1<<j)]=max(dp[i+(1<<j)],dp[i]+r);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
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
