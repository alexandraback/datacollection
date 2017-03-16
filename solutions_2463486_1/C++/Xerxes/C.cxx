/*
*	ID : pallab81
* 	PROG : C
* 	LANG : C++
* 	2013-04-13-09.42.45 Saturday
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
inline bool isPal(Int number){
    Int real=number,rev=0;
    while(number>0){
        rev =(rev*10)+ (number%10);
        number/=10;
    }
    return real==rev;
}
Int nicePalindromes[60];
int sz;
inline bool pregen(){
    sz=0;
    Int cur=1, upper=100000000000000LL;
    for( ; cur*cur<=upper ;++cur){
        if( isPal(cur) ){
            if( isPal(cur*cur) ){
                nicePalindromes[sz++]=cur*cur;
            }
        }
    }
}

Int lo,hi;
inline void read(){
    lo=fastIn<Int>(),hi=fastIn<Int>();
}
inline void proc(){
    int cnt=0;
    for(int i=0;i<sz && nicePalindromes[i]<=hi ;++i){
        if( nicePalindromes[i]>=lo)++cnt;
    }
    cout<<cnt<<'\n';
}
int main() {
        pregen();
        int kase = 1;
#if defined( xerxes_pc )
        freopen("C-large-1.in", "r", stdin);
        freopen("C-large-1.out", "w", stdout);
        kase = 1;
#endif
        kase=fastIn<int>();
        fo(i,kase){
                read();
                cout<<"Case #"<<i+1<<": ";
                proc();
        }
        return 0;
}
