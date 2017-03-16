#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MOD 1000000007

using namespace std;

string s[20];
int c[2000];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("fairphoto.in", "r", stdin);
    //freopen("fairphoto.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<int> a;
        int k = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            a.push_back(i);
        }
        do {
            for (int i = 'a'; i <= 'z'; i++) c[i] = -1;
            //for (int i = 0; i < n; i++) {
            //    cout << a[i] << " ";
            //}
            //cout << endl;
            bool good = true;
            int pos = -1;
            for (int ii = 0; ii < n; ii++) {
                int i = a[ii];
                if (good == false) break;
                for (int j = 0; j < s[i].size(); j++) {
                    pos++;
                    if (c[s[i][j]] == -1) c[s[i][j]] = pos; else {
                        if (c[s[i][j]] != pos-1) {
                            good = false;
                            //cout << i << " " << j << " BAD\n";
                            break;
                        } else c[s[i][j]] = pos;
                    }
                }
            }
            if (good) {
                k++;
                //cout << "HI\n";
            }
        } while (next_permutation(a.begin(), a.end()));
        cout << k << endl;
    }
    return 0;
}
