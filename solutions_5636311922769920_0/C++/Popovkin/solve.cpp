#include <iostream>
#include <fstream>
#define ll long long
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

ll a, b, c, d, e, l, n;

string s;

int main() {
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    cin >> a;
    for (int i = 0; i < a; ++i) {
        cout << "Case #" << i + 1 << ": ";
        cin >> b >> c >> d;
        for (int i = 0; i < b; ++i)
            cout << i + 1 << ' ';
        cout << "\n";
    }
}