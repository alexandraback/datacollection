#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int cnt1[N][N], cnt2[N][N], cnt3[N][N];
vector<pair<pair<int,int>,int>> kq;

int main() {
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int jj, pp, ss, k;
        cin >> jj >> pp >> ss >> k;
        for (int j = 1; j <= jj; j++) {
            for (int p = 1; p <= pp; p++)
                cnt1[j][p] = k;
            for (int s = 1; s <= ss; s++)
                cnt2[j][s] = k;
        }
        for (int p = 1; p <= pp; p++)
            for (int s = 1; s <= ss; s++)
                cnt3[p][s] = k;
        kq.clear();
        for (int s = 1; s <= ss; s++) {
        for (int p = 1; p <= pp; p++)
        for (int j = 1; j <= jj; j++)
            if (cnt1[j][p] > 0 && cnt2[j][s] > 0 && cnt3[p][s] > 0) {
                kq.push_back({{j,p},s});
                cnt1[j][p]--;
                cnt2[j][s]--;
                cnt3[p][s]--;
            }
        }
        cout << "Case #" << nt << ": " << kq.size() << "\n";
        for (auto &p : kq) {
            cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
        }
    }
    return 0;
}
