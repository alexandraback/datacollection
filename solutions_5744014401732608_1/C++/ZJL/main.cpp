#include <iostream>

using namespace std;
typedef long long ll;
const int N = 27;
int v[N];

struct Node {
    int id;
    int num;

    friend bool operator<(Node a, Node b) {
        return a.num < b.num; //结构体中，x小的优先级高
    }
};

int val[55][55];

int main() {
    int T;
     freopen("/Users/vino/Desktop/B-large.in", "r", stdin);

    freopen("/Users/vino/Desktop/B-large.out", "w", stdout);
    cin >> T;
    int cas = 0;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        printf("Case #%d: ", ++cas);
        if (m > (1l << (n - 2))) {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                val[i][j] = 1;
                if(i >= j) val[i][j] = 0;
            }
        for (int i = 0; i < n; i++) {
            val[n - 1][i] = 0;
        }
        int ct = 0;
        ll num = (1l << (n - 2)) - m;
        while (num) {
            if (num & 1)
                val[0][n - 2 - ct] = 0;
            ct++;
            num >>= 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                printf("%d", val[i][j]);
                if (j == n - 1) cout << endl;
            }


    }


    return 0;
}