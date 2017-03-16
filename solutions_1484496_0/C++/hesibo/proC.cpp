#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int task;
    cin >> task;
    vector< pair<int, int> > list;
    for (int t = 1; t <= task; t++) {
        int n, num[20];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        list.clear();
        for (int st = 0; st < (1 << n); st++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (st & (1 << j)) {
                    sum += num[j];
                }
            }
            list.push_back(make_pair(sum, st));
        }
        sort(list.begin(), list.end());
        int i = 0;
        bool find = false;
        while (i < list.size()) {
            int j = i + 1;
            while (j < list.size() && list[i].first == list[j].first) j++;
            for (int k1 = i; k1 < j; k1++) {
                for (int k2 = k1 + 1; k2 < j; k2++) {
                    if ((list[k1].second & list[k2].second) == 0) {
                        cout << "Case #" << t << ":" << endl;
                        bool first = true;
                        for (int x = 0; x < n; x++) {
                            if (list[k1].second & (1 << x)) {
                                if (!first) {
                                    cout << " ";
                                }
                                first = false;
                                cout << num[x];
                            }
                        }
                        cout << endl;
                        first = true;
                        for (int x = 0; x < n; x++) {
                            if (list[k2].second & (1 << x)) {
                                if (!first) {
                                    cout << " ";
                                }
                                first = false;
                                cout << num[x];
                            }
                        }
                        cout << endl;
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            if (find) break;
            i = j;
        }
        if (!find) cout << "Case #" << t << ": Impossible" << endl;
    }
    return 0;
}
