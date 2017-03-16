#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    int case_num;
    long long n, b, m;
    int matrix[50][50];
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++) {
        cout << "Case #" << case_id + 1 << ": ";
        cin >> b >> m;
        if (1 << (b - 2) < m) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            memset(matrix, 0, sizeof(matrix));
            for (int i = 1; i < b - 1; i++) {
                for (int j = 0; j < i; j++) {
                    matrix[j][i] = 1;
                }
            }
            matrix[0][b - 1] = 1;
            m--;
            int pos = 1;
            while (m != 0) {
                if (m % 2 == 1) {
                    matrix[pos][b - 1] = 1;
                }
                pos++;
                m /= 2;
            }
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    cout << matrix[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
