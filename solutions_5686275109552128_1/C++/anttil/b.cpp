#include <iostream>
#include <set>

using namespace std;

#define ll long long

int t;
int n;

void solve(int x) {
    cin >> n;
    int c[1111] = {0};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        c[p]++;
    }
    ll t = 999999999;
    for (int i = 1; i <= 1000; i++) {
        ll z = 0;
        for (int j = 1000; j > i; j--) {
            z += c[j]*((j-1)/i);
        }
        z += i;
        t = min(t, z);
    }
    cout << "Case #" << x << ": " << t << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
