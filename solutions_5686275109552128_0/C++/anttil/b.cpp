#include <iostream>
#include <set>

using namespace std;

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
    int t = 999999999;
    for (int i = 1; i <= 1000; i++) {
        int z = 0;
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
