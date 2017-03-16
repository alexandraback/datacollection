#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int add = 0;
        for (add = 0; add <= n; ++add) {
            int have = add;
            bool can = true;

            for (int i = 0; i <= n; ++i) {
                if (have < i) {
                    can = false;
                    break;
                }
                have += s[i] - '0';
            }

            if (can) break;
        }

        cout << "Case #" << test << ": " << add << endl;
    }

    return 0;
}
