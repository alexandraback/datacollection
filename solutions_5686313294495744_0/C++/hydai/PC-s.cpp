#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int ans = 0;
        int n;
        cin >> n;
        map<string, int> m[2];
        vector< pair<string, string> > v;
        for (int i = 0; i < n; i++) {
            string f[2];
            for (int j = 0; j < 2; j++) {
                cin >> f[j];
                if (m[j].find(f[j]) == m[j].end())
                    m[j][f[j]] = 1;
                else
                    m[j][f[j]] += 1;
            }
            v.push_back(pair<string, string>(f[0], f[1]));
        }
        for (auto i = v.begin(); i != v.end(); i++) {
            if (m[0][i->first] > 1 && m[1][i->second] > 1) {
                m[0][i->first] -= 1;
                m[1][i->second] -= 1;
                ans ++;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
