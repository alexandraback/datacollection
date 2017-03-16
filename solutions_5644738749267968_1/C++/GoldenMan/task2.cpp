#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solve1(int n, vector<long double> &a, vector<long double> &b) {
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long double cur = b[i];
        int k = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            if (a[j] > cur) {
                k = j;
                break;
            }
        }
        if (k == -1) {
            ++ans;
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                k = j;
                break;
            }
        }
        used[k] = true;
    }
    return ans;
}

int solve2(int n, vector<long double> &a, vector<long double> &b) {
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long double cur = b[n - i - 1];
        int k = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            if (a[j] > cur) {
                k = j;
                break;
            }
        }
        if (k == -1) {
            ++ans;
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                k = j;
                break;
            }
        }
        used[k] = true;
    }
    return ans;
}

int solve_perm(int n, vector<long double> &a, vector<long double> &b, vector<int> &perm) {
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long double cur = b[perm[i]];
        int k = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            if (a[j] > cur) {
                k = j;
                break;
            }
        }
        if (k == -1) {
            ++ans;
            for (int j = 0; j < n; ++j) {
                if (used[j]) continue;
                k = j;
                break;
            }
        }
        used[k] = true;
    }
    return ans;
}

bool is_natural(int n, vector<int> &perm) {
    for (int i = 0; i < n; ++i) {
        if (perm[i] != i) {
            return false;
        }
    }
    return true;
}

int solve3(int n, vector<long double> &a, vector<long double> &b) {
    vector<int> perm;
    for (int i = 0; i < n; ++i) {
        perm.push_back(i);
    }
    int ans = solve_perm(n, a, b, perm);
    do {
        next_permutation(perm.begin(), perm.end());
        int cur = solve_perm(n, a, b, perm);
        if (cur > ans) {
            ans = cur;
        }
    } while (!is_natural(n, perm));
    return ans;
}

void solve(int t) {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;
    vector<long double> a;
    vector<long double> b;
    for (int i = 0; i < n; ++i) {
        long double x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        long double x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int p1 = 0;
    int p2 = 0;
    while (true) {
        while (b[p2] < a[p1] && p2 + 1 < n) ++p2;
        if (b[p2] < a[p1]) {
            break;
        }
        ++ans;
        ++p1;
        ++p2;
        if (p1 >= n || p2 >= n) {
            break;
        }
    }
    int s1 = solve1(n, a, b);
    int s2 = solve2(n, a, b);
    //int s3 = solve3(n, a, b);
    cout << ans << " ";
    //cout << solve1(n, a, b) << " ";
    //cout << solve2(n, a, b) << " ";
    //cout << solve3(n, a, b) << " ";
    cout << max(s1, s2) << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
        cerr << "Test #" << i + 1 << " solved." << endl;
    }
    return 0;
}

