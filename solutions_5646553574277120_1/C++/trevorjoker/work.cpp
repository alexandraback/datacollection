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

int test, n, c;
ll a[maxn], v;

void solve(int itest){

	cin >> c >> n >> v;
	For(i, 1, n) cin >> a[i];
	int N = n;

	while(true){
		sort(a + 1, a + n + 1);
		ll sum = 0;
		bool ok = true;
		For(i, 1, n){
			if(sum * c + 1 < a[i]){
				a[++n] = sum * c + 1;
				ok = false;
				break;
			} else sum += a[i];
		}
		if(ok){
			if(sum * c < v){
				a[++n] = sum * c + 1;
			} else{
				break;
			}
		}
	}

	int res = n - N;

	cout << "Case #" << itest << ": " << res << endl;
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
