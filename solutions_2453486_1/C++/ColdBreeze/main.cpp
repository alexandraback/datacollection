#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("in_codejam");
    ofstream cout("out_codejam");
    char m[4][5];
    int T, w=0, d=0, t, cases=0;
    cin >> T;
    while (T--) {
        w = d = t = 0;
        cin >> m[0] >> m[1] >> m[2] >> m[3];
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                if (m[i][j]=='.') {d=1; m[i][j]=0;} if (m[i][j]=='O') {m[i][j]=1;} if (m[i][j]=='T') {m[i][j]=5;} if (m[i][j]=='X') {m[i][j]=10;}
                if (i>0) {m[i][j]+=m[i-1][j];} if (j>0) {m[i][j]+=m[i][j-1];} if (i>0 && j>0) {m[i][j]-=m[i-1][j-1];}
                if (j==3) {
                    t = m[i][3];
                    if (i>0) t -= m[i-1][3];
                    if (t==4 || t==8) {
                        w = 1;
                        break;
                    }
                    if (t==40 || t==35) {
                        w = 2;
                        break;
                    }
                }
                if (i==3) {
                    t = m[3][j];
                    if (j>0) t -= m[3][j-1];
                    if (t==4 || t==8) {
                        w = 1;
                        break;
                    }
                    if (t==40 || t==35) {
                        w = 2;
                        break;
                    }
                }
            }
            if (w!=0) break;
        }
        if (w==0) {
            t = (m[3][0]-m[2][0])+(m[2][1]-m[1][1]-m[2][0]+m[1][0])+(m[1][2]-m[0][2]-m[1][1]+m[0][1])+(m[0][3]-m[0][2]);
            if (t==4 || t==8) w = 1;
            if (t==40 || t==35) w = 2;
            t = (m[0][0])+(m[1][1]-m[0][1]-m[1][0]+m[0][0])+(m[2][2]-m[2][1]-m[1][2]+m[1][1])+(m[3][3]-m[3][2]-m[2][3]+m[2][2]);
            if (t==4 || t==8) w = 1;
            if (t==40 || t==35) w = 2;
        }
        if (w==0 && d) cout << "Case #" << (++cases) << ": " << "Game has not completed" << endl;
        else if (w==0) cout << "Case #" << (++cases) << ": " << "Draw" << endl;
        else if (w==1) cout << "Case #" << (++cases) << ": " << "O won" << endl;
        else cout << "Case #" << (++cases) << ": " << "X won" << endl;
    }
    return 0;
}
