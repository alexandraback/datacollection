#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <queue>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;

int n, m, k;

char c[51][51];

void no() {
    puts("Impossible");
}

void printAns() {
    forn(i, n)
        puts(c[i]);
}

void solveOne() {
    forn(i, n)
        forn(j, m)
            if (k--) c[i][j] = '*';
            else return printAns();
}

vector<pii> make_order() {
    vector<pii> res;
    forn(i, n - 2)
        forn(j, m - 2)
            res.pb(mp(i, j));

    forn(i, n - 2) {
        res.pb(mp(i, m - 2));
        res.pb(mp(i, m - 1));
    }

    forn(j, m) {
        res.pb(mp(n - 2, j));
        res.pb(mp(n - 1, j));
    }

    return res;
}

void solveCase() {
    cin >> n >> m >> k;
    forn(i, n) {
        memset(c[i], '.', m * sizeof(char));
        c[i][m] = 0;
    }

    c[n - 1][m - 1] = 'c';
    if (n == 1 || m == 1) return solveOne();

    if (k > n * m - 4 && k != n * m - 1) return no();

    vector<pii> order = make_order();

    if (k != n * m - 1 && k > (n - 2) * (m - 2) && (k - (n - 2) * (m - 2)) % 2 == 1) {
        if (n < 3 || m < 3) return no();

        for (int i = n - 3; i < n; ++i)
            for(int j = m - 3; j < m; ++j) {
                vector<pii>:: iterator it = find(all(order), mp(i, j));
                if (it != order.end()) order.erase(it);
            }
    }

    if (k > (int)order.size()) return no();

    for(int i = 0; i < (int) order.size() && k; ++i, --k)
        c[order[i].first][order[i].second] = '*';
    printAns();
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tk;
    scanf("%d", &tk);
    for(int tc = 1; tc <= tk; ++tc) {
        printf("Case #%d:\n", tc);
        solveCase();
        cerr << "Case #" << tc << " is solved." << endl;
    }
    return 0;
}