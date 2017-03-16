#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

void solve() {
    int n,res = 0;
    vector<pair<int, int> > level;
    bool used[2000][2] = {{false}};
    cin >> n;
    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        level.push_back(make_pair(a,b));
    }
    sort(level.begin(),level.end());
    int star = 0;
    while (true) {
        int bmax = -1;
        int bmaxi = -1;
        while(true) {
            bool flag = false;
            for (int i=0; i<n; i++) {
                if (used[i][1])continue;
                if (level[i].second <= star) {
                    if (used[i][0] == false) {
                        star++;
                        used[i][0] = true;
                    }
                    flag = true;
                    star++;
                    used[i][1] = true;
                    res++;
                }
            }
            if (flag == false)break;
        }
        for (int i=0; i<n; i++) {
            if (used[i][0])continue;
            if (level[i].first > star)break;

            if (bmax < level[i].second) {
                bmax = level[i].second;
                bmaxi = i;
            }
        }
        if (bmaxi == -1)break;
        used[bmaxi][0] = true;
        star++;
        res++;
    }
    for (int i=0; i<n; i++) {
        if (used[i][1] == false) {
            cout << "Too Bad" << endl;
            return;
        }
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    cout << setprecision(10);
    for (int i=0; i<n; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
