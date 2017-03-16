#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5;
char a[N][N];
int sum;

bool ok(int x1, int y1, int x2, int y2, int dx, int dy, char c){
    int i = x1, j = y1;
    while (1){
            if (a[i][j] != c && a[i][j] != 'T')
                return false;
            if (i == x2 && j == y2) return true;
            i += dx; j += dy;
    }
}

int get(){
    for (int i = 1; i <= 4; i++){
        if (ok(i, 1, i, 4, 0, 1, 'X')) return 1;
        if (ok(i, 1, i, 4, 0, 1, 'O')) return 0;
        if (ok(1, i, 4, i, 1, 0, 'X')) return 1;
        if (ok(1, i, 4, i, 1, 0, 'O')) return 0;
    }
    if (ok(1,1,4,4,1,1,'X')) return 1;
    if (ok(1,1,4,4,1,1,'O')) return 0;
    if (ok(1,4,4,1,1,-1,'X')) return 1;
    if (ok(1,4,4,1,1,-1,'O')) return 0;
    if (sum == 16) return 2;
    else return 3;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++){
        printf("Case #%d: ", t);
        sum = 0;
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++){
                scanf(" %c", &a[i][j]);
                if (a[i][j] != '.') sum++;
            }
        int k = get();
        if (k == 1) printf("X won\n");
        if (k == 0) printf("O won\n");
        if (k == 2) printf("Draw\n");
        if (k == 3) printf("Game has not completed\n");
    }
}
