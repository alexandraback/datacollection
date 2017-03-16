#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 1e6 + 5;

int t, n;
bool used[MAXN];

LL rev(LL num) {
    vector <int> v;
    while (num) {
        v.puba(num % 10);
        num /= 10;
    }
    LL ret = 0;
    for (int i = 0; i < szof(v); ++i) {
        ret = ret * 10 + v[i];
    }
    return ret;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;
        memset(used, 0, sizeof used);
        queue <pii > q;
        q.push(mapa(1, 1));
        used[1] = true;
        while (szof(q)) {
            pii p = q.front();
            q.pop();
            if (p.ff == n) {
                cout << "Case #" << i + 1 << ": " << p.ss << endl;
                break;
            }
            if (!used[p.ff + 1]) {
                q.push(mapa(p.ff + 1, p.ss + 1));
                used[p.ff + 1] = true;
            }
            int tmp = rev(p.ff);
            if (!used[tmp]) {
                q.push(mapa(tmp, p.ss + 1));
                used[tmp] = true;
            }
        }
    }

    return 0;
}