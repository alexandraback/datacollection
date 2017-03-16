#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

typedef pair<string, string> ss;

vector<ss> suspects;
bool used[50][2];

int main() {
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for(int t = 1; t <= tests; ++t) {
        int n;
        cin >> n;

        suspects.clear();
        suspects.resize(n);
        memset(used, 0, sizeof used);

        for(int i = 0; i < n; ++i) {
            cin >> suspects[i].first;
            cin >> suspects[i].second;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(suspects[i].first == suspects[j].first and !used[j][0]) {
                    used[j][0] = true;
                }
                else if(suspects[i].second == suspects[j].second and !used[j][1]) {
                    used[j][1] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(used[i][0] and used[i][1])
                ans = true;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
