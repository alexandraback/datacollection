/*
*	ID : pallab81
* 	PROG : B
* 	LANG : C++
* 	2013-04-13-11.17.04 Saturday
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
int const mxn=105;
int mat[mxn][mxn];
int R,C;

inline void read() {
    R=fastIn<int>(),C=fastIn<int>();
    fo(i,R)fo(j,C)mat[i][j]=fastIn<int>();
}

inline bool check(int const val, int const curR, int const curC) {
    //1:
    //current column will have all values less or equal to {{val}}
    bool flag1=true,flag2=true;
    for(int row=0; row<R && flag1 ; ++row) {
        if( mat[row][curC]<=val )continue;
        flag1&=false;
    }
    if(flag1)return true;
    //2:
    //current row will have all values less or equal to {{val}}
    for(int col=0; col<C&&flag2; ++col) {
        if( mat[curR][col]<=val )continue;
        flag2&=false;
    }
    if(flag2)return true;
    return false;
}
inline void proc() {
    bool flag=true;
    for(int i=0; i<R && flag ; ++i) {
        for(int j=0; j<C && flag ; ++j) {
            flag&= check( mat[i][j],i,j);
        }
    }
    puts(flag?"YES":"NO");
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("B-large.in", "r", stdin))
        puts("error opening file in "), assert(0);

    freopen("B-large.out", "w", stdout);
    kase = 1;
#endif
    kase=fastIn<int>();
    fo(i,kase) {
        read();
        cout<<"Case #"<<i+1<<": ";
        proc();
    }
    return 0;
}
