#include<cstdio>
#include<vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int> stavy;
vector<int> ma;
vector< vector<bool> > g;
int b, m;

ll count(int x) {
    if (ma[x] > -2) return ma[x];
    stavy[x] = 1;
    int pocet = 0;
    if (x == b-1) {
        pocet = 1;
    } else {
        for (int i = 0; i<b; ++i) {
            if (!g[x][i]) continue;
            if (stavy[i] == 1) {
                pocet = -1;
                break;
            }
            int kol = count(i);
            if (kol == -1) {
                pocet = -1;
                break;
            }
            pocet += kol;
        }
    }
    stavy[x] = 2;
    ma[x] = pocet;
    return pocet;
}

void print() {
    for (int i = 0; i<b; ++i) {
        for (int j = 0; j<b; ++j) {
            printf("%d", g[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t<T; ++t) {
        scanf("%d %d", &b, &m);
        printf("Case #%d: ", t+1);
        int c = (b-2)*(b-1) +1;
        bool found = false;
        for (int k = 0; k<(1<<c); ++k) {
            stavy.clear();
            stavy.resize(b, 0);
            ma.clear();
            ma.resize(b, -2);
            g.clear();
            g.resize(b, vector<bool>(b, false));
            int x = k;
            for (int i = 0; i<b-1; ++i) {
                for (int j = 1; j<b; ++j) {
                    if (i == j) continue;
                    g[i][j] = (x%2 == 1);
                    x /= 2;
                }
            }
            int poc = count(0);
            if (poc == m) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("POSSIBLE\n");
            print();
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
