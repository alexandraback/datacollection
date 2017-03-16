#include <iostream>
#include <string>
using namespace std;

int T, S;
string s;

int min_width[7] = {0, 1, 1, 2, 3, 4, 4};

void solve_case(int t) {
    cout << "Case #" << t << ": ";
    cin >> S >> s;
    int ans = 0;
    int clapping = 0;
    for (int i = 0; i <= S; ++i) {
        if (s[i] > '0' && clapping < i){
            ans += i - clapping;
            clapping = i;
        }
        clapping += s[i] - '0';
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    for (int i=1; i <= T; ++i) solve_case(i);
    return 0;
}
