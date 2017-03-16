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

string A, B, C;
ll dp[35][2][2][2][2];
ll solve(int i, int lA, int lB, int lBA, int lC, int x, int y) {
	if(i == 32) {
		if(lA == 0 || lB == 0 || lC == 0) return 0;
		return 1;
	}
	ll &ret = dp[i][lA][lB][lBA][lC];
	if(ret != -1) return ret;
	ret = 0;
	rep(a, 2) rep(b, 2) {
		if(!lA && a && A[i]=='0') continue;
		if(!lB && b && B[i]=='0') continue;
		if(!lC && (a&b) && C[i]=='0') continue;
		// if(!lBA && b>a) continue;
		int nlA = lA || (a==0 && A[i]=='1');
		int nlB = lB || (b==0 && B[i]=='1');
		int nlBA = lBA || (b<a);
		int nlC = lC || ((a&b)==0 && C[i]=='1');
		ret += solve(i+1, nlA, nlB, nlBA, nlC, x*2+a, y*2+b);
	}
	return ret;
}
string f(int a) {
	string t(32, '0');
	rep(i, 32) if(a & (1LL<<i)) t[i] = '1';
	reverse(all(t));
	return t;
}
int main() {
	int t; gi(t);
	rep(T, t) {
		int a, b, c;
		gi(a); gi(b); gi(c);
		if(a < b) swap(a, b);
		A = f(a), B = f(b), C = f(c);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %lld\n", T+1, solve(0, 0, 0, 0, 0, 0, 0));
	}
	return 0;
}