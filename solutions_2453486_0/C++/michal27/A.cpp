#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

char A[15][15];
bool x,o;

void riadok(int a) {
    int oo=0,xx=0;
    for(int i=0; i<4; i++) 
        if(A[a][i]=='O') oo++;
        else if(A[a][i]=='X') xx++;
        else if(A[a][i]=='T') {oo++; xx++;}
    if(oo==4) o=true;
    if(xx==4) x=true;
}

void stlpec(int a) {
    int oo=0,xx=0;
    for(int i=0; i<4; i++) 
        if(A[i][a]=='O') oo++;
        else if(A[i][a]=='X') xx++;
        else if(A[i][a]=='T') {oo++; xx++;}
    if(oo==4) o=true;
    if(xx==4) x=true;
}

void diag1() {
    int oo=0,xx=0;
    for(int i=0; i<4; i++) 
        if(A[i][i]=='O') oo++;
        else if(A[i][i]=='X') xx++;
        else if(A[i][i]=='T') {oo++; xx++;}
    if(oo==4) o=true;
    if(xx==4) x=true;
}

void diag2() {
    int oo=0,xx=0;
    for(int i=0; i<4; i++) 
        if(A[i][3-i]=='O') oo++;
        else if(A[i][3-i]=='X') xx++;
        else if(A[i][3-i]=='T') {oo++; xx++;}
    if(oo==4) o=true;
    if(xx==4) x=true;
}

int main() {
    int t;
    scanf("%d ",&t);
    For(i1,t) {
        For(i,4) scanf("%s ",A[i]);
        x=false; o=false;
        bool bod=false;
        For(i,4) For(j,4) if(A[i][j]=='.') bod=true;
        For(i,4) riadok(i);
        For(i,4) stlpec(i);
        diag1(); diag2();
        printf("Case #%d: ",i1+1);
        if(x) printf("X won\n");
        else if(o) printf("O won\n");
        else if(!bod) printf("Draw\n");
        else printf("Game has not completed\n");
    }
return 0;
}
