#include <iostream>
#include <string>
using namespace std;
const int MAXH = 2500;

bool heights[MAXH+1];

int main() {
    int T, N, h;
    cin >> T;
    for (int i=1; i<=T; ++i) {
        cin >> N;
        memset(heights, 0, sizeof(heights));
        for (int j=2*N-1; j>0; --j) {
            for (int k=0; k<N; ++k) {
                cin >> h;
                heights[h] = !heights[h];
            }
        }
        cout << "Case #" << i << ":";
        for (int a=1; a<=MAXH && N>0; ++a) if (heights[a]) {
            --N;
            cout << " " << a;
        }
        cout << endl;
    }
    return 0;
}
