#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1000;

int main()
{
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int n;
        cin >> n;

        vector<int> diners(n);
        for (int i = 0; i < n; ++i) {
            cin >> diners[i];
        }

        int res = N;
        for (int eatMinutes = 1; eatMinutes <= N; ++eatMinutes) {
            int splits = 0;
            for (int i = 0; i < n; ++i) {
                splits += (diners[i] + (eatMinutes - 1)) / eatMinutes - 1;
            }

            res = min(res, eatMinutes + splits);
        }

        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
