#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
vector<LL> a;
void run(int cas) {
    LL left, right;
    cin >> left>> right;
    int ans = (upper_bound(a.begin(), a.end(), right)
            - lower_bound(a.begin(), a.end(), left));
    cout << "Case #" << cas <<": " << ans << endl;
}

int p[20];
bool pali(LL x) {
    int t = 0;
    while (x > 0) {
        p[t++] = x % 10;
        x = x / 10;
    }
    for (int i = t/ 2; i >= 0; --i)
        if (p[i] != p[t-i - 1]) return false;
    return true;
}

void prework() {
    for (LL i = 1; i <= 10000000; ++i)
        if (pali(i) && pali(i * i))
            a.push_back(i*i);
}

int main() {
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);
    prework();
    //cout << a.size() << endl;
    int t; cin >> t;
    for (int i = 1; i <= t; ++i)
        run(i);
    return 0;
}
