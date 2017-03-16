#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int senate[28];
int graph[51][51];
int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int B,M;
        scanf("%d %d",&B,&M);
        for(int i=1;i<=B;++i){
            for(int j=1;j<=B;++j){
                graph[i][j]=0;
            }
        }
        printf("Case #%d: ",cs++);
        if(B==2){
            if(M>1){
                printf("IMPOSSIBLE\n");
            }
            else{
                printf("POSSIBLE\n");
                printf("01\n00\n");
            }
        }
        else if(B==3){
            if(M>2){
                printf("IMPOSSIBLE\n");
            }
            else{
                printf("POSSIBLE\n");
                if(M>=1){
                    graph[1][B]=1;
                }
                if(M>=2){
                    graph[1][2]=1;
                    graph[2][3]=1;
                }
                for(int i=1;i<=B;++i){
                    for(int j=1;j<=B;++j){
                        printf("%d",graph[i][j]);
                    }
                    printf("\n");
                }

            }
            }
            else if(B==4){
                if(M>4){
                    printf("IMPOSSIBLE\n");
                }
                else{
                    printf("POSSIBLE\n");
                    if(M>=1){
                        graph[1][B]=1;
                    }
                    if(M>=2){
                        graph[1][2]=1;
                        graph[2][B]=1;
                    }
                    if(M>=3){
                        graph[1][3]=1;
                        graph[3][B]=1;
                    }
                    if(M>=4){
                        graph[2][3]=1;
                    }
                    for(int i=1;i<=B;++i){
                    for(int j=1;j<=B;++j){
                        printf("%d",graph[i][j]);
                    }
                    printf("\n");
                    }
                }
            }
            else if(B==5){
                if(M>8){
                    printf("IMPOSSIBLE\n");
                }
                else{
                    printf("POSSIBLE\n");
                    if(M>=1){
                        graph[1][B]=1;
                    }
                    for(int i=2;i<=M && i<=(B-1);++i){
                        graph[1][i]=1;
                        graph[i][B]=1;
                    }
                    if(M>=5){
                        graph[2][3]=1;
                    }
                    if(M>=6){
                        graph[2][4]=1;
                    }
                    if(M>=7){
                        graph[3][4]=1;
                        graph[2][5]=0;

                    }
                    if(M>=8){
                        graph[2][5]=1;
                    }
                    for(int i=1;i<=B;++i){
                        for(int j=1;j<=B;++j){
                            printf("%d",graph[i][j]);
                        }
                        printf("\n");
                    }

                }

            }
            else if(B==6){
                if(M>16){
                    printf("IMPOSSIBLE\n");
                }
                else{
                    printf("POSSIBLE\n");
                    if(M>=1){
                        graph[1][B]=1;
                    }
                    for(int i=2;i<=M && i<=(B-1);++i){
                        graph[1][i]=1;
                        graph[i][B]=1;
                    }
                    if(M>=6){
                        graph[2][3]=1;
                    }
                    if(M>=7){
                        graph[2][4]=1;
                    }
                    if(M>=8){
                        graph[2][5]=1;
                    }
                    if(M>=9){
                        graph[3][4]=1;
                        graph[2][6]=0;
                    }
                    if(M>=10){
                        graph[2][6]=1;
                    }
                    if(M>=11){
                        graph[3][5]=1;
                        graph[2][6]=0;
                    }
                    if(M>=12){
                        graph[2][6]=1;
                    }
                    if(M>=13){
                        graph[4][5]=1;
                        graph[2][6]=0;
                        graph[3][6]=0;
                    }
                    if(M>=14){
                        graph[2][6]=1;
                    }
                    if(M>=15){
                        graph[3][6]=1;
                        graph[2][6]=0;
                    }
                    if(M>=16){
                        graph[2][6]=1;
                    }
                    for(int i=1;i<=B;++i){
                        for(int j=1;j<=B;++j){
                            printf("%d",graph[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
        }
            return 0;
    }


