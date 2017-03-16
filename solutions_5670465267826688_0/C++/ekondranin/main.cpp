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

int get_i(char c)
{
    if (c == 'i') {
        return 1;
    }
    if (c == 'j') {
        return 2;
    }
    return 3;
}

vector <vector <pair <char, char>>> v(10000, vector <pair <char, char>> (10000));

int main()
{
    int t;
    cin >> t;//1 = 0, i = 1, j = 2, k = 3;
    vector <vector <pair <char, char>>> a = {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                               {{1, 0}, {0, 1}, {3, 0}, {2, 1}},
                               {{2, 0}, {3, 1}, {0, 1}, {1, 0}},
                               {{3, 0}, {2, 0}, {1, 1}, {0, 1}}};
    FOR (l1, 0, t) {
        int x, l;
        cin >> x >> l;
        string st;
        cin >> st;
        string s;
        FOR (i, 0, l) {
            s += st;
        }
        FOR (i, 0, s.size()) {
            pair <char, char> t = {get_i(s[i]), 0};
            v[i][i] = t;
            FOR (j, i + 1, s.size()) {
                pair <char, char> x = a[t.first][get_i(s[j])];
                t = {x.first, (x.second + t.second) % 2};
                v[i][j] = t;
            }
        }
        FOR (i, 1, s.size() - 1) {
            FOR (j, i + 1, s.size()) {
                if (v[0][i - 1] == make_pair((char)1, (char)0) && v[i][j - 1] == make_pair((char)2, (char)0) && v[j][s.size() - 1] == make_pair((char)3, (char)0)) {
                    cout << "Case #" << l1 + 1 << ": YES" << endl;
                    goto NEXT;
                }
            }
        }
        cout << "Case #" << l1 + 1 << ": NO" << endl;
NEXT:;
    }
}
