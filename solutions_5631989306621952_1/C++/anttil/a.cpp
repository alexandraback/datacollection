#include <iostream>

using namespace std;

int t;
string s;

string lol(string x) {
    if (x.size() <= 1) return x;
    char u = 'A';
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > u) u = x[i];
    }
    bool p = true;
    string a, b, c;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] < u && p) {
            a += x[i];
        } else if (x[i] == u) {
            b = b+x[i];
            p = false;
        } else {
            c = c+x[i];
        }
    }
    return b+lol(a)+c;
}

void solve(int x) {
    cin >> s;
    cout << "Case #" << x << ": ";
    cout << lol(s) << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
