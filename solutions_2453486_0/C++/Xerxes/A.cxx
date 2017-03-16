/*
*	ID : pallab81
* 	PROG : A
* 	LANG : C++
* 	2013-04-13-09.00.52 Saturday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

#define foR(i1,st,ed) for(int i1 = st , j1 = ed ; i1 < j1 ; ++i1 )
#define fo(i1,ed) foR( i1 , 0 , ed )
#define foE(i1,st,ed) foR( i1, st, ed+1 )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait(double seconds) {
    double endtime = clock() + (seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}
template<class T>
inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while(c<33)c=getchar();
    while(c>33) {
        if(c=='-') {
            neg=true;
        } else {
            a= (a*10)+(c-'0');
        }
        c=getchar();
    }
    return neg?-a:a;
}
string grid[4];
inline void read() {
    fo(i,4)
    cin>>grid[i];
}
inline bool WIN(string const str, char const me) {
    if( count(str.begin(),str.end(),me)==4 )return true;
    if( count(str.begin(),str.end(),me)==3 && str.find('T')!=string::npos )return true;
    return false;
}
inline bool isWin(char const me) {
    //1:
    string tmp="";
    for(int row=0; row<4; ++row) {
        tmp="";
        for(int col=0; col<4; ++col)tmp+=grid[row][col];
        if( WIN(tmp,me) )return true;
    }
    //2:
    tmp="";
    for(int i=0,j=0; i<4; ++i,++j) {
        tmp+=grid[i][j];
    }
    if( WIN(tmp,me) )return true;

    //3:
    tmp="";
    for(int i=0,j=3; i<4; ++i,--j) {
        tmp+=grid[i][j];
    }
    if( WIN(tmp,me) )return true;
    //4:
    for(int col=0; col<4; ++col) {
        tmp="";
        for(int row=0; row<4; ++row)tmp+=grid[row][col];
        if( WIN(tmp,me) )return true;
    }
    return false;
}
inline bool isDraw(){
    fo(i,4){
        if( grid[i].find('.')!= string::npos )return false;
    }
    return true;
}
inline void proc() {
    if( isWin('X') )puts("X won");
    else if( isWin('O') )puts("O won");
    else if( isDraw() )puts("Draw");
    else{
        puts("Game has not completed");
    }
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    kase = 1;
#endif
    kase=fastIn<int>();
    fo(i,kase) {
        cout<<"Case #"<<i+1<<": ";
        read();
        proc();
    }
    return 0;
}
