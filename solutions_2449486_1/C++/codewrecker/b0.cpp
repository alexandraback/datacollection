#include <iostream>

using namespace std;

int lawn[100][100];
int row_max[100];
int col_max[100];

int main()
{
    int T, tcnt = 0;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            int r_max = 0;
            for (int j = 0; j < M; ++j) {
                cin >> lawn[i][j];
                if (lawn[i][j] > r_max)
                    r_max = lawn[i][j];
            }
            row_max[i] = r_max;
        }
        for (int col = 0; col < M; ++col) {
            int c_max = 0;
            for (int row = 0; row < N; ++row) {
                if (lawn[row][col] > c_max)
                    c_max = lawn[row][col];
            }
            col_max[col] = c_max;
        }
        bool could = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int h = min(row_max[i], col_max[j]);
                if (lawn[i][j] < h) {
                    //cout << i << "-" << j << " " << lawn[i][j] << " " << h << endl;
                    could = false;
                    goto end;
                }
            }
        }
        end:
        cout << "Case #" << ++tcnt << ": ";
        if (could)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

