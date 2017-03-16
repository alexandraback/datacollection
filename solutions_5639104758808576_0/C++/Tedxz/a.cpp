#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int T;
int S;
string str;

int ans, tot;

int main() {
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        ans = 0;
        tot = 0;
        cin >> S >> str;
        for (int i = 0; i <= S; ++i) {
            tot += str[i] - '0';
            if (tot <= i) {
                ans += i + 1 - tot;
                tot = i + 1;
            }
        }

        cout << "Case #" << cs << ": " << ans << endl;
    }

    return 0;
}
