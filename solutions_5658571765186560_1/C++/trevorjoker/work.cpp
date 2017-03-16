#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 100000000
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 1000005

int test, n, r, c, d;
string yes = "RICHARD", no = "GABRIEL";

bool cal(int x){
	For(i, 1, n - d + 1){
		int A = (i - 1) * c + (x - 1) * (c - 1);
		if(A % n == 0) return false;
	}
	return true;
}

void solve(int itest){

	cin >> n >> r >> c;
	string res = "";
	if(r < c) swap(r, c);
//	cout << n << " " << r << " " << c << endl;
	if((r * c) % n){
		res = yes;
	} else if(n > r || n > c + c){
		res = yes;
	} else if(n <= c + c - 1){
		res = no;
	}  else{
		res = no;
		d = n - c + 1;
		For(i, 1, d) if(cal(i)) res = yes;
	}

	cout << "Case #" << itest << ": " << res << endl;
}

int main(){
	freopen("in.txt", "r",stdin);
	freopen("out.txt", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> test;

    Rep(run, test){
    	solve(run + 1);
    }

    return 0;
}
