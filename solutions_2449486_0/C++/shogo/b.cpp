#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int no = 1; no <= N; no++) {
        int N, M;
        int i, j;
        int a[100][100];
        bool flag[100][100];
        cin >> N >> M;
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                cin >> a[i][j];
                flag[i][j] = false;
            }
        }

        // row
        for(i = 0; i < N; i++) {
            int m = 0;
            for(j = 0; j < M; j++) {
                if(a[i][j] > m) m = a[i][j];
            }
            for(j = 0; j < M; j++) {
                if(a[i][j] == m) flag[i][j] = true;
            }
        }

        // column
        for(j = 0; j < M; j++) {
            int m = 0;
            for(i = 0; i < N; i++) {
                if(a[i][j] > m) m = a[i][j];
            }
            for(i = 0; i < N; i++) {
                if(a[i][j] == m) flag[i][j] = true;
            }
        }

        // check
        bool ans = true;
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                if(!flag[i][j]) ans = false;
            }
        }

        cout << "Case #" << no << ": ";
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
