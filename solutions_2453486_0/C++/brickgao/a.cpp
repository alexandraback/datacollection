//By Brickgao
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

int t, caseno = 1;
string map[4];
bool end, xwin, owin;

int main() {
    cin >> t;
    while(t --) {
        xwin = owin = false;
        end = true;
        for(int i = 0; i < 4; i ++) {
            cin >> map[i];
        }
        for(int i = 0; i < 4; i ++) {
            for(int j = 0; j < 4; j ++) {
                if(map[i][j] == '.') {
                    end = false;
                    break;
                }
            }
            if(!end) {
                break;
            }
        }
        for(int i = 0; i < 4; i ++) {
            int xnum = 0, onum = 0, tnum = 0;
            for(int j = 0; j < 4; j ++) {
                if(map[i][j] == 'X')    xnum ++;
                if(map[i][j] == 'O')    onum ++;
                if(map[i][j] == 'T')    tnum ++;
            }
            if(xnum == 4 || (xnum == 3 && tnum == 1))
                xwin = true;
            if(onum == 4 || (onum == 3 && tnum == 1))
                owin = true;
        }
        for(int i = 0; i < 4; i ++) {
            int xnum = 0, onum = 0, tnum = 0;
            for(int j = 0; j < 4; j ++) {
                if(map[j][i] == 'X')    xnum ++;
                if(map[j][i] == 'O')    onum ++;
                if(map[j][i] == 'T')    tnum ++;
            }
            if(xnum == 4 || (xnum == 3 && tnum == 1))
                xwin = true;
            if(onum == 4 || (onum == 3 && tnum == 1))
                owin = true;
        }
        int xnum = 0, onum = 0, tnum = 0;
        for(int i = 0; i < 4; i ++) {
            if(map[i][i] == 'X')    xnum ++;
            if(map[i][i] == 'O')    onum ++;
            if(map[i][i] == 'T')    tnum ++;
        }
        if(xnum == 4 || (xnum == 3 && tnum == 1))
            xwin = true;
        if(onum == 4 || (onum == 3 && tnum == 1))
            owin = true;
        xnum = 0, onum = 0, tnum = 0;
        for(int i = 0; i < 4; i ++) {
            if(map[i][3 - i] == 'X')    xnum ++;
            if(map[i][3 - i] == 'O')    onum ++;
            if(map[i][3 - i] == 'T')    tnum ++;
        }
        if(xnum == 4 || (xnum == 3 && tnum == 1))
            xwin = true;
        if(onum == 4 || (onum == 3 && tnum == 1))
            owin = true;
        if(xwin) {
            printf("Case #%d: X won\n", caseno ++);
            continue;
        }
        if(owin) {
            printf("Case #%d: O won\n", caseno ++);
            continue;
        }
        if(end) {
            printf("Case #%d: Draw\n", caseno ++);
            continue;
        }
        printf("Case #%d: Game has not completed\n", caseno ++);
    }
    return 0;
}

