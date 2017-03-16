#include <fstream>
#include <string>

using namespace std;

const int MAXN = 10 * 1000 + 5, D = 4;
char c[MAXN][2 * D + 1][2 * D + 1], c2[2 * D + 1][2 * D + 1],
    c3[2 * D + 1][2 * D + 1][2 * D + 1];
int a[MAXN],
    mt[D + 1][D + 1] = {{0, 0, 0, 0, 0},
                        {0, 1, 2, 3, 4},
                        {0, 2, -1, 4, -3},
                        {0, 3, -4, -1, 2},
                        {0, 4, 3, -2, -1}};

inline int mul(int x, int y) {
    int neg = 1;
    if(x < 0) {
        x *= -1;
        neg *= -1;
    }
    if(y < 0) {
        y *= -1;
        neg *= -1;
    }
    return neg * mt[x][y];
}

bool stupid(int n, long long x, string s) {
    string t = s;
    for(int i = 1; i < x; i++)
        s += t;
    n *= x;
    for(int i = 0; i < n; i++)
        a[i] = (s[i] == 'i'? 2 : (s[i] == 'j'? 3 : 4));
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 2 * D; j++)
            for(int k = 0; k <= 2 * D; k++)
                c[i][j][k] = false;
    for(int i = 0; i <= 2 * D; i++)
        for(int j = 0; j <= 2 * D; j++)
            c2[i][j] = false;
    int m = 1;
    for(int i = n; i >= 0; i--) {
        int mm = 1;
        for(int j = i; j >= 0; j--) {
            c[j][D + mm][D + m] = true;
            if(j == 0)
                c2[D + mm][D + m] = true;
            else
                mm = mul(a[j - 1], mm);
        }
        if(i)
            m = mul(a[i - 1], m);
    }
    for(int i = 0; i <= 2 * D; i++)
        for(int j = 0; j <= 2 * D; j++)
            for(int k = 0; k <= 2 * D; k++)
                c3[i][j][k] = false;
    m = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 2 * D; j++)
            for(int k = 0; k <= 2 * D; k++)
                if(c[i][j][k])
                    c3[D + m][j][k] = true;
        if(i < n)
            m = mul(m, a[i]);
    }
    return c3[D + 2][D + 3][D + 4];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int n;
        long long x;
        string s;
        in >> n >> x >> s;
        for(int i = 0; i < n; i++)
            a[i] = (s[i] == 'i'? 2 : (s[i] == 'j'? 3 : 4));
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= 2 * D; j++)
                for(int k = 0; k <= 2 * D; k++)
                    c[i][j][k] = false;
        for(int i = 0; i <= 2 * D; i++)
            for(int j = 0; j <= 2 * D; j++)
                c2[i][j] = false;
        int m = 1;
        for(int i = n; i >= 0; i--) {
            int mm = 1;
            for(int j = i; j >= 0; j--) {
                c[j][D + mm][D + m] = true;
                if(j == 0)
                    c2[D + mm][D + m] = true;
                else
                    mm = mul(a[j - 1], mm);
            }
            if(i)
                m = mul(a[i - 1], m);
        }
        for(int i = 0; i <= 2 * D; i++)
            for(int j = 0; j <= 2 * D; j++)
                for(int k = 0; k <= 2 * D; k++)
                    c3[i][j][k] = false;
        m = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= 2 * D; j++)
                for(int k = 0; k <= 2 * D; k++)
                    if(c[i][j][k])
                        c3[D + m][j][k] = true;
            if(i < n)
                m = mul(m, a[i]);
        }
        bool ans = false;
        for(int l = 0, lm = 1; l < 4; l++, lm = mul(lm, m))
            for(int r = 0, rm = 1; r < 4; r++, rm = mul(rm, m)) {
                if((l + r + 1) % 4 == x % 4 && l + r + 1 <= x) {
                    for(int i = -D; i <= D; i++)
                        for(int j = -D; j <= D; j++)
                            if(c3[D + i][D + 3][D + j] && mul(lm, i) == 2 &&
                               mul(j, rm) == 4)
                                ans = true;
                }
                for(int mid = 0, midm = 1; mid < 4; mid++, midm = mul(midm, m))
                    if((l + mid + r + 2) % 4 == x % 4 && l + mid + r + 2 <= x)
                        for(int i = -D; i <= D; i++)
                            for(int j = -D; j <= D; j++)
                                if(c2[D + i][D + j] && mul(lm, i) == 2)
                                    for(int k = -D; k <= D; k++)
                                        for(int ii = -D; ii <= D; ii++)
                                            if(c2[D + k][D + ii] &&
                                               mul(j, mul(midm, k)) == 3 &&
                                               mul(ii, rm) == 4)
                                                ans = true;
            }
        out << "Case #" << tt + 1 << ": " << (ans? "YES" : "NO") << '\n';
    }
    return 0;
}
