
#include <iostream>
#include <vector>
#include <inttypes.h>
#include <algorithm>
using namespace std;

#define SZ 10000000
int64_t previous_[SZ];
int64_t next_    [SZ];

int main(int argc, char *argv[])
{
    int problems;
    cin >> problems;

    for (int i=1; i<=problems; ++i) {
        int64_t e, r, n;
        vector<int64_t> v;
        int64_t *previous = previous_;
        int64_t *next = next_;

        cin >> e >> r >> n;
        for (int j=0; j<n; ++j)
        {
            int64_t vi;
            cin >> vi;
            v.push_back(vi);
        }

        for (int j=0; j<=e; ++j) {
            previous[j] = (e-j)*v[0];
            // cout << previous[j] << " ";
        }
        // cout << "\n";
        fill(next, next+e+1, 0);

        for (int j=1; j<n; ++j) {
            for (int k=0; k<=e; ++k) {
                vector<int64_t> vv;
                // cout << "min(" << k+r << "," << e << ")=" << min(k+r, e) << endl;
                for (int l=0; l<=min(k+r, e); ++l) {
                    // cout << k << "->" << l << ":" << previous[k] + (min(k+r, e) - l)*v[j] << endl;;
                    next[l] = max(next[l], previous[k] + (min(k+r, e) - l)*v[j]);
                }
            }
            // for (int k=0; k<=e; ++k)
            //     cout << next[k] << " ";
            swap(previous, next);
            fill(next, next+e+1, 0);
            // cout << "\n";
        }

        cout << "Case #" << i << ": " << *(max_element(previous, previous+e+1)) << "\n";
    }
    return 0;
}
