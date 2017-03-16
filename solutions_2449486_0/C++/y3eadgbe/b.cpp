#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int field[100][100];
bool vis[100][100];
int n,m;

void solve() {
    cin >> n >> m;
    rep(i,n)rep(j,m) {
        cin >> field[i][j];
    }
    rep(i,n)rep(j,m)vis[i][j] = false;

    rep(d,99) {
        int height = d + 1;
        bool flag = true;
        rep(i,n) {
            flag = true;
            rep(j,m) {
                if (field[i][j] != height) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                rep(j,m) {
                    vis[i][j] = true;
                }
            }
        }
        rep(j,m) {
            flag = true;
            rep(i,n) {
                if (field[i][j] != height) {
                    flag = false;
                }
            }
            if (flag) {
                rep(i,n) {
                    vis[i][j] = true;
                }
            }
        }
        rep(i,n)rep(j,m) {
            if (vis[i][j]) {
                vis[i][j] = false;
                field[i][j] += 1;
            }
        }
    }

    bool ok = true;
    rep(i,n) {
        rep(j,m) {
            if (field[i][j] != 100)ok = false;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
