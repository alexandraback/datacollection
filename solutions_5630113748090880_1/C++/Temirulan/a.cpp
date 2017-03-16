#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int T;
int n;
vector <vector <int> > a;
int dp[105][105][55];
int ans[155][155];
int big[155][155];
bool used[155];

bool is_strictly_bigger(vector <int> &a, vector <int> &b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] <= b[i]) return false;
    return true;
}

void fill(int row, int ind) {
    for (int i = 0; i < n; i++)
        ans[row][i] = a[ind][i];
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i && ans[i - 1][j] >= ans[i][j]) return false;
            if (j && ans[i][j - 1] >= ans[i][j]) return false;
        }
    return true;
}

int calc(int ind, int last, int cnt) {
    if (cnt == n) return 1;
    if (ind >= a.size()) return 0;
    int &res = dp[ind][last][cnt];
    if (res != -1) return res;
    res = calc(ind + 1, last, cnt);
    if (big[ind][last]) res |= calc(ind + 1, ind, cnt + 1);
    return res;
}

void rec(int ind, int last, int cnt) {
    if (cnt == n) return;
    assert(ind < a.size());
    if (calc(ind + 1, last, cnt)) rec(ind + 1, last, cnt);
    else {
        fill(cnt, ind);
        used[ind] = 1;
        rec(ind + 1, ind, cnt + 1);
    }
}

void solve(int case_num) {
    cin >> n;
    vector <int> cnt(2555, 0);
    for (int i = 0; i < 2 * n - 1; i++) {
        int x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            cnt[x]++;
        }
    }
    printf("Case #%d:", case_num);
    int res = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i]&1) printf(" %d", i);
        res += cnt[i]%2;
    }
    printf("\n");
    assert(res == n);
}

int main(){

    int T;

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) solve(i);

    return 0;
}
