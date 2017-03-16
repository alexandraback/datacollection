//Template

// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()

#define N 55
int v[N], waste[N], done[N];
vi adj[N];
pair <string, int> s[N];
void dfs(int cur) {
	v[cur] = 1;
	rep(i, adj[cur].sz) if(waste[adj[cur][i]] == false && v[adj[cur][i]] == 0) dfs(adj[cur][i]);
}
int n;
bool solve(vi &a, int j) {
	if(a.sz == 0) {
		a.pb(j);
		return true;
	}
	vi b = a;
	while(true) {
		int cur = a.back();
		rep(i, adj[cur].sz) if(adj[cur][i] == j) {
			a.pb(j);
			return true;
		}
		if(a.sz == 1) {
			a = b;
			rep(i, a.sz) waste[a[i]] = false;
			return false;
		}
		waste[cur] = true;
		memset(v, 0, sizeof v);
		dfs(a[0]);
		bool valid = true;
		rep(i, n) if(!done[i] && v[i]==0) valid = false;
		if(!valid) {
			a = b;
			rep(i, a.sz) waste[a[i]] = false;
			return false;
		}
		a.pop_back();
	}
}

int main() {
	int t; gi(t);
	rep(T, t) {
		int m;
		gi(n); gi(m);
		rep(i, n) adj[i].clear();
		rep(i, n) {
			cin >> s[i].ff;
			s[i].ss = i;
		}
		rep(i, m) {
			int u, v;
			gi(u); gi(v);
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		sort(s, s+n);
		string ans = "";
		vi a;
		memset(done, 0, sizeof done);
		memset(waste, 0, sizeof waste);
		rep(i, n) {
			rep(j, n) if(done[s[j].ss] == 0) {
				//can i put j now?
				bool ok = solve(a, s[j].ss);
				if(ok) {
					ans += s[j].ff;
					done[s[j].ss] = true;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", T+1, ans.c_str());
	}
}