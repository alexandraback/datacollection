#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int K, L, S, MX, N, M;
string pat, kb;

void rec(string str, int i) {
    if (i == S) {
        int a = 0, ps = -1;
        while((ps = str.find(pat, ps + 1)) != -1) a++;
        MX = max(MX, a);
        N += a;
        M ++;
        return;
    }
    for(int j = 0; j < kb.length(); j++) {
        rec(str + kb[j], i+1);
    }
}

int main()
{
    freopen("B-small-attempt0.in", "rt", stdin);
    freopen("output.out", "wt", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> K >> L >> S;
        cin >> kb >> pat;
        MX = N = M = 0;
        rec("", 0);
        double ans = MX - (N + 0.0)/M;
        cout << "Case #" << t << ": " << fixed << setprecision(7) << ans << endl;
    }
    return 0;
}
