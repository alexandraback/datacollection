#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <utility>


using namespace std;

int max_circle(vector<int> bffs) {
    // notice: 1 to n, not 0 to n - 1
    const auto n = bffs.size() - 1;
//    for (int i = 1; i <= n; ++i) { cout << bffs[i] << " "; } cout << endl;
    vector<bool> extendable(n + 1, false);
    for (auto i = 1; i <= n; ++i) {
        extendable[i] = i == bffs[bffs[i]];
    }
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> ll(n + 1, make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        if (!extendable[i] && !visited[i]) {
            visited[i] = true;
            vector<int> list(1, i);
            int j = bffs[i];
            for (; !extendable[j] && !visited[j]; j = bffs[j]) {
                visited[j] = true;
//                cout << j << " ";
                list.push_back(j);
            }
//            cout << endl;
            auto len = list.size();
            for (auto k = 0; k < len; ++k) {
                // link length and dst
                if (extendable[j])
                    ll[list[k]] = make_pair(len - k + 2, bffs[j]);
                else
                    ll[list[k]] = make_pair(len, list[(k + len - 1) % len]);
            }
            if (extendable[j]) {
                ll[j] = make_pair(max((int)len + 2, ll[j].first), bffs[j]);
            }
        }
        else if (extendable[i]) {
            ll[i] = make_pair(max(2, ll[i].first), bffs[i]);
        }
        //ll[i].first : if i is not extendable:
        //                  if is a link, the length of the link
        //                  if is a circle, the length of the cycle
        //              else: the max len of all the links ending i
//        cout << i << " " << ll[i].first << " " << ll[i].second << endl;
    }
//    cout << endl;
    int max_len = 0;
    for (int i = 1; i <= n; ++i) {
        if (extendable[i]) {
            max_len = max(max_len, ll[i].first + ll[bffs[i]].first - 2);
        }
        else {
            max_len = max(max_len, ll[i].first);
        }
    }
    return max_len;
}

int main(int argc, char **argv) {
    fstream input("/Users/garygaojun/Google Drive/Documents/codejam/BFFs/bffs.in", ios_base::in);
    fstream output("/Users/garygaojun/Google Drive/Documents/codejam/BFFs/bffs.out", ios_base::out);
    if (!input.is_open()) {
        cout << "fail to open input file" << endl;
        return -1;
    }
    int lines;
    input >> lines;
    for (int k = 1; k <= lines; ++k) {
        vector<int> bffs(1, 0);
        int n ;
        input >> n;
        for (int i = 0; i < n; ++i) {
            int bff;
            input >> bff;
            bffs.push_back(bff);
        }
        auto ml = max_circle(bffs);
        output << "Case #" << k << ": ";
        output << ml << endl;
    }
    return 0;
}