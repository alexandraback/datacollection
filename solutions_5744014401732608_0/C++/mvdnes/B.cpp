#include <iostream>
#include <vector>

using namespace std;

void doit() {
    vector<char> bits(64, 0);
    long long B, M;
    cin >> B >> M;
    
    long long maxi = 0;
    for (long long i = 0; 1LL << i <= M; ++i) {
        if ((1LL << i) & M) {
            bits[i+1] = 1;
            maxi = i+1;
        }
    }
   
    //cerr << endl << B << ' ' << M << endl;
    //cerr << "maxi: " << maxi << endl;
    bool possible = true;
    if (maxi == B-1) {
        for (long long i = 1; i < B-1; ++i) {
            if (bits[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (long long i = 0; i < B; ++i) {
                bits[i] = 1;
            }
            bits[B-1] = 0;
        }
    }

    if (maxi >= B || !possible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
  
    for (int i = 0; i < B-1; ++i) {
        for (int j = 0; j < B; ++j) {
            if (j > i && (j != (B-1) || bits[i])) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        cout << '\n';
    }
    for (int j = 0; j < B; ++j) {
        cout << '0';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        doit();
    }
    return 0;
}
