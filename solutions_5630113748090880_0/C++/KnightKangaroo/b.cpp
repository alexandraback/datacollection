#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    int t, T;

    cin >> T;

    for (t = 1; t <= T; ++t) {
        int N;
        int h;
        unordered_set<int> H;
        unordered_set<int>::iterator it;
        vector<int> ans;

        cin >> N;

        for (int i = 0; i < 2 * N - 1; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> h;
                if ((it = H.find(h)) == H.end()) {
                    H.insert(h);
                }
                else {
                    H.erase(it);
                }
            }
        }

        for (it = H.begin(); it != H.end(); ++it) {
            ans.push_back(*it);
        }

        sort(ans.begin(), ans.end());

        printf("Case #%d:", t);
        for (int i = 0; i < N; ++i) {
            printf(" %d", ans[i]);
        }
        puts("");
    }

    return 0;
}
