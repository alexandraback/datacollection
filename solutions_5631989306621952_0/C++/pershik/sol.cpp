#include <bits/stdc++.h>

#define NAME "test"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long li;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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

const int MAXN = 1010;
const int ALPHA = 26;

bool used[MAXN];
char res[MAXN];
int cnt[ALPHA];

void solve(int test_number) {
    string s;
    cin >> s;
    int n = s.length();
    memset(used, 0, sizeof(used));
    memset(cnt, 0, sizeof(cnt));
    for (char c : s) {
        cnt[c - 'A']++;
    }
    
    int l = 0, r = n - 1;
    while (l <= r) {
        for (int c = ALPHA - 1; c >= 0; c--) {
            if (cnt[c]) {
                //cerr << c << endl;
                //cerr << l << ' ' << r << endl;
                for (int j = n - 1; j >= 0; j--) {
                    if (!used[j] && s[j] - 'A' == c) {
                        res[l] = s[j];
                        cnt[s[j] - 'A']--;
                        used[j] = true;
                        l++;
                        for (int k = n - 1; k >= j; k--) {
                            if (!used[k]) {
                                res[r--] = s[k];
                                cnt[s[k] - 'A']--;
                                used[k] = true;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    cout << "Case #" << test_number << ": ";
    for (int i = 0; i < n; i++) 
        cout << res[i];
    cout << endl;
}

