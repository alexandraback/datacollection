#include<cstdio>
#include<iostream>
using namespace std;
int TC, r, c, m, a, b, d, board[5][5];
bool isbomb[5][5];
int main(){
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc){
        scanf("%d %d %d", &r, &c, &m); m = r*c-m;
        bool found = false;
        if(m == 1 && !found){
            printf("Case #%d:\n", tc);
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(i == 0 && j == 0) printf("c");
                    else printf("*");
                }
                printf("\n");
            }
            found = true;
        }
        //fill col
        if(m/r >= 2 && (m%r >= 2 || m%r == 0) && !found){
            printf("Case #%d:\n", tc);
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(i == 0 && j == 0) printf("c");
                    else if(j < m/r || (j == m/r && i < m%r)) printf(".");
                    else printf("*");
                }
                printf("\n");
            }
            found = true;
        }
        //fill row
        if(m/c >= 2 && (m%c >= 2 || m%c == 0) && !found){
            printf("Case #%d:\n", tc);
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(i == 0 && j == 0) printf("c");
                    else if(i < m/c || (i == m/c && j < m%c)) printf(".");
                    else printf("*");
                }
                printf("\n");
            }
            found = true;
        }
        for(int i = 2; i < r && !found; ++i){
            for(int j = 2; j < c && !found; ++j){
                if(m >= (i+1)*(j+1)) continue;
                if(m < i*j) continue;
                int overflow = m - (i*j), toi, toj;
                if(overflow == 0) toi = toj = 0;
                else if(overflow <= i && overflow > 1){
                    toi = overflow;
                    toj = 0;
                }
                else if(overflow <= j && overflow > 1){
                    toj = overflow;
                    toi = 0;
                }
                else if(overflow >= 4){
                    toi = min(overflow-2, i);
                    toj = overflow - toi;
                }
                else continue;
                found = true;
                //printf("i is %d, j is %d, toi toj %d %d\n", i, j, toi, toj);
                printf("Case #%d:\n", tc);
                for(int k = 0; k < r; ++k){
                    for(int l = 0; l < c; ++l){
                        if(k == 0 && l == 0) printf("c");
                        else if(k < i && l < j) printf(".");
                        else if(j == l && k < toi) printf(".");
                        else if(i == k && l < toj) printf(".");
                        else printf("*");
                    }
                    printf("\n");
                }
            }
        }
        if(!found){
            printf("Case #%d:\nImpossible\n", tc);
        }
    }
    //system("pause");
}
