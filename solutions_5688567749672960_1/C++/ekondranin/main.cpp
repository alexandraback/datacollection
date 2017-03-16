#include <bits/stdc++.h>
#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int i = 0; i < (n); ++i) cin >> a[i];
#define GETM(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
#define PRINTM(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < m; ++j) cout << a[i][j] << " ";  cout << endl; };
#define PRINT(a, n) for (int i = 0; i < (n); ++i) cout << a[i] << " ";
#define IT(a) a.begin(), a.end()
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
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

#define int LL

vector <int> to_arr(int num) {
    vector <int> ans;
    while (num > 0) {
        ans.push_back(num % 10);
        num /= 10;
    }
    return ans;
}

LL to_num(const vector <int> &num) {
    LL res = 0;
    FOR (i, 0, num.size()) {
        res *= 10;
        res += num[i];
    }
    return res;
}

LL get_res(LL n)
{
    if (1 <= n && n <= 9) {
        return n;
    }
    vector <int> c = to_arr(n);
    reverse(IT(c));
    vector <int> a;
    vector <int> b;
    FOR (i, 0, int(c.size()) / 2) {
        a.push_back(c[i]);
    }
    FOR (i, int(c.size()) / 2, int(c.size())) {
        b.push_back(c[i]);
    }
    LL res = 0;
    reverse(IT(a));
    LL a1 = to_num(a);
    LL a2 = to_num(b);
    res = a1 - 1 + a2 - 1;
    vector <int> d = vector <int> (c.size() - 1, 9);
    LL x = to_num(d);
    return get_res(x) + res + 3 - (a1 == 1);
}

signed main()
{
    int t;
    cin >> t;
    FOR (i, 0, t) {
        LL n;
        cin >> n;
        LL x = 0;
        if (n % 10 == 0) {
            ++x;
            --n;
        }
        x += get_res(n);
        CASE(i + 1, x);
    }
}
