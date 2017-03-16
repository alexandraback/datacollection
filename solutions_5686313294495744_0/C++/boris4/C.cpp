#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int n;
set<pair<int, string> > exist;
string A[20], B[20];

int main() {
    int testNum; cin >> testNum;
    for (int testId = 1; testId <= testNum; ++testId) {
        cout << "Case #" << testId << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i] >> B[i];
        }
        int res = 0;
        for (int mask = 0; mask < 1 << n; ++mask) {
            exist.clear();
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    exist.insert(make_pair(0, A[i]));
                    exist.insert(make_pair(1, B[i]));
                }
            }
            int curRes = 0;
            for (int i = 0; i < n; ++i) {
                if (!((mask >> i) & 1)) {
                    if (exist.count(make_pair(0, A[i])) &&
                        exist.count(make_pair(1, B[i]))) {
                        ++curRes;
                    }
                }
            }
            res = max(res, curRes);
        }
        cout << res << endl;
    }
    return 0;
}
