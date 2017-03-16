#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>
#include <unistd.h> 

int N;
int ar[1000][10];
int ar_c[1000];
int ar_i[1000];// buf inh

int test(int ti){
    int i;
    for(i = 0; i< N; i++){ // clear
        ar_i[i] = 0;
    };
    return set_i(ti);
}

int set_i(int ti){
    if (ar_i[ti] == 1) return 1;
    else
        ar_i[ti] = 1;
    int i, a;
    for (i = 0;i<ar_c[ti];i++){
        a = set_i(ar[ti][i]);
        if (a == 1) return 1;
    }
    return 0;
}

line(int ii){
       scanf("%d",&N); // count class
    int i;
    int j;
    for (i = 0; i<N; i++){ // load
        scanf("%d",&ar_c[i]); // inherited count
        for(j=0;j<ar_c[i];j++){
            scanf("%d",&ar[i][j]);
            ar[i][j] = ar[i][j] - 1;
        }
    }
    // analis
    for(i = 0; i< N; i++){
        if (ar_c[i]>1) // больше 1 ветвления
          if (test(i)==1) {
                printf("Yes");
                return 1;
          }
    };
    printf("No");
}

main(){
    int T = 0;
    scanf("%d",&T);
    int i;
    for (i = 0; i<T; i++){
        printf("Case #%d: ",i+1);
        line(i);   
        printf("\n");
    }
}
