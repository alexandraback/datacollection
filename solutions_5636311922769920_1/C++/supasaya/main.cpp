#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T, K, C, S;

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        cin >> K >> C >> S;
        if (C == 1) {
            if (S < K) {
                cout << "Case #" << TC << ": IMPOSSIBLE" << endl;
            } else {
                cout << "Case #" << TC << ": ";
                for (int i = 1; i <= S; i++) {
                    cout << i << " ";
                }
                cout << endl;
            }
        } else {
            if (S < (K+1)/2) {
                cout << "Case #" << TC << ": IMPOSSIBLE" << endl;
            } else {
                cout << "Case #" << TC << ": ";
                for (int i = 1; i <= K; i+=2) {
                    if (C == 2 && i == K) {
                        cout << (i-1)*K+1;
                    } else {
                        cout << (i-1)*K+i+1 << " ";
                    }
                    
                }
                cout << endl;
            }
        }
        
    }
    return 0;
}
