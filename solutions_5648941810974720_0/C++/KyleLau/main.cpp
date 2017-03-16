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

char ss[MN];
int cc[26];
int res[10];
int N,A,B,C,D,M,Q,X,Y,T,R,K,L,U,S;
string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cal(int i) {
    if(i == 0 || i == 8) {
        return cal(i + 1);
    } else {
        bool exist = true;
         FOR(i, num[i].length()) {
            //cc[num[0][i]] -= n;
        }
    }
}
void pre(int id, char ch) {
    int n = cc[ch - 'A'];
    FOR(i, num[id].length()) {
        cc[num[id][i] - 'A'] -= n;
    }
    res[id] += n;
}
int main(){        
    int i,j,k,tt,a,b,c,s,t,n,d,x,y,r,u,v,p;
    scanf("%d\n",&T);
    for (tt = 1; tt <= T; tt++) {
        memset(cc, 0, sizeof(cc));
        memset(res, 0, sizeof(res));
        //scanf("%d",&N);
        //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
        //"", "ONE", "", "", "", "", "", "", "", "NINE"
        gets(ss);
        FOR(i, strlen(ss)) {
            cc[ss[i] - 'A']++;
        }
        pre(0, 'Z');
        pre(8, 'G');
        pre(6, 'X');
        pre(7, 'S');
        pre(3, 'H');
        pre(4, 'R');
        pre(2, 'W');
        pre(5, 'F');
        
        pre(9, 'I');
        pre(1, 'N');
        

        
        printf("Case #%d: ",tt);
        FOR(i, 10) {
            FOR(j, res[i]) {
                cout << char('0' + i);
            }
        }
        puts("");
        //printf("Case #%d: %d\n",tt,N);
    }
    
    return 0;
}

