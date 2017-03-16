#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    double eps = 1e-9;
    fp >> T;
    for(int k = 1; k <= T; k++) {
        long long n, d[500001], m[500001], c = 0, res = 0;
        fp >> n;
        for (ll i = 0; i < n; i++) {
            int dd, h, mm;
            fp >> dd >> h >> mm;
            for (ll j = 0; j < h; j++)
                d[c] = dd, m[c] = mm + j, c++;
        }
        if (c == 2) {
            if (d[0] > d[1]) swap(d[0], d[1]), swap(m[0], m[1]);
            if (m[0] < m[1]) {
                ll t1 = (360 - d[1]) * m[1];
                ll t0 = (720 - d[0]) * m[0];
                //cout << "first " << t0 << " " << t1 << endl;
                if (t0 <= t1) res = 1;
            } else if (m[0] > m[1]) {
                ll t1 = (720 - d[1]) * m[1];
                ll t0 = (double) (360 - d[0]) * m[0];
                if (t1 <= t0) res = 1;
                //cout << "second " << t0 << " " << t1 << endl;

            }
            
        }
        ofp << "Case #" << k << ": " << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
