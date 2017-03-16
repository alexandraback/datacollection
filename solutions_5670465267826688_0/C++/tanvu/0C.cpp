#include <bits/stdc++.h>
using namespace std;

#define repu(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i > (b); --i)
#define mem(a, x) memset(a, x, sizeof(a))
#define all(a) a.begin(), a.end()
#define uni(a) a.erase(unique(all(a)), a.end())
#define count_bits(x) __builtin_popcount(x)
#define count_bitsll(x) __builtin_popcountll(x)
#define least_bits(x) __builtin_ffs(x)
#define least_bitsll(x) __builtin_ffsll(x)
#define most_bits(x) 32 - __builtin_clz(x)
#define most_bitsll(x) 64 - __builtin_clz(x)

vector<string> split(const string &s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

void err(vector<string>::iterator it) {}

template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) {return (a < b) ? a : b;}
template<class T, class U> inline T tmax(T a, U b) {return (a > b) ? a : b;}
template<class T, class U> inline void amax(T &a, U b) {if (b > a) a = b;}
template<class T, class U> inline void amin(T &a, U b) {if (b < a) a = b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {while (b != 0) {T c = a; a = b; b = c % b;} return a;}

#define first X
#define second Y

typedef pair<int, int> P;
const int N = 210505;
map<P, int> mp;
int prf[N], suf[N];
const int thresh[4] = {16, 17, 18, 19};


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
    	reverse(all(posk));
    	int leni = posi.size(), lenk = posk.size();
    	bool ok = 0;
    	repu(i, 0, leni) {
    		int ind = lower_bound(all(posk), posi[i] + 2) - posk.begin();
    		repu(j, ind, lenk) {
    			int lb = posi[i] + 1, rb = posk[j] - 1;
    			sg = (tabs(prf[lb - 1]) == 1) ? 1 : -1;
    			if (prf[lb - 1] < 0) sg = -sg;
    			if (prf[rb] < 0) sg = -sg;
    			int x = sg * mp[P(tabs(prf[lb - 1]), tabs(prf[rb]))];
    			if (x == 'j') {
    				ok = 1; break;
    			}
    		}
    		if (ok) break;
    	}
    	cout << "Case #" << it << ": " << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
