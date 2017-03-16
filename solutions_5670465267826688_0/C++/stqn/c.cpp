#include <bits/stdc++.h>
using namespace std;

const int table[8][8] = {
    /* 1  i  j  k -1 -i -j -k */
    {  0, 1, 2, 3, 4, 5, 6, 7},
    {  1, 4, 3, 6, 5, 0, 7, 2},
    {  2, 7, 4, 1, 6, 3, 0, 5},
    {  3, 2, 5, 4, 7, 6, 1, 0},
    {  4, 5, 6, 7, 0, 1, 2, 3},
    {  5, 0, 7, 2, 1, 4, 3, 6},
    {  6, 3, 0, 5, 2, 7, 4, 1},
    {  7, 6, 1, 0, 3, 2, 5, 4},
};
inline int ord(char c) { return c - 'i' + 1; }
inline int mul(int a, int b) { return table[a][b]; }
int pow(int a, int n) {
    int ret = 0;
    for (n &= 3; n--; ) ret = mul(ret, a);
    return ret;
}

int n, m;
string s;

void input()
{
    cin >> n >> m >> s;
}

bool check_product()
{
    int prod = 0;
    for (int i = 0; i < n; ++i) {
        prod = mul(prod, ord(s[i]));
    }
    return pow(prod, m) == 4;
}

int len_prefix()
{
    int prod = 0;
    for (int i = 0; i < 4 * n; ++i) {
        if (prod == 1) return i;
        prod = mul(prod, ord(s[i % n]));
    }
    return -1;
}

int len_suffix()
{
    int prod = 0;
    for (int i = 0; i < 4 * n; ++i) {
        if (prod == 3) return i;
        prod = mul(ord(s[n - i % n - 1]), prod);
    }
    return -1;
}

bool solve()
{
    if (!check_product()) return false;
    const int a = len_prefix();
    const int b = len_suffix();
    return a != -1 and b != -1 and a + b < n * m;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        input();
        cout << "Case #" << i << ": "
             << (solve() ? "YES" : "NO")
             << endl;
    }
}
