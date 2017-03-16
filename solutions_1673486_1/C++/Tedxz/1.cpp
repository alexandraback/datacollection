#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int MAX_LEN = 100010;

long double c[MAX_LEN], ans, tem;
int a, b, T;

void solve() {
    cin >> a >> b;
    c[0] = 1;
    for (int i = 1; i <= a; ++i) {
        cin >> c[i];
        c[i] *= c[i - 1];
    }
    //直接放弃
    ans = b + 2;
    //直接打，若错误就重打
    tem = c[a] * (b - a + 1) + (1  - c[a]) * (b * 2 - a + 2);
    if (ans > tem)
       ans = tem;
    //打退格
    for (int i = 1; i < a; ++i) {
        tem = c[a - i] * (i * 2 + b - a + 1) + (1 - c[a - i]) * (i * 2 + b - a + b + 2);
        if (ans > tem)
            ans = tem;
    } 
    
    cout << ans << endl;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d\n", &T);
    cout << fixed << setprecision(8);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }

}
