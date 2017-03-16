#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cas=1;cas<=t;++cas) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0;i < n; ++i) {
            cin >> v[i];
        }
        cout << "Case #" << cas << ":" << endl;
        vector<vector<int> > used(5000000);
        for (int mask=0;mask<(1<<n);++mask) {
            int s=0;
            for (int j=0;j<n;++j) if ((mask>>j)&1) s+=v[j];
            used[s].push_back(mask);
        }
        bool puc=0;
        for (int i=0;!puc and i<int(used.size());++i) if (used[i].size()>1) {
            puc=1;
            bool primer=1;
            for (int j=0;j<n;++j) if ((used[i][0]>>j)&1) {
                if (primer) {
                    cout << v[j];
                    primer=0;
                }
                else cout << " " << v[j];
            }
            cout << endl;
            
            primer=1;
            for (int j=0;j<n;++j) if ((used[i][1]>>j)&1) {
                if (primer) {
                    cout << v[j];
                    primer=0;
                }
                else cout << " " << v[j];
            }
            cout << endl;

        }
        if (!puc) cout << "Impossible" << endl;
    }
}
