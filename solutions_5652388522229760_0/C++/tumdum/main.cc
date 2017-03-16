#include <set>
#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

void solve(const int C) {
    int64_t N;
    cin >> N;
    set<char> seen;
    int64_t last;
    for (int64_t i = 1; i <= 100; ++i) {
        last = i * N;
        const auto rep = to_string(last);
        seen.insert(rep.begin(), rep.end());
        if (seen.size() == 10) {
            break;
        }
    }
    cout << "Case #" << C << ": " <<
        ((seen.size() == 10) ? to_string(last) : "INSOMNIA") << endl;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}
