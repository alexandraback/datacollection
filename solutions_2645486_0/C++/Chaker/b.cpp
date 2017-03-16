#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define pb push_back
#define sz(v) (int(v.size()))
#define mp make_pair

vector <vector <int> > D;
vector <int> v;
int n, E, R;

int main()
{
    int TEST = 0;
    cin >> TEST;
    for (int test = 1; test <= TEST; ++test) {
        //---code here---
        cin >> E >> R >> n;
        v.resize(n);
        D.clear();
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        D.resize(n + 1);
        
        for (int i = 0; i < n + 1; ++i) {
            D[i].resize(E + 1, -1000000000);
        }
        
        D[0][E] = 0;
        /*
        for (int d = 0; d < n; ++d) {
            for (int e = 0; e <= E; ++e) {
                cout << D[d][e] << "\t";
            }
            cout << endl;
        }
        */
        //cout << "-------------------------------------\n";
        for (int d = 0; d < n; ++d) {
            for (int e = 0; e <= E; ++e) {
                for (int use = 0; use <= e; ++use) {
                    int new_E = min(E, e - use + R);
                    D[d + 1][new_E] = max(D[d + 1][new_E], D[d][e] + use * v[d]);
                }
            }
        }
        /*
        for (int d = 0; d < n; ++d) {
            for (int e = 0; e <= E; ++e) {
                cout << D[d][e] << "\t";
            }
            cout << endl;
        }
        */

        int ans = 0;
        for (int e = 0; e <= E; ++e) {
            ans = max(ans, D[n][e]);
        }
        cout << "Case #" << test <<": " << ans << endl;
    }
    return 0;
}