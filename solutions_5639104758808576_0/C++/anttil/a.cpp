#include <iostream>

using namespace std;

int t;
int n;
string s;

void solve(int x) {
    cin >> n;
    cin >> s;
    int c = 0, u = 0;
    for (int i = 0; i <= n; i++) {
        if (c < i) {
            u += i-c;
            c = i;
        }
        c += s[i]-'0';
    }
    cout << "Case #" << x << ": " << u << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
