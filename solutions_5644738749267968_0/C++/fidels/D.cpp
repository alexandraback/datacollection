#include <iostream>
using namespace std;

#define MAXN 1024

int cheat(double n[2][MAXN], int N) {
    int i, j;

    for (i=0; i<=N; i++) {
        for (j=i; j<N; j++) if (n[0][j] < n[1][j-i]) break;
        if (j==N) return N-i;
    }
}

int nocheat(double n[2][MAXN], int N) {
    int i=0, j=0, RES=0;

    while (j < N) {
        if (n[0][i] > n[1][j]) j++;
        else {RES++; i++; j++;}
    }
    return N-RES;
}

int main() {
    int t, T, i, j, N;
    double n[2][MAXN];

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> N;
        for (i=0; i<2; i++) {
            for (j=0; j<N; j++) cin >> n[i][j];
            sort(n[i], n[i]+N);

//            for (j=0; j<N; j++) cout << n[i][j] << ' '; cout << endl;
        }
        cout << "Case #" << t << ": " << cheat(n, N) << " " << nocheat(n, N) << endl;
    }

    return 0;
}
