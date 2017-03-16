#include <bits/stdc++.h>
using namespace std;



typedef double DB;
typedef long long LL;

const int N = 55;

int e[N][N];
long long f[N];

bool calc(int n, long long m) {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    if (e[i][j]) f[j] += f[i];
    return f[n - 1] == m;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n;
    long long m;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++) {
        printf("Case #%d: ", cas);
        cin >> n >> m;
        long long max_path = 1LL << (n - 2);
        if (max_path >= m) {
            memset(e, 0, sizeof(e));
            for (int i = 0; i < n;  i++) {
                if ((1LL << i) >= m) {
                    long long left = (1LL << i) - m;
                    for (int j = 0; j <= i; j++) {
                        for (int k = j + 1; k <= i; k++) {
                            e[j][k] = 1;
                        }
                    }
                    for (int j = 0; j <= i; j++) {
                        if (j && (left >> (j - 1) & 1)) e[j][n - 1] = 0;
                        else e[j][n - 1] = 1;
                    }
                    break;
                }
            }
            //cout << calc(n, m) << endl;

            puts("POSSIBLE");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << e[i][j];
                }
                cout << endl;
            }
        } else {
            puts("IMPOSSIBLE");
        }
    }


}
