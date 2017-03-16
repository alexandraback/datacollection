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
#define MN 1005
#define max(a, b) return a>b ? a : b
#define min(a, b) return a<b ? a : b
#define FOR(i, n) for(int i=0; i<n; i++) 
using namespace std;

char mem[MN];
int N,A,B,C,D,M,Q,X,Y,T,R,K,L,U,S;

int main(){        
    int i,j,k,tt,a,b,c,s,t,n,d,x,y,r,u,v,p;
    string res;
    scanf("%d\n",&T);
    for (tt = 1; tt <= T; tt++) {
        res = "";
        gets(mem);
        N = strlen(mem);
        FOR(i,N) {
            if(i == 0){
                res += mem[i];
            } else {
                if(res[0] > mem[i]) {
                    res += mem[i];
                } else {
                    res = mem[i] + res;
                }
            }
        }
    
        cout << "Case #" << tt << ": " << res << endl;
        //printf("Case #%d: %d\n",tt,res + 1);
    }
    
    return 0;
}

