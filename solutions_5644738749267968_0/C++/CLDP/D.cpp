#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

double x[MAXN], y[MAXN];


int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> x[i];
        for (int i = 0; i < N; ++i) cin >> y[i];
        sort(x, x + N);
        sort(y, y + N);
        int ans1 = 0, ans2 = 0, L = 0;
        for (int i = 0; i < N; ++i) {
            if (x[i] > y[L]) {
                ++ans1;
                ++L;
            }
        }
        vector<pair<double, int> > X;
        for (int i = 0; i < N; ++i) {
            X.push_back(make_pair(x[i], 1));
            X.push_back(make_pair(y[i], 2));
        }
        sort(X.begin(), X.end());
        int B = 0;
        for (int i = N + N - 1; i >= 0; ) {
            int j = i;
            while (j >= 0 && X[j].second == X[i].second) --j;
            if (X[i].second == 2) {
                B += i - j;
            } else {
                B -= i - j;
                if (B < 0) {
                    ans2 -= B;
                    B = 0;
                }
            }
            
            i = j;
        }
        
        cout << "Case #" << times << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
