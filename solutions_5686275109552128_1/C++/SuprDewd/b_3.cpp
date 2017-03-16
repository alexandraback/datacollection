#include "../../lib/include.h"

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {
        int d;
        cin >> d;

        vector<int> p(d);
        for (int i = 0; i < d; i++) {
            cin >> p[i];
        }

        LOGIC;

        ll mn = -1;
        for (int end = 1; end <= 1000; end++) {
            vector<ll> cnt(1001, 0);
            for (int i = 0; i < d; i++) {
                cnt[p[i]]++;
            }

            ll done = 0;
            for (int i = 1000; i > end; i--) {
                int l = end,
                    r = i - l;

                cnt[l] += cnt[i];
                cnt[r] += cnt[i];
                done += cnt[i];
            }

            ll cur = end + done;
            if (mn == -1 || cur < mn) {
                mn = cur;
            }
        }

        OUTPUT;

        assert(mn != -1);

        cout << mn << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
