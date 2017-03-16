#include <iostream>
#include <string>

using namespace std;

void doit() {
    string input;
    cin >> input;
    char state = input[0];
    size_t plen = input.size();
    int ans = 0;
    for (size_t i = 1; i < plen; ++i) {
        if (input[i] != state) {
            state = input[i];
            ans += 1;
        }
    }
    if (state == '-') {
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        doit();
    }
    return 0;
}
