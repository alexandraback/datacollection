#include <map>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int Length = 18;
const int Base = 10;

#define x first
#define y second

typedef long long LL;
typedef pair<LL, LL> Pair;
map<LL, Pair> avail[Length + 1][Base][Base];

void Update(map<LL, Pair> &mp, const LL &diff, const Pair &value) {
    if (mp.end() == mp.find(diff)) {
        mp[diff] = value;
    } else {
        mp[diff] = min(mp[diff], value);
    }
}

void Fix(map<LL, Pair> &mp) {
    if (mp.size() > 1) {
        auto mi = mp.begin();
        auto mj = mp.begin();
        ++mj;
        if (mi->x < 0 && mj->x < 0) {
            mp.erase(mi->x);
        }
    }
    if (mp.size() > 1) {
        auto rmi = mp.rbegin();
        auto rmj = mp.rbegin();
        ++rmj;
        if (rmi->x > 0 && rmj->x > 0) {
            mp.erase(rmi->x);
        }
    }
}

void Gao(const string &a, const string &b, const int pos) {
    int al = ('?' == a[pos] ? 0 : a[pos] - '0');
    int ar = ('?' == a[pos] ? 9 : a[pos] - '0');
    int bl = ('?' == b[pos] ? 0 : b[pos] - '0');
    int br = ('?' == b[pos] ? 9 : b[pos] - '0');
    int apl = ('?' == a[pos - 1] ? 0 : a[pos - 1] - '0');
    int apr = ('?' == a[pos - 1] ? 9 : a[pos - 1] - '0');
    int bpl = ('?' == b[pos - 1] ? 0 : b[pos - 1] - '0');
    int bpr = ('?' == b[pos - 1] ? 9 : b[pos - 1] - '0');
    
    for (int i = apl; i <= apr; ++i) {
        for (int j = bpl; j <= bpr; ++j) {
            for (auto x : avail[pos - 1][i][j]) {
                for (int p = al; p <= ar; ++p) {
                    for (int q = bl; q <= br; ++q) {
                        LL ia = x.y.x * 10 + p;
                        LL ib = x.y.y * 10 + q;
                        
                        Update(avail[pos][p][q], ia - ib, Pair(ia, ib));
                        Fix(avail[pos][p][q]);
                        
                        //cerr << i << ' ' << j << ' ' << x.x << ' ' << p << ' ' << q << ' ' << ia << ' ' << ib << endl;
                    }
                }
            }
        }
    }
}

void Gao(string a, string b) {
    int len = a.length();
    // init
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j < Base; ++j) {
            for (int k = 0; k < Base; ++k) {
                avail[i][j][k].clear();
            }
        }
    }
    a = "0" + a;
    b = "0" + b;
    avail[0][0][0][0] = Pair(0, 0);
    
    for (int i = 1; i <= len; ++i) {
        Gao(a, b, i);
    }
    
    LL answer = LLONG_MAX;
    Pair output;
    
    for (int i = 0; i < Base; ++i) {
        for (int j = 0; j < Base; ++j) {
            for (auto x : avail[len][i][j]) {
                if (abs(x.x) < answer) {
                    answer = abs(x.x);
                    output = x.y;
                } else if (abs(x.x) == answer) {
                    output = min(output, x.y);
                }
            }
        }
    }
    //cerr << answer << endl;
    cout << setw(len) << setfill('0') << output.x << ' ';
    cout << setw(len) << setfill('0') << output.y << endl;
}

int main() {
        freopen("/Users/ybc/Project/CCPP/ACM/B-small-attempt0.in", "r", stdin);
        freopen("/Users/ybc/Project/CCPP/ACM/out.txt", "w", stdout);
    
    string a, b;
    int T;
    
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> a >> b;
        cout << "Case #" << cas << ": ";
        Gao(a, b);
    }
    
    return 0;
}
