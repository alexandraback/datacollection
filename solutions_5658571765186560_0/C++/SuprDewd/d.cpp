#include "../../lib/include.h"

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {

        int x, r, c;
        cin >> x >> r >> c;

        LOGIC;

        if (r > c)
            swap(r, c);

        bool decided = false;
        bool can;
        if (!decided && x >= 2*min(r,c) + 1) can = false, decided = true;
        if (!decided && x >= 7) can = false, decided = true;
        if (!decided && (r*c) % x != 0) can = false, decided = true;
        if (!decided && r == c && x > r) can = false, decided = true;
        if (!decided && x == 1) can = true, decided = true;
        if (!decided && x == 2) can = true, decided = true;
        if (!decided && x == 3) can = true, decided = true;
        if (!decided && x == 4) {
            if (!decided && r == 2 && c == 4) can = false, decided = true;
            if (!decided && r == 3 && c == 4) can = true, decided = true;
            if (!decided && r == 4 && c == 4) can = true, decided = true;
        }

        assert(decided);

        OUTPUT;
        // if (!decided) cout << x << "," << r << "," << c << endl;
        if (can) cout << "GABRIEL" << endl;
        else cout << "RICHARD" << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
