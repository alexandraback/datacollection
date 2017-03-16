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

int main(int argc, char **argv) {

    int T;
    cin >> T;

    for (int tno = 1;tno <= T; tno++) {
        int n;
        cin >> n;
        vector<int> bff(n);
        vector<int> circ;
        for (auto& f: bff) {
            cin >> f;
            f--;
            int x = circ.size();
            circ.push_back(x);
        }

        int ret = 0;
        do {
            for (int l = 2;l <= n; l++) {
                bool valid = true;
                for (int i = 0;i < l; i++) {
                    int id = circ[i];
                    int lf = circ[(i + l - 1) % l];
                    int rg = circ[(i + 1) % l];
                    if (bff[id] == lf or bff[id] == rg) {}
                    else {valid = false;break;}
                }
                if (valid)
                    ret = max(ret, l);
            }
        } while (next_permutation(circ.begin(), circ.end()));

        cout << "Case #" << tno << ": " << ret << endl;
    }

    return 0;
}
