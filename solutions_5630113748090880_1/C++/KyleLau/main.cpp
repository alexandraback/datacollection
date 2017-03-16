#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <climits>
#include "limits.h"
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <map>


#define MaxLength 2147483647
#define INF 0x3f3f3f3f
#define NEG -1
#define MN 2505
#define max(a, b) return a>b ? a : b
#define min(a, b) return a<b ? a : b
#define FOR(i, n) for(int i=0; i<n; i++) 
using namespace std;

int mem[MN];
int N,A,B,C,D,M,Q,X,Y,T,R,K,L,U,S;

int main(){        
    int i,j,k,tt,a,b,c,s,t,n,d,x,y,r,u,v,p;
    int res;
    scanf("%d",&T);
    for (tt = 1; tt <= T; tt++) {
        memset(mem,0,sizeof(mem));
        scanf("%d",&N);
        FOR(i,(2*N)-1) {
            FOR(j, N) {
                scanf("%d",&res);
                mem[res]++;
            }
        }

    
        printf("Case #%d:",tt);
        FOR(i,MN) {
            if(mem[i] % 2) {
                printf(" %d",i);
            }
        }
        puts("");
    }
    
    return 0;
}

