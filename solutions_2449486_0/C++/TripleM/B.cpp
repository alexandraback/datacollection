#include <iostream>
using namespace std;
int grid[100][100];
bool validrow[100], validcol[100];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int N,M; scanf("%d %d",&N,&M);
        for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) scanf("%d",&grid[i][j]);
        
        bool possible = true;
        for (int i=1; i<=99; i++) {
            for (int j=0; j<N; j++) {
                validrow[j] = true;
                for (int k=0; k<M; k++) if (grid[j][k]!=i) validrow[j]=false;
            }
            for (int j=0; j<M; j++) {
                validcol[j] = true;
                for (int k=0; k<N; k++) if (grid[k][j]!=i) validcol[j]=false;
            }
            for (int j=0; j<N; j++)
            for (int k=0; k<M; k++) {
                if (grid[j][k]==i) {
                    if (!validrow[j] && !validcol[k]) {
                        possible = false;
                    }
                    grid[j][k]++;
                }
            }
        }
        printf("Case #%d: %s\n",t,possible?"YES":"NO");
    }
}
