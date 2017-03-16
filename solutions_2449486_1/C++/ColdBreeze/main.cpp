#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("in_codejam");
    ofstream cout("out_codejam");
    int T, n, m, arr[110][110], cases=0;
    bool win;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> arr[i][j];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                win = true;
                for (int k=0; k<m; ++k) {if (arr[i][k]>arr[i][j]) {win = false;break;}}
                if (win) continue;
                win = true;
                for (int k=0; k<n; ++k) {if (arr[k][j]>arr[i][j]) {win = false;break;}}
                if (!win) break;
            }
            if (!win) break;
        }
        if (win) cout << "Case #" << (++cases) << ": YES" << endl;
        else cout << "Case #" << (++cases) << ": NO" << endl;
    }
    return 0;
}
