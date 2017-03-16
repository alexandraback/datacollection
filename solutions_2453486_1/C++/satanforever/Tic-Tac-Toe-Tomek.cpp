#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <complex>
using namespace std;

#define read(c) scanf("%d",&(c))
#define FOR(i,n) for (int i=0;i<(n);i++)
#define FR(i,a,b) for (int i=(a);i<(b);i++)
#define fillzero(d) memset(d,0,sizeof(d))
#define fillmax(d) memset(d,63,sizeof(d))
#define dumps(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<endl
#define dump(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<"	"
#define shit cerr<<"Line:"<<(__LINE__)<<endl;
#define fileread freopen("/Users/satanforever/Downloads/A-large.in","r",stdin)
#define filewrite freopen("/Users/satanforever/Documents/A-large.out","w",stdout)
#define closeread fclose(stdin)
#define closewrite fclose(stdout)
#define MAXINT 0x7fffffff

int board[5][5];
bool emptyFlag;
string solve(){
    bool Oflag = false, Xflag = false;
    int row, col;
    for(int i = 0; i < 4; i++) {
        row = 0;
        col = 0;
        for(int j = 0; j < 4; j++) {
            row += board[i][j];
            col += board[j][i];
        }
        Oflag = Oflag || row == -3 || row == -4 || col == -3 || col == -4;
        Xflag = Xflag || row == 3 || row == 4 || col == 3 || col == 4;
    }
    row = 0;
    col = 0;
    for(int i = 0; i < 4; i++) {
        row += board[i][i];
        col += board[i][3 - i];
    }
    Oflag = Oflag || row == -3 || row == -4 || col == -3 || col == -4;
    Xflag = Xflag || row == 3 || row == 4 || col == 3 || col == 4;
    if (Oflag && Xflag)
        return "Draw";
    if (Oflag)
        return "O won";
    if (Xflag)
        return "X won";
    if (emptyFlag)
        return "Game has not completed";
    return "Draw";
}
void input(){
    char line[5];
    emptyFlag = false;
    for(int i = 0; i < 4; i++) {
        scanf("%s", line);
        for(int j = 0; j < 4; j++)
            switch (line[j]) {
                case 'X':
                    board[i][j] = 1; break;
                case 'O':
                    board[i][j] = -1; break;
                case 'T':
                    board[i][j] = 0; break;
                case '.':
                    board[i][j] = 1000; emptyFlag = true; break;
            }

    }
}
void output(string ret, int t){
    cout << "Case #" << t << ": " << ret <<endl;
}
int main() {
//fileread;
//filewrite;
int T;
cin >> T;
for(int i = 1; i <= T; i++) {
  	input();
  	output(solve(), i);
}
//closeread;
//closewrite;
  	return 0;
}
