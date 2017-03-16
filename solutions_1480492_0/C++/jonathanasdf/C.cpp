#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

int L = 5, S[50], P[50], idx[50];
typedef long double ld;

int main() {
    int T; cin >> T; 
    for (int zz=1; zz <= T; zz++) {
        int N; cin >> N;
        for (int i=0; i < N; i++) {
            idx[i] = i;
            char C; cin >> C;
            cin >> S[i] >> P[i];
        }
        
        ld ans = 1e13;
        for (int i=0; i < N; i++) {
            for (int j=0; j < N; j++) {
                for (int k=0; k < N; k++) {
                    if (i==j || j==k || i==k) continue;
                    int a = i, b = j, c = k;
                    if (P[a] <= P[b] && P[b] <= P[c] && S[a] >= S[b] && S[b] >= S[c] && S[a] > S[c]) {
                        if (S[b] == S[c] && P[b]+L <= P[c]) {
                            continue;
                        }
                        ld tab1 = P[a]+L < P[b] ? (S[b] == S[a] ? 1e13 : (P[b]-P[a]-L)*1.0/(S[a]-S[b])) : 0;
                        ld tab2 = S[b] == S[a] ? 1e13 : (P[b]+L-P[a])*1.0/(S[a]-S[b]);
                        ld tac1 = P[a]+L < P[c] ? (P[c]-P[a]-L)*1.0/(S[a]-S[c]) : 0;
                        ld tac2 = (P[c]+L-P[a])*1.0/(S[a]-S[c]);
                        
                        if (tac1 >= tab1 && tac1 <= tab2) {
                            ans = min(ans, tac1);
                        } else if (tac1 < tab1 && tab1 <= tac2) {
                            ans = min(ans, tab1);
                        }
                    }
                }
            }
        }
        
        cout << "Case #" << zz << ": ";
        if (ans >= 1e13-1) cout << "Possible" << endl;
        else cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}