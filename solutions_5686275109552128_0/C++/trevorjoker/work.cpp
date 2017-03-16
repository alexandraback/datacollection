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

int test, n, a[maxn];
string s;

void solve(int itest){
	cin >> n;
	int res = inf, maxa = 0;
	For(i, 1, n) {
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}

	For(i, 1, maxa){
		int ret = 0;
		For(j, 1, n){
			int devide = a[j] / i;
			if(devide * i == a[j]) devide--;
			ret += devide;
		}
		res = min(res, i + ret);
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
