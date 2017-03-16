#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

double C, F, X;
double ans, past;

void solve() {
    cin >> C >> F >> X;

    ans = X / 2;
    past = 0;
    for (int i = 0; i < X; i++) {
        past += C / (2 + F * i);
        double curr = past + X / (2 + F * (i+1));
        if (ans > curr)
            ans = curr;
        else {
            printf("%.7lf\n", ans);
            return;
        }
    }

}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}
