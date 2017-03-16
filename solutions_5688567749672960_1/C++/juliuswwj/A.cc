#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;

long long qq(char num[])
{
    int n = 0;
    while(num[n])n++;
    if(n==1)return num[0] - '0';
    
    if(num[n-1] == '0'){
        sprintf(num, "%ld", atol(num)-1);
        return qq(num)+1;
    }
    
    char nnum[20];
    for(int i=0; i<n; i++)nnum[i] = '9';
    nnum[n-1] = 0;
    long long m = qq(nnum)+1;
    
    for(int i=0; i<n/2; i++)nnum[i] = num[n/2-i-1];
    nnum[n/2]=0;
    int a = atoi(nnum);
    
    int p = 0;
    if(n%2){
        nnum[0] = num[n/2];
        for(int i=1; i<=n/2; i++)nnum[i] = '0';
        nnum[n/2+1]=0;
        m += atoi(nnum);
        p += 1;
    }
    
    for(int i=0; i<n/2; i++)nnum[i] = num[n/2+i+p];
    nnum[n/2]=0;
    int b = atoi(nnum);
    
    if(a>1)m++;

    fprintf(stderr, "%s %d %d\n", num, a, b);
    
    return m+a+b-1;
}

void q() {
    char num[20];
    RS(num);
    
    printf("%ld\n", qq(num));
}

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
    }
    return 0;
}