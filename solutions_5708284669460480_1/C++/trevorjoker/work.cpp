#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>

using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s);}

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
#define y0 y141290
#define maxn 400005

int test, n, m, s;

double f[55];
string s1, s2;

void solve(int itest){
	cin >> n >> m >> s;
	cin >> s1 >> s2;

	ms(f, 0);
	for(int i = 0; i < n; i++){
		int c = s1[i] - 'A';
		f[c] += (ld)(1.0) / n;
	}

	ld RR = (s - m + 1);
	bool ok = true;

	for(int i = 0; i < m; i++){
		int c = s2[i] - 'A';
		RR *= f[c];
		if(f[c] < eps) ok = false;
	}

	int loop = m;
	for(int i = 1; i < m; i++){
		if(s2.substr(0, m - i).compare(s2.substr(i, m - i)) == 0){
			loop = i;
			break;
		}
	}

	int res = (s - m) / loop + 1;
	if(!ok) res = 0;
	cout << fixed << setprecision(9);
	cout << "Case #" << itest << ": " << res - RR << endl;
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin >> test;
    For(i, 1, test){
    	solve(i);
    }

    return 0;
}
