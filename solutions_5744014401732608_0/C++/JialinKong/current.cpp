#include <vector>
#include <iostream>
using namespace std;

int main() {
    long long T, B, M;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        cin >> B >> M;
        cout << "Case #" << i << ": ";
        vector<vector<int>> matrix(B, vector<int>(B, 0));
        if (((long long)1 << (B-2)) < M) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            matrix[0][B-1] = 1;
            --M;
            long long k = 1, max = 1;
            while(M != 0) {
                for(int i=0; i<k; ++i)
                    matrix[i][k] = 1;
                if (2*max > M) {
                    int index = 1;
                    while(M != 0) {
                        if (M % 2 != 0)
                            matrix[index][B-1] = 1;
                        M /= 2;
                        ++index;
                    }
                }
                ++k;
                max *= 2;
            }

            for (int ii = 0; ii < B; ++ii) {
                for (int j = 0; j < B; ++j) {
                    cout << matrix[ii][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}