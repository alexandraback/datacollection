#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
}

bool u[200];
int a[60][60];
vector<int> b[200];
bool l[200];
bool r[200];
bool ps[60];
int n;

bool check(int cn) {
    int c = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (u[i]) {
            for (int j = 0; j < n; ++j) {
                a[c][j] = b[i][j];
            }
            c++;
        }
    }
    for (int i = 0; i < cn; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i][j] == a[i][k]) return false;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cn; ++j) {
            for (int k = j + 1; k < cn; ++k) {
                if (a[j][i] == a[k][i]) return false;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        l[i] = r[i] = false;
    c = 0;
    for (int i = 0; i < n; ++i) {
        while ((c < 2 * n - 1) && (u[c])) c++;
        while (!l[i]) {
            if (c >= 2 * n - 1) break;
            if (u[c]) {
                c++;
                continue;
            }
            l[i] = true;
            for (int j = 0; j < cn; ++j) {
                if (a[j][i] != b[c][j]) l[i] = false;
            }
            if (!l[i]) c++;
        }
        if (!l[i]) break;
    }
    c = 2 * n - 2;
    for (int i = n - 1; i >= 0; --i) {
        while ((c >= 0) && (u[c])) --c;
        while (!r[i]) {
            if (c < 0) break;
            if (u[c]) {
                c--;
                continue;
            }
            r[i] = true;
            for (int j = 0; j < cn; ++j) {
                if (a[j][i] != b[c][j]) r[i] = false;
            }
            if (!r[i]) c--;
        }
        if (!r[i]) break;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (l[i - 1] && r[i + 1]) return true;
    }
    if (r[1]) return true;
    if (l[n - 2]) return true;
    return false;
}


bool gen(int c, int x) {

    if (c == n) {
        check(c);
        int an = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (l[i - 1] &&  r[i + 1]) {
                an = i;
            }
        }
        if (r[1]) {
            an = 0;
        }
        if (l[n - 2])
            an = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i][an] > a[i + 1][an]) return false;
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i][an] << " ";
        }
        cout << endl;
        return true;
    }
    if (x == 2 * n - 1) return false;
    u[x] = true;
    if (check(c + 1)) {
        if (gen(c + 1, x + 1)) return true;
    }
    u[x] = false;
    return gen(c, x + 1);
}

int solve() {
    cin >> n;
    for (int i = 0; i < 2 * n - 1; ++i) {
        u[i] = false;
        b[i].resize(n);
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    }
    sort(b, b + 2 * n - 1, cmp);
    gen(0, 0);
}

int main(void) {
    int T;
    cin >> T;
   
    for (int t = 1; t <= T; ++t) {
        cerr << t << endl;
        printf("Case #%d: ", t);
        solve();
    }
}
