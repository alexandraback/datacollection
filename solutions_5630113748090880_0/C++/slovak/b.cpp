#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxh = 2501;

int freq[Maxh];

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N;
        cin >> N;
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < 2 * N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int x; cin >> x;
                freq[x]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < Maxh; i++) {
            if (freq[i] % 2 != 0) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << tt << ": ";
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}
