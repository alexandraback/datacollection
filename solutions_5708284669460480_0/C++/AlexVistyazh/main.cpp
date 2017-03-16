#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

bool d[111][111][111];


double f[111][111][111];
int p[111], goo[111][26];

void calcP(string s, int N) {
    s = "#" + s;
    p[1] = 0;
    for (int i = 2; i <= N; i++) {
        int v = p[i - 1];
        while (v != 0 && s[v + 1] != s[i]) v = p[v];
        if (s[v + 1] == s[i]) p[i] = v + 1;
        else p[i] = v;
    }
    for (int i = 0; i <= N; i++) {
        for (char c = 'A'; c <= 'Z'; c++) {
            int v = i;
            while (v > 0 && (v + 1 > N || s[v + 1] != c)) v = p[v];
            if (s[v + 1] == c) v++;
            goo[i][int(c - 'A')] = v;
        }
    }
}

int go(int v, int c) {
    return goo[v][c];
}

int foo(int K, int L, int S, string alpha, string need) {
    memset(d, 0, sizeof(d));
    d[0][0][0] = true;
    for (int len = 0; len < S; len++) {
        for (int v = 0; v <= L; v++) {
            for (int cnt = 0; cnt <= len; cnt++) {
                for (int it = 0; it < K; it++) {
                    int c = alpha[it] - 'A';
                    int nv = go(v, c);
                    d[len + 1][nv][cnt + (nv == L ? 1 : 0)] |= d[len][v][cnt];
                }
            }
        }
    }
    int result = 0;
    for (int v = 0; v <= L; v++)
        for (int cnt = 0; cnt <= S; cnt++)
            if (d[S][v][cnt] && cnt > result) result = cnt;
    return result;
}

double solve(int K, int L, int S, string alpha, string need) {
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int len = 0; len < S; len++) {
        for (int v = 0; v <= L; v++) {
            for (int cnt = 0; cnt <= len; cnt++) {
                double koef = double(1) / K;
                for (int it = 0; it < K; it++) {
                    int c = alpha[it] - 'A';
                    int nv = go(v, c);
                    f[len + 1][nv][cnt + (nv == L ? 1 : 0)] += f[len][v][cnt] * koef;
                }
            }
        }
    }
    double result = 0;
    for (int v = 0; v <= L; v++)
        for (int cnt = 0; cnt <= S; cnt++)
            result += f[S][v][cnt] * cnt;
    return result;
}

void solve(int tc) {
    int K, L, S;
    cin >> K >> L >> S;
    string alpha, need;
    cin >> alpha;
    cin >> need;
    cout << "Case #" << tc << ": ";
    calcP(need, L);
    double z = foo(K, L, S, alpha, need) - solve(K, L, S, alpha, need);
    printf("%.9f\n", z);
}

int main () {
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    int T;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
