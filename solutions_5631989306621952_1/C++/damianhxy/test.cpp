#include <iostream>
#include <string>
using namespace std;

int N;
string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        string NS, S2;
        cin >> S;
        for (auto C: S) {
            if (NS.empty()) NS.push_back(C);
            else if (C >= NS.front())
                NS = C + NS;
            else
                NS.push_back(C);
        }
        cout << "Case #" << a << ": " << NS << "\n";
    }
    return 0;
}
