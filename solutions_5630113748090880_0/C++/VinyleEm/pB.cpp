#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

typedef vector<int> Line;

bool better(Line& l1, Line& l2)
{
    const size_t n = l1.size();
    for (int i = 0;i < n; ++i)
        if (l1[i] <= l2[i])
            return false;
    return true;
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int tno = 1;tno <= T; tno++) {
        int n;
        cin >> n;
        vector<Line> lines(2 * n - 1);
        vector<int> counts(2501, 0);
        for (auto& l: lines) {
            l.resize(n);
            for (auto c: l) {
                cin >> c;
                counts[c]++;
            }
        }

        cout << "Case #" << tno << ":";
        for (int v = 1;v <= 2500; v++)
            if (counts[v] & 1)
                cout << " " << v;
        cout << endl;
    }

    return 0;
}
