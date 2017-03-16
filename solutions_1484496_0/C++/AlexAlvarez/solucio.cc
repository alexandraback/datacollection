#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVB> VVVB;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<VVC> VVVC;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<VVS> VVVS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<VD> VVD;
const int INF = 1000000000;

VI v;
bool final;

VI M[3000000];

void rec(int p, VI& s, int sum) {
    if (final) return;
    if (p == v.size()) {
        if (M[sum].size() == 0) M[sum] = s;
        else {
            for (int i = 0; i < M[sum].size(); ++i) {
                if (i != 0) cout << " ";
                cout << M[sum][i];
            }
            cout << endl;
            for (int i = 0; i < s.size(); ++i) {
                if (i != 0) cout << " ";
                cout << s[i];
            }
            cout << endl;
            final = true;
        }
        return;
    }
    rec(p + 1, s, sum);
    s.push_back(v[p]);
    rec(p + 1, s, sum + v[p]);
    s.pop_back();
}

int main() {
    int casos;
    cin >> casos;
    for (int cas = 1; cas <= casos; ++cas) {
        for (int i = 0; i < 3000000; ++i) M[i] = VI(0);
        int n;
        cin >> n;
        v = VI(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        final = false;
        VI s;
        cout << "Case #" << cas << ":" << endl;
        rec(0, s, 0);
        if (not final) cout << "Impossible" << endl;
    }
}
