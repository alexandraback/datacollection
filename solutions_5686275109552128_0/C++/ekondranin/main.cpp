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
#define DEBA(a) for (auto i: a) cout << i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

double
get_rand(int low, int high) {
    return rand()/(RAND_MAX + 1.0) * (high - low) + low;
}


int main()
{
    int t;
    cin >> t;
    FOR (l, 0, t) {
        int n;
        cin >> n;
        multiset <int> s;
        multiset <int> old_s;
        FOR (i, 0, n) {
            int a;
            cin >> a;
            s.insert(a);
        }
        old_s = s;
        FOR (k, 1, 10) {
            FOR (l3, 0, k) {
                s = old_s;
                int k2 = k - 1;
                int l2 = l3;
                while (1) {
                    if (k2 == -1) {
                        break;
                    }
                    if (*s.rbegin() <= k2 + 1) {
                        cout << "Case #" << l + 1 << ": " << k << endl;
                        //cout << l3 << endl;
                        goto NEXT;
                    } else {
                        int t = *s.rbegin();
                        s.erase(s.find(t));
                        int x = k2 - l2;
                        if (t - x != 0) {
                            s.insert(t - x);
                        }
                        if (x != 0) {
                            s.insert(x);
                        }
                    }
                    --k2;
                    --l2;
                }
            }
        }
NEXT:;
    }
}
