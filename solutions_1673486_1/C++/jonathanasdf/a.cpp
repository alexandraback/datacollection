#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

typedef long double ld;
int main() {
    int T; cin >> T; 
    for (int zz=1; zz <= T; zz++) {
        int A, B; cin >> A >> B;
        
        ld cum[A+1];
        cum[0] = 1;
        for (int i=1; i <= A; i++) {
            ld P; cin >> P;
            cum[i] = cum[i-1] * P;
        }
        
        ld ans = 2+B;
        for (int i=1; i <= A; i++) {
            ans = min(ans, (A-i+B-i+1)*cum[i]+(A-i+B-i+1+B+1)*(1-cum[i]));
        }
        
        cout << fixed << setprecision(6) << "Case #" << zz << ": " << ans << endl;
    }
    return 0;
}