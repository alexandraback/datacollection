// Pijus Navickas <pijus.navickas@gmail.com>

#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ullong;

using namespace std;

vector<ullong> findMinimalSolution(ullong k, ullong c) {
    vector<ullong> result;

    ullong checked = 0;

    while (checked < k) {
        ullong absolutePosition = checked;
        ++checked;
        // cout << "absolutePosition=" << absolutePosition << "; depth=" << 1 << "; checked=" << checked << endl;
        for (uint depth = 2; depth <= c; ++depth) {
            absolutePosition = absolutePosition * k + checked;

            if (checked + 1 <= k) {
                ++checked;
            } else {
                --absolutePosition;
            }
            // cout << "absolutePosition=" << absolutePosition << "; depth=" << depth << "; checked=" << checked << endl;
        }
        result.push_back(absolutePosition);
        // break;
    }

    return result;
}

void doTestCase(uint number) {
    uint k, c, s;
    cin >> k >> c >> s;

    vector<ullong> result = findMinimalSolution(k, c);

    if (result.size() > s) {
        cout << "Case #" << number << ": " << "IMPOSSIBLE" << endl;
    } else {
        cout << "Case #" << number << ": ";
        for (uint i = 0; i != result.size(); ++i) {
            if (i != 0) {
                cout << ' ';
            }
            cout << result[i] + 1;
        }
        cout << endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint t;
    cin >> t;

    for (uint i = 0; i != t; ++i) {
        doTestCase(i + 1);
    }

    return 0;
}
