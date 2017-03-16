/*
 * Author: fatboy_cw
 * Created Time:  2013/4/13 11:55:47
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 5;

int t;
char mat[maxn][maxn];

bool getRes(char ch) {
    for(int i = 0; i < 4; i++) {
        int c1 = 0, c2 = 0;
        for(int j = 0; j < 4; j++) {
            if(mat[i][j] == ch || mat[i][j] == 'T') c1++;
            if(mat[j][i] == ch || mat[j][i] == 'T') c2++;
        }
        if(c1 == 4 || c2 == 4) return true;
    }
    int c1 = 0, c2 = 0;
    for(int i = 0; i < 4; i++) {
        if(mat[i][i] == ch || mat[i][i] == 'T') c1++;
        if(mat[i][3 - i] == ch || mat[i][3 - i] == 'T') c2++;
    }
    if(c1 == 4 || c2 == 4) return true;
    return false;
}

bool draw() {
    int c = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(mat[i][j] == '.') c++;
        }
    }
    return c == 0;
}

int ca;

void output(char ch) {
    printf("Case #%d: ", ++ca);
    if(ch == 'X') printf("X won\n");
    else if(ch == 'O') printf("O won\n");
    else if(ch == 'D') printf("Draw\n");
    else printf("Game has not completed\n");
}

int main() {
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 4; i++) {
            scanf("%s", mat[i]);
        }
        if(getRes('X')) output('X');
        else if(getRes('O')) output('O'); 
        else if(draw()) output('D');
        else output('G');
    }
    return 0;
}

