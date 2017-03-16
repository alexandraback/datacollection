#include <bits/stdc++.h>
#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int i = 0; i < (n); ++i) cin >> a[i];
#define GETM(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
#define PRINTM(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < m; ++j) cout << a[i][j] << " ";  cout << endl; };
#define PRINT(a, n) for (int i = 0; i < (n); ++i) cout << a[i] << " ";
#define IT(a) a.begin(), a.end()
#define DEB(a) cout << #a << " = " << a << endl; cout.flush();
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

int main()
{
    vector <vector <vector <int>>> ans = {{{1, 1, 1, 1},//k = 1
                                            {1, 1, 1, 1},
                                            {1, 1, 1, 1},
                                            {1, 1, 1, 1}},
                                           {{0, 1, 0, 1},//k = 2
                                            {1, 1, 1, 1},
                                            {0, 1, 0, 1},
                                            {1, 1, 1, 1}},
                                           {{0, 0, 0, 0},//k = 3
                                            {0, 0, 1, 0},
                                            {0, 1, 1, 1},
                                            {0, 0, 1, 0}},
                                           {{0, 0, 0, 0},//k = 4
                                            {0, 0, 0, 0},
                                            {0, 0, 0, 1},
                                            {0, 0, 1, 1}}};
    int t;
    cin >> t;
    FOR (i, 0, t) {
        int x, r, c;
        cin >> x >> r >> c;//0 - first, 1 - second
        --x; --r; --c;
        if (ans[x][r][c] == 1) {
            cout << "Case #" << i + 1 << ": GABRIEL" << endl;
        } else {
            cout << "Case #" << i + 1 << ": RICHARD" << endl;
        }
    }
    return 0;
}
