#include<iostream>
using namespace std;

int N, M, a[100][100], A[100][100];

void cutColumn(int j, int h) {
    for (int i=0; i<N; i++)
        A[i][j] = A[i][j]>h? h: A[i][j];
}

void cutRow(int i, int h) {
    for (int j=0; j<M; j++)
        A[i][j] = A[i][j]>h? h: A[i][j];
}

int main () {
    int T;
    cin >> T;
    for (int cas=1; cas<=T; cas++) {
        bool possible=1;
        cin >> N >> M;
        for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            A[i][j]=100;
            cin >> a[i][j];
        }
        /* Cut Row */
        for (int i=0; i<N; i++) {
            int max = 1;
            for (int j=0; j<M; j++)
                max = a[i][j]>max? a[i][j]: max;
            cutRow(i, max);
        }
        /* Cut Column */
        for (int j=0; j<M; j++) {
            int max = 1;
            for (int i=0; i<N; i++)
                max = a[i][j]>max? a[i][j]: max;
            cutColumn(j, max);
        }
        /* Determine */
        for (int i=0; i<N && possible; i++)
        for (int j=0; j<M; j++) {
            if (a[i][j]!=A[i][j]) {
                possible=0;
                break;
            }
        }
        /* End */
        cout << "Case #" << cas << ": ";
        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
    //system("pause");
}
