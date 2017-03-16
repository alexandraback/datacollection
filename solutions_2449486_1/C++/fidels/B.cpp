#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i, j, t, T, N, M, max_row[128], max_col[128], a[128][128];
    bool FLAG;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N >> M;

        memset(max_row, 0, sizeof(max_row));
        memset(max_col, 0, sizeof(max_col));
        for (i=0; i<N; i++) for (j=0; j<M; j++) {
            cin >> a[i][j];
            max_row[i] = max(max_row[i], a[i][j]);
            max_col[j] = max(max_col[j], a[i][j]);
        }

        FLAG = true;
        for (i=0; i<N; i++) for (j=0; j<M; j++) if (a[i][j] < max_row[i] && a[i][j] < max_col[j]) FLAG = false;

        cout << "Case #" << t << ": ";
        if (FLAG) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
