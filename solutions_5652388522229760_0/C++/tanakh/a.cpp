#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int cases; cin >> cases;
    for (int cn = 1; cn <= cases; cn++) {
        cout << "Case #" << cn << ": ";

        int n; cin >> n;

        if (n == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }

        int done_cnt = 0;
        vector<bool> done(10, false);

        char buf[32];

        for (int i = n; ; i += n) {
            itoa(i, buf, 10);
            for (int j = 0; buf[j]; j++) {
                int c = buf[j] - '0';
                if (!done[c]) {
                    done[c] = true;
                    done_cnt++;
                }
            }
            if (done_cnt == 10) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
