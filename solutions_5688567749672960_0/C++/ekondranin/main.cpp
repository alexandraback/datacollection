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

vector <int> to_arr(int num) {
    vector <int> ans;
    while (num > 0) {
        ans.push_back(num % 10);
        num /= 10;
    }
    return ans;
}

int to_num(const vector <int> &num) {
    int res = 0;
    FOR (i, 0, num.size()) {
        res *= 10;
        res += num[i];
    }
    return res;
}

int main()
{
    const int C = 1000002;
    vector <int> dp(C, 0);
    dp[1] = 1;
    FOR (i, 1, C) {
        vector <int> v = to_arr(i);
        //reverse(IT(v));
        dp[i] = dp[i - 1] + 1;
        if (v[0] == 0) {
            continue;
        }
        int x = to_num(v);
        if (x >= i) {
            continue;
        }
        dp[i] = min(dp[i], dp[x] + 1);
    }
    FOR (i, 0, C) {
     //   cout << dp[i] << endl;
    }
    int t;
    cin >> t;
    FOR (i, 0, t) {
        LL n;
        cin >> n;
        CASE(i + 1, dp[n]);
    }
}
