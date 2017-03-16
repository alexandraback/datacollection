#include <algorithm>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <iostream>


using namespace std;

int f(const set<double>& nao, const set<double>& ken, double d) {
    int ans = 0;

    if (*nao.begin() > d) {
        ++ans;
    }

    set<double> naoN = nao;
    naoN.erase(naoN.begin());

    set<double> kenN = ken;
    kenN.erase(d);

    int cans = 0;
    for (auto d : kenN) {
        cans = max(cans, f(naoN, kenN, d));
    }

    ans += cans;
    return ans;
}

int main(int argc, char* argv[]) {
    int numTests = 0;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        int ans1 = 0, ans2 = 0;

        int n = 0;
        cin >> n;

        set<double> nao, ken;
        for (int i = 0; i < n; ++i) {
            double v;
            cin >> v;
            nao.insert(v);
        }

        for (int i = 0; i < n; ++i) {
            double v;
            cin >> v;
            ken.insert(v);
        }

        // {
        //     for (auto d : nao) cout << d << " ";
        //     cout << endl;
        //     for (auto d : ken) cout << d << " ";
        //     cout << endl;
        // }

        {
            for (auto d : ken) {
                int cans = f(nao, ken, d);
                ans1 = max(ans1, cans);
            }
        }

        {
            set<double> k = ken;
            for (auto na : nao) {
                auto it = k.lower_bound(na);
                if (it == k.end()) {
                    k.erase(k.begin());
                    ++ans2;
                } else {
                    k.erase(it);
                }
            }
        }

        cout << "Case #" << test << ": " << ans1 << " " << ans2 << endl;
    }

    return 0;
}
