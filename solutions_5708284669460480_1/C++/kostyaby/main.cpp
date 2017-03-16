#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXL = 222;

struct Node {
    int go[26];
    int link;
    int c;
    int prev;
    int flag;

    Node() {
        memset(go, -1, sizeof(go) );
        link = c = prev = -1;
        flag = 0;
    }
};

Node tree[MAXL];
int n;
int k, l, s;
string a, b;

long double f[MAXL][MAXL][MAXL];
bool h[MAXL][MAXL][MAXL];

int get_link(int);

int go(int v, int c) {
    if (tree[v].go[c] != -1) {
        return tree[v].go[c];
    }

    if (v == 0) {
        return tree[v].go[c] = 0;
    }

    return tree[v].go[c] = go(get_link(v), c);
}

int get_link(int v) {
    if (tree[v].link != -1) {
        return tree[v].link;
    }

    if (v == 0 || tree[v].prev == 0) {
        return tree[v].link = 0;
    }

    return tree[v].link = go(get_link(tree[v].prev), tree[v].c);
}

long double solve() {
    cin >> k >> l >> s;

    n = 1;
    for (int i = 0; i < MAXL; i++) {
        tree[i] = Node();
    }
    for (int i = 0; i < MAXL; i++) {
        for (int j = 0; j < MAXL; j++) {
            for (int k = 0; k < MAXL; k++) {
                f[i][j][k] = 0.0;
                h[i][j][k] = false;
            }
        }
    }

    cin >> a >> b;

    int v = 0;
    for (int i = 0; i < l; i++) {
        int c = b[i] - 'A';
        if (tree[v].go[c] == -1) {
            tree[n].c = c;
            tree[n].prev = v;
            tree[v].go[c] = n++;
        }
        v = tree[v].go[c];
    }
    tree[v].flag = 1;

    h[0][0][0] = true;
    f[0][0][0] = 1.0;

    for (int i = 0; i < s; i++) 
        for (int j = 0; j < n; j++) 
            for (int c = 0; c <= s; c++) {
                if (!h[i][j][c] ) {
                    continue;
                }
                for (int k = 0; k < a.size(); k++) {
                    int ch = a[k] - 'A';
                    int new_j = go(j, ch);
                    int new_c = c + tree[new_j].flag;
                    h[i + 1][new_j][new_c] = true;
                    f[i + 1][new_j][new_c] += f[i][j][c] / a.size();
                }
            }

    int c = 0;
    long double d = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (h[s][i][j] ) {
                c = max(c, j);
                d += f[s][i][j] * j;
                // cerr << s << " " << i << " " << j << " " << f[s][i][j] << "\n"; 
            }
        }
    }
    return c - d;

}

int main() {
	int cases; cin >> cases;

    cout << fixed << setprecision(10);
	for (int i = 0; i < cases; i++) {
        cerr << "Case " << i + 1 << " is done!\n";
        cout << "Case #" << i + 1 << ": " << max((long double)0.0, solve() ) << "\n";
    }
    return 0;
}