#include <cstdio>

int main() {
scanf("%*d");
printf("Case #1:\n");
    int r, n, m, k; scanf("%d %d %d %d", &r, &n, &m, &k);
    for(int i=0; i<r; i++) {
        int product[500];
        for(int j=0; j<500; j++) product[j]=0;
        for(int j=0; j<k; j++) {
            int x; scanf("%d", &x);
            product[x]++;
        }
        int best=0;
        int A, B, C;
        for(int a=2; a<=m; a++) {
            for(int b=2; b<=m; b++) {
                for(int c=2; c<=m; c++) {
                    int score=0;
                    bool f = false;
                    for(int j=0; j<500; j++) {
                        if(product[j]>0) {
                            if(j==1 or j==a or j==b or j==c or j==a*b or j==a*c or j==c*b or j==a*b*c);
                            else f=true;
                        }
                    }
                    if(f) continue;
                    for(int aa=0; aa<2; aa++) {
                        for(int bb=0; bb<2; bb++) {
                            for(int cc=0; cc<2; cc++) {
                                score += product[(aa?a:1)*(bb?b:1)*(cc?c:1)];
                            }
                        }
                    }
                    if(score>best) {
                        best=score;
                        A=a;
                        B=b;
                        C=c;
                    }
                }
            }
        }
        printf("%d%d%d\n", A, B, C);
    }
}
                    

