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
#define MAX 60

string board[4];
bool ended() {
    int i , j;
    for (i =0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (board[i][j] == '.')
                return false;
    return true;
}
bool ok(int i, int j, char c) {
    return board[i][j] == c || board[i][j] == 'T';
}
bool wonHorizontal(int i, char c) {
    return ok(i,0,c) && ok(i,1,c) && ok(i,2,c) && ok(i,3,c);
}
bool wonVertical(int i, char c) {
    return ok(0,i,c) && ok(1, i,c) && ok(2, i,c) && ok(3, i,c);
}
bool win(char c) {
    int i;
    for (i = 0; i < 4; i++) {
        if (wonHorizontal(i, c) || wonVertical(i,c))
            return true;
    }
    if (ok(0,0,c) && ok(1,1,c) && ok(2,2,c) && ok(3,3,c))
        return true;
    return ok(0,3,c) && ok(1,2,c) && ok(2,1,c) && ok(3,0,c);
}
void go() {
    if (win('X'))
        puts("X won");
    else if (win('O'))
        puts("O won");
    else if (ended())
        puts("Draw");
    else
        puts("Game has not completed");
}
int main() {
    int nt, t, i;
    cin >> nt;
    for (t = 1; t <= nt; t++) {
        printf("Case #%d: ", t);
        for (i = 0 ; i < 4; i++)
            cin >> board[i];
        go();
    }
    return 0;
}
