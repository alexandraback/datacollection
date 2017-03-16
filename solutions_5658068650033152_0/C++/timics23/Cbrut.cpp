#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
int T,N,M,K;

int main() {
    freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d: ",t);
        scanf("%d%d%d",&N,&M,&K);
        if(N<=2 || M<=2) {
            printf("%d\n",K);
            continue;
        }

        if(M<=N) {
            int x = N;
            N=M;
            M=N;
        }

        if(N==3 && M==3) {
            if(K<=4) {
                printf("%d\n",K);
            }
            if(K>=5) {
                printf("%d\n",K-1);
            }
        }

        if(N==3 && M==4) {
            if(K<=4) {
                printf("%d\n",K);
            }
            else if(K==5) {
                printf("%d\n",4);
            } else if(K<=8) {
                printf("%d\n",6);
            } else {
                printf("%d\n",K-2);
            }
        }

        if(N==3 && M==5) {
            if(K<=4) {
                printf("%d\n",K);
            }
            else if(K==5) {
                printf("%d\n",4);
            } else if(K<=8) {
                printf("%d\n",6);
            } else if(K<=11) {
                printf("%d\n",8);
            } else {
                printf("%d\n",K-3);
            }
        }

        if(N==3 && M==6) {
            if(K<=4) {
                printf("%d\n",K);
            }
            else if(K==5) {
                printf("%d\n",4);
            } else if(K<=8) {
                printf("%d\n",6);
            } else if(K<=11) {
                printf("%d\n",8);
            } else if(K<=14) {
                printf("%d\n",10);
            } else {
                printf("%d\n",K-4);
            }
        }

        if(N==4 && M==4) {
            if(K<=4) {
                printf("%d\n",K);
            }
            else if(K==5) {
                printf("%d\n",4);
            } else if(K<=8) {
                printf("%d\n",6);
            } else if(K<=10) {
                printf("%d\n",7);
            } else if(K<=11) {
                printf("%d\n",10);
            } else {
                printf("%d\n",K-4);
            }
        }

        if(N==4 && M==5) {
                        if(K<=4) {
                printf("%d\n",K);
            }
            else if(K==5) {
                printf("%d\n",4);
            } else if(K<=8) {
                printf("%d\n",6);
            } else if(K<=10) {
                printf("%d\n",7);
            } else if(K<=14) {
                printf("%d\n",9);
            } else {
                printf("%d\n",K-5);
            }
        }


       // printf("%d\n",N);
    }
    return 0;
}


