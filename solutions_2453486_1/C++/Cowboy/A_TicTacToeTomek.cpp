/*
 *ID:   Cowboy
 *TASK: A Codejam
 *Judge:Code Jam
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#define INF 2000000000
#define PI 2*acos(0.0)
using namespace std;

#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))

bool isX( char c ){
    return c=='X' || c=='T';
}

bool isO( char c ){
    return c=='O' || c=='T';
}

int main( ){
    freopen("A-large.in","r",stdin);
    freopen("solution.out","w",stdout);
    int T;
    bool draw, gX, gO;
    cin>>T;
    string tab[4], res;
    for(int k=0; k<T; k++){
        draw = true;
        gX = gO = false;
        for(int i=0; i<4; i++){
            cin>>tab[i];
            for(int j=0; j<4; j++){
                if(tab[i][j]=='.')
                    draw = false;
            }
        }
        if( draw )
            res = "Draw";
        else
            res = "Game has not completed";

        if( isX( tab[0][0] ) && isX( tab[1][1] )
            && isX( tab[2][2] ) && isX( tab[3][3] ) )
                gX=true;
        if( isX( tab[0][3] ) && isX( tab[1][2] )
            && isX( tab[2][1] ) && isX( tab[3][0] ) )
                gX=true;

        if( isO( tab[0][3] ) && isO( tab[1][2] )
            && isO( tab[2][1] ) && isO( tab[3][0] ) )
                gO=true;
        if( isO( tab[0][0] ) && isO( tab[1][1] )
            && isO( tab[2][2] ) && isO( tab[3][3] ) )
                gO=true;


        //Mirar si gano el X
        for( int i=0; i<4 ; i++ ){
            if( isX(tab[i][0]) && isX(tab[i][1])
               && isX(tab[i][2]) && isX(tab[i][3]) )
                gX = true;

            if( isX(tab[0][i]) && isX(tab[1][i])
               && isX(tab[2][i]) && isX(tab[3][i]) )
               gX = true;

            if( gX )
                break;

            if( isO(tab[i][0]) && isO(tab[i][1])
               && isO(tab[i][2]) && isO(tab[i][3]) )
                gO = true;

            if( isO(tab[0][i]) && isO(tab[1][i])
               && isO(tab[2][i]) && isO(tab[3][i]) )
               gO = true;

            if( gO )
                break;
        }

        if( gX )
            res = "X won";

        if( gO )
            res = "O won";

        printf("Case #%d: ", k+1);cout<<res<<endl;
    }

return 0;
}
