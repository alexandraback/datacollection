#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
unsigned long long int tt, te, n, m, a[111], A[111], b[111], B[111], j, d, t, res;
 
int main () {
      
        cin >> te;
        while (te--) {
                cin >> n >> m;
                for (int i=1; i<=n; i++) {
                        cin >> a[i] >> A[i];
                        if (i > 1 && A[i] == A[i-1]) {
                                n--;
                                a[i-1] += a[i];
                        }
                }
                while (n < 3) {
                        n++;
                        a[n] = 0;
                        A[n] = -n;
                }
                for (int i=1; i<=m; i++) {
                        cin >> b[i] >> B[i];
                }
                //cout << "hehe\n";
                for (int aa=1; aa<=m; aa++)
                        for (int bb=aa; bb<=m; bb++) {
                                j = d = t = 0;
                                if (aa == bb && A[1] == A[3]) {
                        //              cout << "hehe\n";
                                        for (int i=1; i<=m; i++)
                                                if (B[i] == A[1])
                                                        j+=b[i];
                        //              cout << j << " " << a[1] + a[3] << endl;
                                        res = max(res, min(j, a[1] + a[3]));
                                }
                                else {
                                        for (int i=1; i<=aa; i++)
                                                if (B[i] == A[1])
                                                        j += b[i];
                                        for (int i=aa+1; i<=bb; i++)
                                                if (B[i] == A[2])
                                                        d += b[i];
                                        for (int i=bb+1; i<=m; i++)
                                                if (B[i] == A[3])
                                                        t += b[i];
                                        res = max(res, min(j, a[1]) + min(d, a[2]) + min(t, a[3]));
                                }
                        }
                cout << "Case #" << ++tt << ": " << res << endl;
 
                res = 0;
        }
}
