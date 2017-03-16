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
#define MN 2005
#define max(a, b) return a>b ? a : b
#define min(a, b) return a<b ? a : b
#define FOR(i, n) for(int i=0; i<n; i++) 
using namespace std;

int mem[MN];
string C,J;
int N,A,B,D,M,Q,X,Y,T,R,K,L,U,S;
struct {
    long long c, j;
} typedef Pair;

Pair getMin(Pair a, Pair b) {
    if(abs(a.c - a.j) < abs(b.c - b.j)) {
        return a;
    } else if(abs(a.c - a.j) > abs(b.c - b.j)) {
        return b;
    } else if(a.c < b.c){
        return a;
    } else if(a.c > b.c){
        return b;
    } else if(a.j < b.j){
        return a;
    } else {
        return b;
    }
}
Pair calc(int i, long long c, long long j) {
    Pair res;
    if(i == L) {
        res.c = c;
        res.j = j;
        return res;
        
    } else if(C[i] == '?' && J[i] == '?') {
        res = calc(i + 1, c*10, j*10);
        if((i +1 <L) && (C[i+1] == '?' && J[i+1] == '?')) {
            
        } else {
            res = getMin(res, calc(i + 1, c*10 +9, j*10));
            res = getMin(res, calc(i + 1, c*10 +1, j*10));
            res = getMin(res, calc(i + 1, c*10 , j*10 +9 ));
            res = getMin(res, calc(i + 1, c*10 , j*10 +1 ));
        }
        return res;
    } else if(C[i] != '?' && J[i] != '?') {
        c = c * 10 + C[i] - '0';
        j = j * 10 + J[i] - '0';
        return calc(i + 1, c, j);
    } else if(C[i] == '?') {
        j = j * 10 + J[i] - '0';
        int newC;
        newC = c * 10 + ((J[i] - '0' - 1 +10)%10);
        res = calc(i + 1, newC, j);
        newC = c * 10 + J[i] - '0';
        res = getMin(res, calc(i + 1, newC, j));
        newC = c * 10 + ((J[i] - '0' + 1)%10);
        res = getMin(res, calc(i + 1, newC, j));
        newC = c * 10 + 9;
        res = getMin(res, calc(i + 1, newC, j));
        newC = c * 10;
        res = getMin(res, calc(i + 1, newC, j));
        return res;
    } else {
        c = c * 10 + C[i] - '0';
        long long newJ;
        newJ = j * 10 + ((C[i] - '0' -1 + 10) % 10);
        res = calc(i + 1, c, newJ);
        
        newJ = j * 10 + C[i] - '0';
        res = getMin(res, calc(i + 1, c, newJ));
        newJ = j * 10 + ((C[i] - '0' +1) % 10);
        res = getMin(res, calc(i + 1, c, newJ));
        newJ = j * 10 + 9;
        res = getMin(res, calc(i + 1, c, newJ));
        newJ = j * 10 + 0;
        res = getMin(res, calc(i + 1, c, newJ));
        return res;
        
    }
}
int main(){        
    int i,j,k,tt,c,s,t,n,d,x,y,r,u,v,p;
    scanf("%d\n",&T);
    for (tt = 1; tt <= T; tt++) {
        memset(mem, 0, sizeof(mem));
        cin >> C >> J;
        L = C.length();
        Pair res = calc(0, 0, 0);
        printf("Case #%d: ",tt);
        cout << setfill('0') << std::setw (L) << res.c << " " << std::setw (L) << res.j << std::endl;
        //printf("Case #%d: %d %d\n",tt,res.c,res.j);
    }
    
    return 0;
}

