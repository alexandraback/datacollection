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

typedef pair<int, int> P;
const int N = 180005;
map<P, int> mp;
int prf[N], suf[N];
const int thresh[4] = {16, 17, 14, 15};


int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    int ntest, L, sg;
    ll X;
    string ss, tt;

    mp[P(1, 1)] = 1; mp[P(1, 'i')] = 'i'; mp[P(1, 'j')] = 'j'; mp[P(1, 'k')] = 'k';
    mp[P('i', 1)] = 'i'; mp[P('i', 'i')] = -1; mp[P('i', 'j')] = 'k'; mp[P('i', 'k')] = -'j';
    mp[P('j', 1)] = 'j'; mp[P('j', 'i')] = -'k'; mp[P('j', 'j')] = -1; mp[P('j', 'k')] = 'i';
    mp[P('k', 1)] = 'k'; mp[P('k', 'i')] = 'j'; mp[P('k', 'j')] = -'i'; mp[P('k', 'k')] = -1;

    cin >> ntest;
    repu(it, 1, ntest + 1) {
    	cin >> L >> X >> tt;
    	int lim = tmin(thresh[X % 4], X);
    	ss = tt;
    	repu(i, 1, lim) ss += tt;
    	vector<int> posi, posk;
    	L = ss.size();
    	prf[0] = 1;
    	repu(i, 0, L) {
    		sg = 1;
    		if (prf[i] < 0) sg = -1;
    		prf[i + 1] = sg * mp[P(tabs(prf[i]), ss[i])];
    		if (prf[i + 1] == 'i') posi.push_back(i + 1);
    	}
    	suf[L + 1] = 1;
    	repd(i, L, 0) {
    		sg = 1;
    		if (suf[i + 1] < 0) sg = -1;
    		suf[i] = sg * mp[P(ss[i - 1], tabs(suf[i + 1]))];
    		if (suf[i] == 'k') posk.push_back(i);
    	}
    	bool ok = 0;
    	if (prf[L] == -1) {
    		reverse(all(posk));
    		int leni = posi.size(), lenk = posk.size();
    		repu(i, 0, leni) {
    			int ind = lower_bound(all(posk), posi[i] + 2) - posk.begin();
    			if (ind < lenk) {
    				ok = 1; break;
    			}
    		}
    	}
    	cout << "Case #" << it << ": " << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
