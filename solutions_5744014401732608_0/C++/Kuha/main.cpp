#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define ld long double
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<18)

#define cout out
#define cin in

using namespace std;

int main() {
    ofstream out("google.out");
    ifstream in("google.in");

    int t;
    cin>>t;

    for (int c = 1; c <= t; c++) {
        ll n, m;
        cin>>n>>m;
        if ((1<<(n - 2)) < m) {
            cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
        } else {
            cout<<"Case #"<<c<<": POSSIBLE"<<endl;
            bool b[n][n];
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) b[y][x] = false;
            }
            for (int y = 0; y < n - 1; y++) {
                for (int x = y + 1; x < n - 1; x++) {
                    b[y][x] = true;
                }
            }

            if ((1<<(n - 2)) == m) {
                for (int y = 0; y < n - 1; y++) {
                    b[y][n - 1] = true;
                }
            } else {
                for (int y = 0; y < n - 1; y++) {
                    if (m & (1<<y)) b[y + 1][n - 1] = true;
                }
            }

            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    cout<<b[y][x];
                }
                cout<<endl;
            }
        }
    }

    out.close();
}
