#include <iostream>
#include <climits>
#include <cstring>
#include <stdlib.h>
using namespace std;

bool dfs(long p, long q, long gen, long& min_gen) {
    if (p == 0) {
        return true;
    }

    while (p < q) {
        if (q % 2 == 1) {
            return false;
        }
        q = q / 2;
        gen++;
    }

    if (p >= q && gen < min_gen) {
        min_gen = gen;
    }

    return dfs(p - q, q, gen, min_gen);
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        int pos = s.find("/");
        long p = atol(s.substr(0, pos).c_str());
        long q = atol(s.substr(pos + 1).c_str());

        cout << "Case #" << t << ": ";
        long min_gen = LONG_MAX;
        bool ispossible = dfs(p, q, 0, min_gen);
        if (ispossible) {
            cout << min_gen << endl;
        }
        else {
            cout << "impossible" << endl;
        }
    }
}
