#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const char* OUTFIT[27] ={"000", "001", "002", "010", "011", "012", "020", "021", "022",
                   "100", "101", "102", "110", "111", "112", "120", "121", "122",
                   "200", "201", "202", "210", "211", "212", "220", "221", "222" };

int A, B, C, K;
unsigned p;

int AB[3][3];
int BC[3][3];
int AC[3][3];

unsigned bestp;
int bestcnt;

int result[3][3][3][11];
int resultp[3][3][3][11];

int main() {
    
    
    for (p=0; p<(1<<27); p++) {
        
        int A=0, B=0, C=0, K=0;
        
        for (int i=0; i<3; i++) for (int j=0; j<3; j++) AB[i][j] = AC[i][j] = BC[i][j] = 0;
        K = 0;
        int cnt = 0;
        
        for (int i=0; i<27; i++) {
            if ((p & (1<<i))==0) continue;
            cnt++;
            int a = OUTFIT[i][0]-'0';
            int b = OUTFIT[i][1]-'0';
            int c = OUTFIT[i][2]-'0';
            A = max(A, a);
            B = max(B, b);
            C = max(C, c);
            ++AB[a][b];
            ++AC[a][c];
            ++BC[b][c];
            K = max(K, max(AB[a][b], max(AC[a][c], BC[b][c])));
        }
        
        for (int a=A; a<3; a++)
            for (int b=B; b<3; b++)
                for (int c=C; c<3; c++)
                    for (int k=K; k<11; k++)
                        if (result[a][b][c][k] < cnt)
                            result[a][b][c][k] = cnt, resultp[a][b][c][k] = p;
    }
    cerr<<"ready."<<endl;
        
    int Z; scanf("%d", &Z);
    for (int z=1; z<=Z; z++) {
        int A, B, C, K;
        scanf("%d%d%d%d", &A, &B, &C, &K); A--, B--, C--;
        
        printf("Case #%d: %d\n", z, result[A][B][C][K]);
        for (int i=0; i<27; i++) {
            if ((resultp[A][B][C][K] & (1<<i))==0) continue;
            printf("%d %d %d\n", OUTFIT[i][0]-'0'+1, OUTFIT[i][1]-'0'+1, OUTFIT[i][2]-'0'+1);
        }
    }
    return 0;
}
