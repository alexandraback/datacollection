#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>

using namespace std;

struct sol {
    int j;
    int p;
    int s;
    sol(int a, int b, int c) { j = a; p = b; s = c; }
};

void doit() {
    int J, P, S, K;
    cin >> J >> P >> S >> K;

    vector<sol> ans;
    vector<int> used_fl(100, 0);
    vector<int> used_fm(100, 0);
    vector<int> used_ml(100, 0);


    // First do 3 distintct values
    // We want this so we can swap the two values later on
    for (int j = 0; j < J; ++j) {
        for (int p = 0; p < P; ++p) {
            if (j == p) continue;
            int fm = 10*j+p;
            if (used_fm[fm] == K) continue;
            for (int s = 0; s < S; ++s) {
                if (p == s || j == s) continue;
                int ml = 10*p+s;
                int fl = 10*j+s;
                if (used_fm[fm] == K) break;
                if (used_ml[ml] == K) continue;
                if (used_fl[fl] == K) continue;

                used_fm[fm]++;
                used_ml[ml]++;
                used_fl[fl]++;

                ans.push_back(sol(j, p, s));

            }
        }
    }

    // Now, allow repeats
    for (int j = 0; j < J; ++j) {
        for (int p = 0; p < P; ++p) {
            int fm = 10*j+p;
            if (used_fm[fm] == K) continue;
            for (int s = 0; s < S; ++s) {
                if (j != p && j != s && p != s) continue;
                int ml = 10*p+s;
                int fl = 10*j+s;
                if (used_fm[fm] == K) break;
                if (used_ml[ml] == K) continue;
                if (used_fl[fl] == K) continue;

                used_fm[fm]++;
                used_ml[ml]++;
                used_fl[fl]++;

                ans.push_back(sol(j, p, s));

            }
        }
    }

    cout << " " << ans.size() << '\n';
    for (auto s : ans) {
        cout << s.j+1 << ' ' << s.p+1 << ' ' << s.s+1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        doit();
    }
    return 0;
}
