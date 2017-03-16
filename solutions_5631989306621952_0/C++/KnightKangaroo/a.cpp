#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int t, T;

    cin >> T;

    for (t = 1; t <= T; ++t) {
        string ans = "";
        string S;

        cin >> S;

        int n = S.size();

        if (n == 1) {
            ans = S;
        }
        else {
            ans = S[0];

            for (int i = 1; i < n; ++i) {
                if (S[i] >= ans[0]) {
                    ans = S[i] + ans;
                }
                else {
                    ans = ans + S[i];
                }
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
