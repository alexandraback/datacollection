#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXH 2510

using namespace std;

int n;
int ct[MAXH];

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        memset(ct,0,sizeof(ct));
        cin >> n;
        for (int i = 0; i < 2 * n * n - n; i++) {
            int h;
            cin >> h;
            ct[h]++;
        }
        vector<int> ans;
        for (int i = 0; i < MAXH; i++) {
            if (ct[i] % 2 == 1) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());

        cout << "Case #" << TC << ":";
        for (int x : ans) cout << " " << x;
        cout << '\n';
    }
}
