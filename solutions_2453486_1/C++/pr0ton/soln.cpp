#include<cassert>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


char a[8][8];
const int N = 4, M = 4;
bool eq(char x, char y) {
    if (x == 'T' || y == 'T') return true;
    return x == y;
}
char getWinner(string a) {
    for (int i=0; i < (int)a.size(); i++)
    if (a[i] == '.') return 0;
    char res = 0;
    for (int i=0; i < (int)a.size(); i++)
    if (a[i] != 'T') res = a[i];
    for (int i=0; i < (int)a.size(); i++)
    if (!eq(a[i], res)) return 0;
    
    return res;
}
char winner() {
    for (int i=0; i < N; i++) {
        string row = "";
        for (int j=0; j < M; j++) row += a[i][j];
        // cout<<"row " << i << " = " << row << endl;
        char f = getWinner(row);
        if (f) return f;
    }
    for (int j=0; j < M; j++) {
        string col = "";
        for (int i=0; i < N; i++) col += a[i][j];
        // cout<<"col " << j << " = " << col << endl;
        char f = getWinner(col);
        if (f) return f;
    }
    {
        string d1 = "";
        for (int i=0, j=0; i < N; i++, j++) {
            d1 += a[i][j];
        }
        // cout <<"d1 is "<< d1 << endl;
        char f = getWinner(d1);
        if (f) return f;
    }
    {
        string d2 = "";
        for (int i=0, j=M-1; i < N; i++, j--) {
            d2 += a[i][j];
        }
        // cout <<"d2 is "<< d2 << endl;
        char f = getWinner(d2);
        if (f) return f;
    }
    return 0;
}

int main() {
    int runs; s(runs);
    for (int t=1; t <= runs; t++) {
        bool movesLeft = false;
        for (int i=0; i < N; i++) {
            scanf("%s", a[i]);
            for (int j=0; j < M; j++) {
                movesLeft |= a[i][j] == '.';
            }
        }
        char res = winner();
        printf("Case #%d: ", t);
        if (res) {
            printf("%c won\n", res);
        } else {
            if(movesLeft) 
                puts("Game has not completed");
            else
                puts("Draw");
        }
        
    }
}
