// {{{
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)		(A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
#define PB  push_back
using namespace std;
typedef long long ll;

int vx[]={1,0,-1,0},vy[]={0,1,0,-1};
// }}}

int main(){
    int T;
    scanf("%d\n",&T);
    char ar[4][4],vecs[10][4];
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%c",&ar[i][j]);
            }
            scanf("\n");
        }
        scanf("\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                vecs[i][j]=ar[i][j];
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                vecs[i+4][j]=ar[j][i];
            }
        }
        for(int i=0;i<4;i++){
            vecs[8][i]=ar[i][i];
        }
        for(int i=0;i<4;i++){
            vecs[9][i]=ar[i][3-i];
        }
        bool isx=false,iso=false;
        for(int i=0;i<10;i++){
            bool isnow=true;
            for(int j=0;j<4;j++){
                if(vecs[i][j]!='X' && vecs[i][j]!='T') isnow=false;
            }
            if(isnow) isx=true;
            isnow=true;
            for(int j=0;j<4;j++){
                if(vecs[i][j]!='O' && vecs[i][j]!='T') isnow=false;
            }
            if(isnow) iso=true;
        }
        if(isx) printf("X won\n");
        else if(iso) printf("O won\n");
        else{
            bool isnow=true;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(ar[i][j]=='.') isnow=false;
                }
            }
            if(isnow) printf("Draw\n");
            else printf("Game has not completed\n");
        }
    }
}
