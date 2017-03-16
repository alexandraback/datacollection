#include <iostream>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void tc() {
    static int cas = 1;
    cout << "Case #" << cas++ << ": ";
    int N;
    cin >> N;
    vector<vector<int> >ls(2*N-1);
    for (int i = 0; i < 2*N-1; ++i) {
        ls[i].resize(N);
        for (int j = 0; j < N; ++j) cin >> ls[i][j];
    }
    for (int i = 0; i < N - 1; ++i) {
        int lo = 999999999;
        multiset<int> nums;
        vector<int> ixs;
        for (int j = 0; j < ls.size(); ++j) {
            if (ls[j][i] < lo) {
                lo = ls[j][i];
                nums.clear();
                ixs.clear();
            }
            if (ls[j][i] == lo) {
                ixs.push_back(j);
                for (int k = i+1; k < N; ++k) {
                    nums.insert(ls[j][k]);
                }
            }
        }
        if (ixs.size() == 1) {
            cout << ls[ixs[0]][i] << ' ';
            swap(ls[ixs[0]], ls.back()); ls.pop_back();
            vector<int> out;
            for (int j = 0; j < ls.size(); ++j) {
                auto it = nums.lower_bound(ls[j][i]);
                if (it == nums.end() || *it != ls[j][i]) {
                    out.push_back(ls[j][i]);
                } else {
                    nums.erase(it);
                }
            }
            sort(out.begin(), out.end());
            for (int k = 0; k < out.size(); ++k) cout << out[k] << ' ';
            cout << endl;
            return;
        }
        assert(ixs.size() == 2);
        assert(nums.size() == 2 * (N-i-1));
        //for (int j = 0; j < N; ++j) cerr << ls[ixs[0]][j] << ' '; cerr << endl;
        //for (int j = 0; j < N; ++j) cerr << ls[ixs[1]][j] << ' '; cerr << endl;
        if (ixs[0] > ixs[1]) swap(ixs[0], ixs[1]);
        swap(ls[ixs[1]], ls.back()); ls.pop_back();
        swap(ls[ixs[0]], ls.back()); ls.pop_back();
        for (int j = 0; j < ls.size(); ++j) {
            auto it = nums.lower_bound(ls[j][i]);
            assert(*it == ls[j][i]);
            nums.erase(it);
        }
        assert(nums.size() == 1);
        cout << *nums.begin() << ' ';
    }
    assert(ls.size() == 1);
    cout << ls[0][N-1];
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
