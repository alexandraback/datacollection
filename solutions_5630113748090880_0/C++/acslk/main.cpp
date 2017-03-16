#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T, N;

string calc (int val) {

}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<vector<int>> lists;
        vector<vector<vector<int>>> sorted;

        for (int i = 0; i < 2*N - 1; i++) {
            vector<int> list;
            for (int j = 0; j < N; j++) {
                int a;
                cin >> a;
                list.push_back(a);
            }
            lists.push_back(list);
        }

        int missing = -1;
        for (int i = 0; i < N; i++) {
            vector<vector<int>> cur;
            int min = 2600;
            int mina = -1;
            int minb = -1;
            for (int j = 0; j < lists.size(); j++) {
                if (lists[j][i] < min) {
                    min = lists[j][i];
                    mina = j;
                    minb = -1;
                } else if (lists[j][i] == min) {
                    minb = j;
                }
            }
            cur.push_back(lists[mina]);
            if (minb == -1) {
                missing = i;
            } else {
                cur.push_back(lists[minb]);
                lists.erase(lists.begin() + minb);
            }
            lists.erase(lists.begin() + mina);
            sorted.push_back(cur);
        }

        vector<int> other = sorted[missing][0];
        cout << "Case #" << t+1 << ":";

        for (int i = 0; i < N; i++) {
            if (i != missing) {
                int a = sorted[i][0][missing];
                int b = sorted[i][1][missing];
                cout << " " << (a == other[i] ? b : a);
            } else
                cout << " " << other[missing];
        }

        cout << "\n";
    }
}