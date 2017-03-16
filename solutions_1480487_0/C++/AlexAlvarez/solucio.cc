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
typedef long double ld;
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
typedef vector<ld> VD;
typedef vector<VD> VVD;
const int INF = 1000000000;
const ld EPS = 1e-10;


bool can(int p, VI& v, ld m, int sum) {
    ld points = ld(v[p]) + ld(sum)*m;
    ld rest = 1.0 - m;
    for (int i = 0; i < v.size(); ++i) {
        if (i == p) continue;
        ld need = max((points - ld(v[i]))/ld(sum), ld(0.0));
        rest -= need;
    }
    return rest > -EPS;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    int casos;
    cin >> casos;
    for (int cas = 1; cas <= casos; ++cas) {
        int n, sum = 0;
        cin >> n;
        VI v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        cout << "Case #" << cas << ":";
        for (int i = 0; i < n; ++i) {
            ld ini = 0.0, fin = 1.0;
            while (fabs(fin - ini) > EPS) {
                ld m = (ini + fin)/2.0;
                if (can(i, v, m, sum)) ini = m;
                else fin = m;
            }
            cout << " " << ini*100.0;
        }
        cout << endl;
    }
}
