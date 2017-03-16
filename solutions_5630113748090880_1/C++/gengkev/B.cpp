#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        
        int heights[4096] = {0};
        for (int i = 0; i < 2*N-1; i++) {
            for (int j = 0; j < N; j++) {
                int x; cin >> x;
                heights[x]++;
                //cerr << ' ' << x;
            }
            //cerr << endl;
        }

        int out[64] = {0};
        int p = 0;
        for (int i = 0; i < 4096; i++) {
            if (heights[i] % 2 == 1) {
                out[p++] = i;
                //cerr << i << ' ' << heights[i] << endl;
            }
        }
        
        if (p != N) {
            cerr << "error at t=" << t << endl;
        }
        
        cout << "Case #" << t << ":";
        for (int i = 0; i < N; i++) {
            cout << ' ' << out[i];
        }
        cout << endl;
    }
}