#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

string init(string s, int level) {
    string org(s), sam(s.size(), 'G');
    string ans = s;
    REPU(i, 1, level) {
        ans = "";
        REPU(j, 0, s.size()) {
            if (s[j] == 'L') ans += org;
            else ans += sam;
        }
        s = ans;
    }
    return ans;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
    int noTest, K, C, S;

    while (false) {
        int len, level;
        cin >> len >> level;
        string s(len, 'L');
        vector<string> tmp(len);
        REPU(i, 0, len) {
            s[i] = 'G';
            tmp[i] = init(s, level);
            cout << tmp[i] << endl;
            s[i] = 'L';
        }
        REPU(i, 0, tmp[0].size()) {
            bool ok = true;
            REPU(j, 0, len) if (tmp[j][i] != 'G') {
                ok = false;
            }
            if (ok) {
                cout << "OK" << endl;
                break;
            }
        }
    }

    cin >> noTest;
    REPU(it, 1, noTest + 1) {
        cin >> K >> C >> S;
        printf("Case #%d: ", it);
        ll pos = 1;
        REPU(i, 1, C) pos *= K;
        ll x = pos;
        REPU(i, 1, S + 1) {
            printf("%lld%c", x, " \n"[i == S]);
            x += pos;
        }
    }
	
	return 0;
}
