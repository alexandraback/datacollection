#include <stdio.h>

int T, L, S[10001], Check[9];
long long X;
int N, A[160001];
int Multi[9][9]={{0,0,0,0,0,0,0,0,0},
                 {0,1,2,3,4,5,6,7,8},
                 {0,2,5,4,7,6,1,8,3},
                 {0,3,8,5,2,7,4,1,6},
                 {0,4,3,6,5,8,7,2,1},
                 {0,5,6,7,8,1,2,3,4},
                 {0,6,1,8,3,2,5,4,7},
                 {0,7,4,1,6,3,8,5,2},
                 {0,8,7,2,1,4,3,6,5}};
char temp[10002];

int main(void) {

    int i, j, k, x, y;
    long long p, q;

    scanf("%d",&T);
    for(i=1 ; i<=T ; i++) {
        N=0;
        for(j=1 ; j<=8 ; j++) Check[j]=0;
        scanf("%d %lld %s",&L,&X,&temp[1]);
        for(j=1 ; j<=L ; j++) {
            if(temp[j]=='i') S[j]=2;
            else if(temp[j]=='j') S[j]=3;
            else S[j]=4;
        }
        if(X<=16) for(j=1 ; j<=X ; j++) for(k=1 ; k<=L ; k++) A[++N]=S[k];
        else for(j=1 ; j<=16 ; j++) for(k=1 ; k<=L ; k++) A[++N]=S[k];
        x=1;
        for(j=1 ; j<=N ; j++) {
            x=Multi[x][A[j]];
            if(x==2) {
                p=j;
                break;
            }
        }
        if(j==N+1) {
            printf("Case #%d: NO\n",i);
            continue;
        }
        x=1;
        for(j=N ; j>=1 ; j--) {
            x=Multi[A[j]][x];
            if(x==4) {
                q=L*X-N+j;
                break;
            }
        }
        if(j==0) {
            printf("Case #%d: NO\n",i);
            continue;
        }
        x=1;
        for(j=1 ; j<=L ; j++) x=Multi[x][S[j]];
        if(X<=16) {
            y=x;
            for(j=2 ; j<=X ; j++) x=Multi[x][y];
        }
        else {
            y=x;
            Check[x]=1;
            for(j=2 ; j<=16 ; j++) {
                x=Multi[x][y];
                if(Check[x]) {
                    X%=j-1;
                    break;
                }
                else Check[x]=1;
            }
            x=y;
            for(j=2 ; j<=X ; j++) x=Multi[x][y];
        }
        if(p+1>q-1) {
            printf("Case #%d: NO\n",i);
            continue;
        }
        for(j=1 ; j<=8 ; j++)
            if(Multi[2][j]==x) {
                x=j;
                break;
            }
        for(j=1 ; j<=8 ; j++) {
            if(Multi[j][4]==x) {
                x=j;
                break;
            }
        }
        if(x==3) {
            printf("Case #%d: YES\n",i);
            continue;
        }
        else {
            printf("Case #%d: NO\n",i);
            continue;
        }
    }

    return 0;
}
