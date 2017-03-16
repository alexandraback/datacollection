#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cstdio>

using namespace std;

ifstream in("Cin.txt");
ofstream out("Cout.txt");

const int MAXRC=51;
char grid[MAXRC][MAXRC];
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

bool setgrid(int R, int C, int numE) {
    bool possible=false;
    for( int csz = 2; csz <= C && !possible && numE>=4; csz++ ) {
        if( numE/csz <= 1 ) break; //not enough
        if( (numE/csz <= R && numE%csz==0) ||
           (numE/csz <= R-1 && numE%csz >= 2) ) {
            for( int i=0; i<numE/csz; i++ ) {
                for( int j=0; j<csz; j++ ) {
                    grid[i][j] = '.';
                }
            }
            for( int j=0; j<numE%csz; j++ ) grid[numE/csz][j]='.';
            possible= true;
            grid[0][0] = 'c'; //set click point
        }
    }
    return possible;
}


int main() {
    int T;
    in >> T;
    for( int TC=1; TC <=T; TC++ ) {
        int R, C, M, numE;
        bool swapped = false, possible=false;
        in >> R >> C >> M;

        //if( C > R ) swap(R,C), swapped = true;
        numE = R*C-M;
        for( int i=0; i<MAXRC; i++ ) for( int j=0; j<MAXRC; j++ ) grid[i][j]='*';

        //where only 1 empty square
        if( numE == 1 ) {
                grid[0][0] = 'c';
                possible=true;
        }
        //special case where C = 1
        else if( R==1 || C == 1 ) {
            if( R < C ) {swap(R,C); swapped=true;}
            grid[0][0] = 'c';
            for( int i=1; i<numE; i++ ) grid[i][0] = '.';
            possible = true;
        }
        else if( R == C && R>=4 && M == R-1 ) {
            cout << TC << endl;
            for( int i=0; i<R; i++ ) {
                for( int j=0; j<C; j++ ) grid[i][j] = '.';
            }
            for( int i=2; i<R; i++ ) grid[i][C-1]='*';
            grid[R-1][C-2] = '*';
            grid[0][0] = 'c';
            possible = true;
        }
        else {
        //make sure numE >= 4
        //general case where C >= 2
            if( setgrid(R,C,numE) ) possible=true;
            else if( setgrid(C,R,numE) ) { possible=true; swapped=true; swap(R,C); }
            else possible=false;
        }

        //output
        out << "Case #" << TC << ": " << endl;
        if(!possible) out << "Impossible" << endl;
        else {
            if( swapped ) {
                char ans[MAXRC][MAXRC];
                swap(R,C);
                for( int i=0; i<R; i++ ) {
                    for( int j=0; j<C; j++ ) ans[i][j] = grid[j][i];
                    ans[i][C] = '\0';
                    out << ans[i] << endl;
                }
            }
            else {
                for( int i=0; i<R; i++ ) {
                    grid[i][C] = '\0';
                    out << grid[i] << endl;
                }
            }
        }


    }
    return 0;
}
