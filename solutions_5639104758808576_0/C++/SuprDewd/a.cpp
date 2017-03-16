#include "../../lib/include.h"

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {
        int smax;
        cin >> smax;
        string s;
        cin >> s;

        LOGIC;

        int need = 0;
        int highest = 0;
        for (int i = 0; i <= smax; i++) {
            if (highest < i) {
                need++;
                highest++;
            }
            assert(highest >= i);
            highest += s[i] - '0';
        }

        OUTPUT;

        cout << need << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
