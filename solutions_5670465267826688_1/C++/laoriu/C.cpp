#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 10;

int f[MAXN];
int nxt[MAXN][20], prv[MAXN][20];
bool ok[MAXN];

int tab[5][5] = {{},
                {0, 1, 2, 3, 4},
                {0, 2, -1, 4, -3},
                {0, 3, -4, -1, 2},
                {0, 4, 3, -2, -1}};


void convert_to_num(string &s) {
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == 'i') s[i] = '2';
        else if (s[i] == 'j') s[i] = '3';
        else if (s[i] == 'k') s[i] = '4';
    }
}

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int power(int x, long long k) {
    if (k == 1) return x;
    if (x == 1) return 1;
    if (x == -1) return ((k % 2 == 0) ? 1 : -1);
    if (power(-1, k / 2) == 1) {
        if (k % 2 == 0) return 1;
        else return x;
    }
    else {
        if (k % 2 == 0) return -1;
        else return -x;
    }
}

int mul(int x, int y) {
    return sign(x) * sign(y) * tab[abs(x)][abs(y)];
}

int find_num(int a, int c) {
    for(int b = -4; b <= 4; b++) {
        if (b != 0) {
            if (mul(a, b) == c) return b;
        }
    }
    return 0;
}

string calc(string &seed, int L, long long X) {
    f[0] = 1;
    for(int i = 1; i <= L; i++) {
        int j = seed[i - 1] - '0';
        f[i] = mul(f[i - 1], j);
    }
    if (power(f[L], X) != -1) return "NO";
    int delta = 4;
    for(int j = 0; j <= 4 + delta; j++) nxt[L + 1][j] = L + 1;
    for(int i = L; i >= 1; i--) {
        for(int j = 0; j <= 4 + delta; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][f[i] + delta] = i;
    }
    for(int j = 0; j <= 4 + delta; j++) prv[0][j] = 0;
    for(int i = 1; i <= L; i++) {
        for(int j = 0; j <= 4 + delta; j++) prv[i][j] = prv[i - 1][j];
        prv[i][f[i] + delta] = i;
    }
    //cout << prv[L][4 + delta] << endl;
    int x = 1;
    long long pos2 = X * L + 1;
    for(int i = 0; i < min(5LL, X); i++) {
        int y = find_num(x, 2);
        if (((y != 0) && (nxt[1][y + delta] <= L)) || (pos2 <= X * L)) {
            pos2 = min(pos2, 1LL * L * i + nxt[1][y + delta]);
            int z = find_num(x, 4);
            //cout << y << " " << z << endl;
            //cout << nxt[1][y + delta] << " " <<
            if (z != 0) {
                if (i + 1 < X) {
                    if (prv[L - 1][z + delta] > 0) return "YES";
                    if ((i + 1 == X) && (prv[L][z + delta] > nxt[1][y + delta])) return "YES";
                    if ((i + 1 < X) && (prv[L][z + delta] > 0)) return "YES";
                }
                else {
                    if (prv[L - 1][z + delta] > nxt[1][y + delta]) return "YES";
                }
            }
        }
        x = mul(x, f[L]);
    }
    return "NO";
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        int L; long long X;
        cin >> L >> X;
        string seed;
        cin >> seed;
        convert_to_num(seed);
        string result = calc(seed, L, X);
        cout << "Case #" << tc << ": " << result << endl;
    }
}
