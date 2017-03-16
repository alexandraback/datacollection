// In the Name of Allah
// AD13

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/

int b, m;
bool edge[10][10];
bool way[10][10];

bool hasLoop() {
    For (i, b) For (j, b) way[i][j] = edge[i][j];

    bool change = true;
    while (change) {
        change = false;
        For (i, b - 1) For(j, b - 1) For (k, b - 1) {
            if (way[i][j] && way[j][k] && way[i][k] == false) {
                change = true;
                way[i][k] = true;
            }
        }
    }
    For (i, b - 1) For (j, b - 1)
        if (way[i][j] && way[j][i]) return true;

    return false;
}

int cntWays(int ind = 0) {
    if (ind == b - 1) return 1;

    int cnt = 0;
    For (i, b) if (edge[ind][i]) {
        cnt += cntWays(i);
    }

    return cnt;
}

bool f (int r, int c) {
    if (hasLoop() == true) return false;
    if (r == b - 1) return cntWays() == m;

    if (c == b) return f(r + 1, 0);

    if (f(r, c + 1)) return true;
    if (r != c) {
        edge[r][c] = true;
        if (f(r, c + 1)) return true;
        edge[r][c] = false;
    }

    return false;
}

/*_____________________________________________________________________________________*/

// check debug, read 2 times (until full!)
// think --> idea? --> really works?

int main() {
    //*
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    //*/
    int T;
    cin >> T;
    For1 (tc, T) {
        cerr << "--> " << tc << " / " << T << endl;

        cin >> b >> m;
        For (i, b) For(j, b) edge[i][j] = false;

        bool pos = f(0, 0);

        cout << "Case #" << tc << ": " << (pos ? "POSSIBLE" : "IMPOSSIBLE");
        if (pos) {
            For (i, b) {
                cout << endl;
                For (j, b) cout << (edge[i][j] ? 1 : 0);
            }
        }
        cout << endl;
    }

    return 0;
}
/*

*/
