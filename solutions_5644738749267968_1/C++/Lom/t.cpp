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

bool fullLess(const set<double>& s1, const set<double>& s2) {
    for (set<double>::const_iterator it1 = s1.begin(), it2 = s2.begin();
         it1 != s1.end(); ++it1, ++it2)
    {
        if (*it1 > *it2) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    int numTests = 0;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        int ans1 = 0, ans2 = 0, ans1True = 0;

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
            // for (auto d : ken) {
            //     int cans = f(nao, ken, d);
            //     ans1True = max(ans1True, cans);
            // }

            set<double> naoN = nao;
            set<double> kenN = ken;

            while (!naoN.empty() && !fullLess(kenN, naoN)) {
                naoN.erase(naoN.begin());
                kenN.erase((++kenN.rbegin()).base());
            }

            ans1 = naoN.size();
        }

        {
            set<double> kenN = ken;
            for (auto na : nao) {
                auto it = kenN.lower_bound(na);
                if (it == kenN.end()) {
                    kenN.erase(kenN.begin());
                    ++ans2;
                } else {
                    kenN.erase(it);
                }
            }
        }

        cout << "Case #" << test << ": " << ans1 << " " << ans2/* << " " << ans1True */<< endl;
    }

    return 0;
}
