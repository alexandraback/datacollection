#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> v[n];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int h;
                cin >> h;
                v[j].push_back(h);
            }
        }

        vector<int> hm;
        vector<int> vm;

        for (int j = 0; j < n; j++) {
            int mx = v[j][0];
            for (int k = 1; k < m; k++) {
                if (v[j][k] > mx)
                    mx = v[j][k];
            }
            hm.push_back(mx);
        }

        for (int j = 0; j < m; j++) {
            int mx = v[0][j];
            for (int k = 1; k < n; k++) {
                if (v[k][j] > mx) mx = v[k][j];
            }
            vm.push_back(mx);
        }

        string r = "YES";
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (v[j][k] != hm[j] && v[j][k] != vm[k]) {
                    r = "NO";
                    break;
                }
            }
            if (r == "NO") break;
        }
        cout << "Case #" << i << ": " << r << endl;
    }
}
