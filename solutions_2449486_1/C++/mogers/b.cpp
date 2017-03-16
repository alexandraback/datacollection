#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
#define PB			push_back
#define ALL(v)			(v).begin() , (v).end()
#define SZ(v)			( (int) v.size() )
#define Set(v,x)		memset(  v , x , sizeof(v))
#define two(n)			( 1 << (n) )
#define contain(S,i)		( (S) & two(i) ) 
#define SQR(v)			( (v) * (v) )
#define ABS(x)			( ( (x) >= 0 ) ? (x) : -(x) )
#define foreach(v,it)		for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define MAX 110
int mat[MAX][MAX], L , C;
int alt[MAX][MAX];

bool solve() {
    int i , j;
    for (i = 0 ; i < L ; i++)
        for (j = 0 ; j < C ; j++)
            alt[i][j] = 100;
    for (i = 0 ; i < L  ; i++) {
        int m = mat[i][0];
        for (j = 1 ; j < C ; j++)
            m = max(m, mat[i][j]);
        for (j = 0; j < C ; j++)
            alt[i][j] = min(alt[i][j], m);
    }
    for (j = 0 ; j < C  ; j++) {
        int m = mat[0][j];
        for (i = 1 ; i < L ; i++)
            m = max(m, mat[i][j]);
        for (i = 0 ; i < L ; i++)
            alt[i][j] = min(alt[i][j], m);
    }
    for (i = 0 ; i < L  ;i++)
        for (j = 0 ; j < C ; j++)
            if (alt[i][j] != mat[i][j])
                return false;
    return true;
}
int main() {
    int nt, t, i, j;
    cin >> nt;
    for (t = 1; t <= nt; t++) {
        printf("Case #%d: ", t);
        cin >> L >> C;
        for (i = 0 ; i < L ; i++)
            for (j = 0 ; j < C ; j++)
                cin >> mat[i][j];
        if (solve())    puts("YES");
        else            puts("NO");
    }
    return 0;
}
