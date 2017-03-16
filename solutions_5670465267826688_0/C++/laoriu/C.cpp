#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 10;

int f[MAXN];
bool ok[MAXN];

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

int main()
{
    int tab[5][5] = {{},
                    {0, 1, 2, 3, 4},
                    {0, 2, -1, 4, -3},
                    {0, 3, -4, -1, 2},
                    {0, 4, 3, -2, -1}};

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        int L, X;
        cin >> L >> X;
        string seed;
        cin >> seed;
        convert_to_num(seed);
        string s = "";
        for(int i = 0; i < X; i++) s += seed;
        int n = s.length();
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            int j = s[i - 1] - '0';
            f[i] = sign(f[i - 1]) * tab[abs(f[i - 1])][j];
            //cout << i << " " << f[i] << endl;
        }
        for(int i = 0; i <= n; i++) ok[i] = false;
        bool ok_i = (f[1] == 2);
        for(int i = 2; i <= n; i++) {
            ok[i] = ok[i - 1] | ((f[i] == 4) && (ok_i));
            ok_i = ok_i | (f[i] == 2);
        }
        string result = ((f[n] == -1) && (ok[n - 1])) ? "YES" : "NO";
        cout << "Case #" << tc << ": " << result << endl;
    }
}
