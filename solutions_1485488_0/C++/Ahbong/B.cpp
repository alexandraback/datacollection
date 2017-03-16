#include <cstdio>
#include <algorithm>
using namespace std;

const int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int T;
int H, N, M, C[100][100], F[100][100];
int S[100][100];

inline bool valid(int r, int c) {
    return r>=0 && r<N && c>=0 && c<M;
}

void calc(int r=0, int c=0) {
    if(r==0 && c==0) {
        S[r][c] = 0;
    }
    for(int i=0; i<4; ++i) {
        int nr = r + di[i][0];
        int nc = c + di[i][1];
        if(valid(nr, nc)) {
            if(C[nr][nc]-F[nr][nc]>=50 &&
               C[r][c]  -F[nr][nc]>=50 &&
               C[nr][nc]-F[r][c]  >=50) { // dist of floor and ceiling is larger than 50 cm
                if(S[r][c]==0) { // find starting point
                    if(C[nr][nc]-max(H, F[nr][nc])>=50 &&
                       C[r][c]  -max(H, F[nr][nc])>=50 &&
                       C[nr][nc]-max(H, F[r][c])>=50 && (S[nr][nc]>0 || S[nr][nc]==-1)) {
                        S[nr][nc] = 0;
                        calc(nr, nc);
                    }
                }
                // not starting point, need to between water level and time
                int nt = S[r][c];
                int nH = H - nt;
                while(C[nr][nc]-max(nH, F[nr][nc])<50 ||
                      C[r][c]  -max(nH, F[nr][nc])<50 ||
                      C[nr][nc]-max(nH, F[r][c])<50) {
                    ++nt;
                    --nH;
                }
                int tmp = nt + ((nH-F[r][c]>=20)?10:100);
                if(S[nr][nc]==-1 || tmp<S[nr][nc]) {
                    S[nr][nc] = tmp;
                    calc(nr, nc);
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        scanf("%d %d %d", &H, &N, &M);
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                scanf("%d", &C[i][j]);
            }
        }
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                scanf("%d", &F[i][j]);
            }
        }
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                S[i][j] = -1;
            }
        }
        calc();
        printf("Case #%d: %f\n", z, S[N-1][M-1]/10.0);
    }
    return 0;
}
