#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        int k, l, s;
        cin >> k >> l >> s;
        double ans = 0;
        vector < int > n_let (26, 0);
        string d;
        
        cin >> d;
        //cout << d << endl;
        for (int i = 0; i < k; ++i) {
            ++n_let[d[i] - 'A'];
        }    
        cin >> d;
        bool possib = true;
        for (int i = 0; i < l; ++i) {
            if (n_let[d[i] - 'A'] == 0) {
                possib = false;
            }
        }
        //cout << d << endl;
        vector < double > ver (26);
        for (int i = 0; i < 26; ++i) {
            ver[i] = (double) n_let[i] / (double) k;
        }
        //cout << "lol" << endl;
        //cout << d;
        vector < double > mat[l];
        for (int i = 0; i < l; ++i) {
            mat[i].resize(s, 0);
        }

        for (int i = 0; i < s; ++ i) {
            mat[0][i] = ver[d[0] - 'A'];
        }
        for (int i = 1; i < l; ++i) {
            mat[i][0] = 0;
        }

        for (int i = 1; i < l; ++i) {
            for (int j = 1; j < s; ++j) {
                mat[i][j] = ver[d[i] - 'A'] * mat[i - 1][j - 1];
            }
        }
        for (int i = 0; i < s; ++i) {
            ans += mat[l - 1][i];
        }

        int com = 0;
        vector < int > z (l, 0);
        for (int i = 0; i < l; ++i) {
            for (; d[z[i]] == d[i + z[i]] && i + z[i] < l; ++z[i]);
        }
        z[0] = 0;
        for (int i = 0; i < l; ++i) {
            if (z[i] == l - i) {
                com = z[i];
                break;
            }
            //break;
        }
        //cout << com << " ";
        int mx = 0;
        if (s >= l) {
            mx = 1;
            int ds = s - l;
            mx += ds / (l - com);
        }

        if (!possib) {
            mx = 0;
        }
         
        cout << "Case #" << q << ": ";
        printf("%.13lf\n", (double) mx - ans);
    }
    return 0;
}