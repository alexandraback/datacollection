#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1005;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        string in;
        cin >> in;
        string ans;
        for (int i = 0; i < in.size(); ++i) {
            string tmp1, tmp2;
            tmp1 = ans + in[i];
            tmp2 = ans;
            reverse(tmp2.begin(), tmp2.end());
            tmp2 = tmp2 + in[i];
            reverse(tmp2.begin(), tmp2.end());
            if (tmp1 > tmp2) ans = tmp1;
            else ans = tmp2;
        }
        static int ca = 0;
        printf("Case #%d: ", ++ca);
        cout << ans << endl;
    }
    return 0;
}
