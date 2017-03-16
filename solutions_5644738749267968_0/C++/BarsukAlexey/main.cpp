#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    ios_base::sync_with_stdio(false);

    double eps = 1e-8;
    int test; cin >> test;
    for (int i = 0; i < test; i++) {
        int n; cin >> n;
        vector<double> naomi, man;
        for (int j = 0; j < n; j++) {
            double num; cin >> num;
            naomi.push_back(num);
        }
        for (int j = 0; j < n; j++) {
            double num; cin >> num;
            man.push_back(num);
        }
        sort(naomi.begin(), naomi.end());
        sort(man.begin(), man.end());
        vector<double> lie_naomi = naomi;
        vector<double> c_man = man;
        int second = 0;
        for (int j = 0; j < c_man.size(); j++) {
            if (c_man[j] > lie_naomi[j] + eps) {
                reverse(lie_naomi.begin(), lie_naomi.end());
                lie_naomi.pop_back();
                reverse(lie_naomi.begin(), lie_naomi.end());
                c_man.pop_back();
                j--;
            }
            else second++;
        }
        int first = 0;
        for (int j = 0; j < naomi.size(); j++) {
            bool was = false;
            for (int k = 0; k < man.size() && !was; k++) {
                if (man[k] > naomi[j] + eps) {
                    was = true;
                    man.erase(man.begin() + k);
                }
            }
            if (!was) first++;
        }
        cout << "Case #" << i + 1 << ": " << second << " " << first << endl;
        cout.flush();
    }

    return 0;
}
