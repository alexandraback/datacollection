#include <cstdio>
#include <algorithm>
//#include <iostream>

using namespace std;

void doTest(int tt) {
    printf("Case #%d: ", tt);
    int N, M;
    scanf("%d%d", &N, &M);
    int A[N][M];
    int nn, mm;
    //cerr << "INPUT: " << endl;
    for (nn=0; nn<N; ++nn) {
        for (mm=0; mm<M; ++mm) {
            scanf("%d", &A[nn][mm]);
            //cerr << A[nn][mm] << " ";
        }
        //cerr << endl;
    }

    int rowMax[N];
    int colMax[M];
    for (nn=0; nn<N; ++nn) {
        rowMax[nn] = 0;
    }
    for (nn=0; nn<M; ++nn) {
        colMax[nn] = 0;
    }
    for (nn=0; nn<N; ++nn) {
        for (mm=0; mm<M; ++mm) {
            rowMax[nn] = max(rowMax[nn], A[nn][mm]);
            colMax[mm] = max(colMax[mm], A[nn][mm]);
        }
    }

    /*cerr << " ROW MAX: " << endl;
    for (nn=0; nn<N; ++nn) {
        cerr << " " << nn << " : " << rowMax[nn] << endl;
    }
    cerr << " COL MAX: " << endl;
    for (nn=0; nn<M; ++nn) {
        cerr << " " << nn << " : " << colMax[nn] << endl;
    }*/

    bool notPossible = false;
    for (nn=0; nn<N; ++nn) {
        for (mm=0; mm<M; ++mm) {
            if (A[nn][mm] < rowMax[nn]) {
                if (A[nn][mm] < colMax[mm]) {
                    notPossible = true;
                    break;
                }
            }
        }
        if (notPossible) {
            break;
        }
    }
    if (notPossible) {
        printf("NO");
        //cerr << "NO" << endl;
    } else {
        printf("YES");
        //cerr << "YES" << endl;
    }

    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tt=1; tt<=T; ++tt) {
        doTest(tt);
    }
    return 0;
}

