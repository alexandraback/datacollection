#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#define NAME "test-large"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define ve vector<int>
#define pb push_back

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define fs first
#define sc second

using namespace std;

typedef long long li;
typedef long long ll;
typedef long long lint;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#else
#endif
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

const int MAXN = 110;

string keys;
string s;
int n, m, len;
int overlap;
int overlaps[MAXN][MAXN];

int get_overlap(string s, string x) {
    int res = 0;
    for (int i = 0; i <= (int)x.length(); i++) {
        if ((int)s.length() < i) {
            break;
        }
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (x[j] != s[s.length() - i + j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            res = i;
    }
    //cout << s << ' ' << x << ' '<< res << endl;
    return res;
}

double dp[MAXN][MAXN][MAXN];
set<char> letters;

void solve(int test_number) {
    letters.clear();
    cin >> n >> m >> len;
    cin >> keys >> s;
    for (int i = 0; i < n; i++)
        letters.insert(keys[i]);
    for (int i = 0; i < m; i++)
        if (letters.count(s[i]) == 0) {
            cout << "Case #" << test_number << ": " << 0 << endl;
            return;
        }

    overlap = 0;
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) 
            if (s[j] != s[m - i + j])
                flag = false;
        if (flag)
            overlap = i;
    }
    if (overlap == m)
        overlap--;

    string ss = "";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            overlaps[i][j] = get_overlap(ss + keys[j], s);
        }
        if (i != m)
            ss += s[i];
    }


    double taken = 0;
    int cur = s.length();
    while (cur <= len) {
        taken += 1;
        cur += (m - overlap);
    }
    //cout << "taken = " << taken << endl;

    //for (int i = 0; i <= m; i++) {
        //for (int j = 0; j < n; j++)
            //cout << overlaps[i][j] << ' ';
        //cout << endl;
    //}
    
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            for (int ov = 0; ov <= m; ov++) {
                if (dp[i][j][ov] < EPS)
                    continue;
                for (int k = 0; k < n; k++) {
                    int new_ov = overlaps[ov][k];
                    if (new_ov == m) {
                        dp[i + 1][j + 1][new_ov] += (dp[i][j][ov] / n);
                    } else {
                        dp[i + 1][j][new_ov] += (dp[i][j][ov] / n);
                    }
                }   
            }
        }
    }

    //for (int i = 0; i <= len; i++) {

    //for (int j = 0; j <= len; j++) {
        //for (int ov = 0; ov <= m; ov++) {
            //cout << dp[i][j][ov] << ' ';
        //}
        //cout << endl;
    //}

    //cout << endl;
    //}
    double res = 0;
    for (int j = 0; j <= len; j++) {
        for (int ov = 0; ov <= m; ov++) {
            res += dp[len][j][ov] * j;
        }
    }
    cout << "Case #" << test_number << ": " << taken - res << endl;

}

