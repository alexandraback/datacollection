#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
int A,B,K;


void init()
{
    cin >> A>>B>>K;
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            if ((i & j) < K) ans++;
    cout << ans;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
