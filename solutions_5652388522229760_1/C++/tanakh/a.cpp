#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
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

        for (int64_t i = n; ; i += n) {
            ostringstream oss; oss << i;
            const char *buf = oss.str().c_str();

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
