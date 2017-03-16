#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;
const int INF = (int)(1e9);
const int MOD = (int)(1e9) + 7;

int freq[30];
int K, L, S;
string kb, sb;
int nxt[MAXN];
double f[MAXN][MAXN][MAXN];

void init() {
    cin >> K >> L >> S;
    cin >> kb; cin >> sb;
    for(int i = 0; i < 26; i++) freq[i] = 0;
    for(int i = 0; i < kb.size(); i++) {
        freq[kb[i] - 'A']++;
    }

    nxt[0] = 0;
    int j = 0;
    for(int i = 1; i < L; i++) {
        while ((j > 0) && (sb[i] != sb[j])) j = nxt[j - 1];
        if (sb[i] == sb[j]) j++;
        nxt[i] = j;
    }
}

double prob(int x) {
    return 1.0 * freq[x] / K;
}

void add(double &a, double b) {
    a += b;
}

double solve() {
    init();

    for(int i = 0; i <= S; i++) {
        for(int j = 0; j <= L; j++) {
            for(int k = 0; k <= S; k++) {
                f[i][j][k] = 0.0;
            }
        }
    }

    f[0][0][0] = 1.0;
    for(int i = 0; i < S; i++) {
        for(int j = 0; j < L; j++) {
            for(int k = 0; k <= i; k++) {
                //if (f[i][j][k] > 0.0) cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
                for(int t = 0; t < 26; t++) {
                    int jj = (j < L) ? j : nxt[j - 1];
                    while ((jj > 0) && (t != sb[jj] - 'A')) jj = nxt[jj - 1];
                    if (t == sb[jj] - 'A') jj++;
                    //if (jj == 1) cout << t << " " << prob(t) << endl;
                    add(f[i + 1][((jj < L) ? jj : nxt[jj - 1])][k + (jj == L)], f[i][j][k] * prob(t));
                }
            }
        }
    }

    int b = 0;
    for(int j = 0; j < L; j++) {
        for(int k = 0; k <= S; k++) {
            if (f[S][j][k] > 0.0) {
                b = max(b, k);
                //cout << f[S][j][k] << endl;
            }
        }
    }
    double res = 0.0;
    for(int j = 0; j < L; j++) {
        for(int k = 0; k <= b; k++) {
            res += f[S][j][k] * (b - k);
        }
    }
    return res;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        printf("Case #%d: %.07lf\n", tc, solve());
    }
}

