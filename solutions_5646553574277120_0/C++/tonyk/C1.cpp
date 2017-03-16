#include <iostream>

using namespace std;

int main() {
    int t, c, d, v, res;
    int i, j, k, sn, tmp, ss;
    int sums[200];
    int cs[10];
    bool ok;
    
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> c >> d >> v;
        sn = 1;
        for (j = 0; j < d; j++) {
            sn *= 2;
            cin >> cs[j];
        }

        res = 0;
        while (true) {
            for (j = 0; j < 200; j++) {
                sums[j] = 0;
            }
            
            sn = 1;
            for (j = 0; j < d; j++) sn*=2;
            
            for (j = 0; j < sn; j++) {
                ss = 0;
                tmp = j;
                for (k = 0; k < d; k++) {
                    if (tmp % 2 == 1) ss += cs[k];
                    if (ss > v) break;
                    tmp >>= 1;
                }
                sums[ss]++;
            }

            ok = true;
            for (j = 1; j <= v; j++) {
                if (sums[j] == 0) {
                    ok = false;
                    res++;
                    d++;
                    cs[d-1] = j;
                    break;
                }
            }
            if (ok) break;
        }
        
        cout << "Case #" << i+1 << ": " << res << endl;
        
    }
    
    
    return 0;
}
