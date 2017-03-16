#include <iostream>
#include <string> 

using namespace std;

int main () {
	int T; 
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int K, C, S;
    	cin >> K >> C >> S;
    	cout << "Case #" << t << ": ";
        if (S * C < K) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int s = 0; s < S; s++) {
                if (s > 0 && s*C % K == 0) {
                    break;
                }
                long i = 0;
                long v = 1;
                for (int j = 0; j < C; j++) {
                    i += v * ((s*C + j) % K);
                    v *= K;
                } 
                i += 1;
                cout << i << ' ';
            }
            cout << endl;
        }
    }
}