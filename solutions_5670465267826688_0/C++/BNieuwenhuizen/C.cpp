#include <iostream>
#include <string>
#include <vector>
using namespace std;


int map(char c) { 
    switch(c) {
        case '1': return 0;
        case 'i': return 1;
        case 'j': return 2;
        case 'k': return 3;
    }
}

// negative is ^ 4
int const multTable[4][4] = {
    {0,1,2,3},
    {1,4,3,6},
    {2,7,4,1},
    {3,2,5,4},
};
int mult(int a, int b) {
    return multTable[a & 3][b & 3] ^(a & 4) ^ (b & 4);
}
int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        long long L, X; string s;
        cin >> L >> X >> s;
        if(X > 12)
            X = 12 + (X % 12);
        int state = 0;
        int m = 0;
        for(int i = 0; i < X; ++i) {
            for(int j = 0; j < L; ++j) {
                m = mult(m, map(s[j]));
                if(state == 0 && m == 1) { state = 1; m = 0; }
                if(state == 1 && m == 2) { state = 2; m = 0; }
                if(state == 2 && m == 3) { state = 3; m = 0; }
            }
        }
        bool result = m == 0 && state == 3;
        
        cout << "Case #" << i << ": " << (result ? "YES" : "NO") << "\n";
    }
}