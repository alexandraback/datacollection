#define SCTOR
#include "../template/codejam-dsl.hpp"

int N, M[1000][1000], nb[1000], w[1000];

void run() {
    N = rdi();
    P1(N); PNL();
    FZ(i,N) {
        FZ(j,N) M[i][j] = 0;
        nb[i] = rdi();
        P1(nb[i]); 
        FZ(j,nb[i]) {
            int fi = rdi() - 1;
            P1(fi); 
            M[i][fi] = 1;
            //nd[fi] += 1;
        }
        PNL();
    }

    if (db) {
        FZ(q,N) fprintf(stderr, "%c ", 'A' + q); PNL();
        FZ(q,N) fprintf(stderr, "%d ", nb[q]); PNL();
        //FZ(q,N) fprintf(stderr, "%d ", nd[q]); PNL();
        PNL();
    }

    FZ(i,N) if (nb[i] > 1) {
        memset(w, 0, sizeof(int)*N);
        w[i] = 1;
        FE(s,2,N+2) {

            if (db) {
                P1(i); P1(s);  PNL();
                FZ(q,N) fprintf(stderr, "%c ", 'A' + q); PNL();
                FZ(q,N) fprintf(stderr, "%d ", w[q]); PNL();
            }

            bool f = false;
            FZ(j,N) if (w[j] == s-1) {
                FZ(k,N) if (M[j][k]) {
                    if (w[k]) {
                        printf("Yes");
                        return;
                    }
                    w[k] = s;
                    if (!f) f = true;
                }
            }

            if (db) {
                FZ(q,N) fprintf(stderr, "%d ", w[q]); PNL();
                PNL();
            }

            if (!f) break;
        }
    }
    printf("No");
}

void sctor()
{
}
