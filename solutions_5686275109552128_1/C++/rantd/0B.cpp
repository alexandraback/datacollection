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

const int N = 1001, INF = 1E9;
int n, p[N];

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    int ntest;
    
    cin >> ntest;
    repu(it, 1, ntest + 1) {
    	cin >> n;
    	repu(i, 0, n) cin >> p[i];
    	
    	int ans = INF;
    	repu(d, 1, N) {
    		int res = d, cnt = 0;
    		repu(i, 0, n) {
    			cnt += (p[i] - 1) / d;
    		}
    		amin(ans, res + cnt);
    	}
    	cout << "Case #" << it << ": " << ans << endl;
    }
    return 0;
}
