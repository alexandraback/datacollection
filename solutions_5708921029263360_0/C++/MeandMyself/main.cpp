#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;



int main()
{
    ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(28);

    int tt;
    cin >> tt;
    //cout << tt;
    for (int t = 0; t < tt; ++t) {
        int n, m, p, k;
        cin >> n >> m >> p;
        vector < int > cl = {n, m, p};
        cin >> k;
        int mx = n * m * p;
        vector < int > x (mx, 0);
        for (int i = 0; i < mx; ++i) {
            x[i] = i;
        }
        int ans = 0;
        auto xx = x;
        //cout << "here" << endl;
        for (int i = 0; i < 1000; ++i) {
            int sum = 0;
            set < vector < int > > ex;
            map < vector < int > , int > pr;
            for (int j = 0; j < mx; ++j) {
                //cout << "herej" << endl;
                vector < int > temp(3);
                int tmp = x[j];
                for (int l = 0; l < 3; ++l) {
                    temp[l] = tmp % cl[l];
                    tmp /= cl[l];
                }
                if (ex.find(temp) == ex.end()) {
                    bool ok = true;
                    for (int l = 0; l < 3; ++l) {
                        tmp = temp[l];
                        temp[l] = -1;
                        if (pr[temp] == k) {
                            ok = false;
                        }
                        temp[l] = tmp;
                    }
                    if (ok) {
                        //cout << "here" << endl;
                        ex.insert(temp);
                        for (int l = 0; l < 3; ++l) {
                            tmp = temp[l];
                            temp[l] = -1;
                            pr[temp]++;
                            temp[l] = tmp;
                        }
                        sum++;
                    }
                }
            }
            if (sum > ans) {
                ans = sum;
                xx = x;
            }
            next_permutation(x.begin(), x.end());
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
        x = xx;
        set < vector < int > > ex;
        map < vector < int > , int > pr;
        for (int j = 0; j < mx; ++j) {
            vector < int > temp(3);
            int tmp = x[j];
            for (int l = 0; l < 3; ++l) {
                temp[l] = tmp % cl[l];
                tmp /= cl[l];
            }
            if (ex.find(temp) == ex.end()) {
                bool ok = true;
                for (int l = 0; l < 3; ++l) {
                    tmp = temp[l];
                    temp[l] = -1;
                    if (pr[temp] == k) {
                        ok = false;
                    }
                    temp[l] = tmp;
                }
                if (ok) {
                    ex.insert(temp);
                    for (int l = 0; l < 3; ++l) {
                        cout << temp[l] + 1 << " ";
                        tmp = temp[l];
                        temp[l] = -1;
                        pr[temp]++;
                        temp[l] = tmp;
                    }
                    //sum++;
                    cout << endl;
                }
            }
        }
        //cout << endl;
    }
    return 0;
}