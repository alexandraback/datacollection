#include <bits/stdc++.h>
using namespace std;

#define repu(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i > (b); --i)
#define mem(a, x) memset(a, x, sizeof(a))
#define all(a) a.begin(), a.end()
#define uni(a) a.erase(unique(all(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) {return (a < b) ? a : b;}
template<class T, class U> inline T tmax(T a, U b) {return (a > b) ? a : b;}
template<class T, class U> inline void amax(T &a, U b) {if (b > a) a = b;}
template<class T, class U> inline void amin(T &a, U b) {if (b < a) a = b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {while (b != 0) {T c = a; a = b; b = c % b;} return a;}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    int ntest, S;
    string au;

    cin >> ntest;
    repu(it, 1, ntest + 1) {
    	cin >> S >> au;
    	int ans = 0, tot = au[0] - '0';
    	repu(level, 1, S + 1) {
    		amax(ans, level - tot);
    		tot += au[level] - '0';
    	}
    	cout << "Case #" << it << ": " << ans << endl;
    }
    return 0;
}
