/*
*	ID : pallab81
* 	PROG : D
* 	LANG : C++
* 	2013-04-13-13.59.10 Saturday
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
int const max_room = 22;
int const max_key = 22;
int to_open_room[max_room];
vector<int> key_have[max_room];

int initialKey,roomCount;
int keys[max_key];

inline void read() {
    SET(keys,0);
    fo(i,max_room)key_have[i].clear();

    initialKey=fastIn<int>(),roomCount=fastIn<int>();

    fo(i,initialKey){
        int tmp=fastIn<int>();
        ++keys[tmp];
    }

    fo(i,roomCount){
        to_open_room[ i ]=fastIn<int>();
        int _key_have=fastIn<int>();
        fo(j,_key_have){
            int tmp=fastIn<int>();
            key_have[i].pb(tmp);
        }
    }
}
inline int bc(Int msk) {
        int c=0;
        for(c=0; msk ; ++c){
                msk&= (msk-1);
        }
        return c;
}
int retval[max_room];
int ct;
int dp[1<<22];
bool go(int msk){
    if( bc(msk)>= roomCount ){
        return true;
    }
    if( dp[msk]!=-1 )return dp[msk];

    fo(i,roomCount){
        if( !(msk&(1<<i)) ){
            //Do I have key for this room ?
            int need = to_open_room[i];
            if( keys[need]>0 ){
                --keys[need];
                for(auto x: key_have[i])
                    ++keys[x];
                if(go(msk|(1<<i)) ){ retval[ct++]=i+1; return dp[msk]=true; }
                ++keys[need];
                for(auto x: key_have[i])
                    --keys[x];
            }
        }
    }
    return dp[msk]=false;
}
inline void proc() {
    SET(dp,-1);
    ct=0;
    if( !go(0) )puts(" IMPOSSIBLE");
    else{
        for(int i=ct-1;i>=0;--i)
            cout<<' '<<retval[i];
        puts("");
    }
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    if (!freopen("D-small-attempt1.in", "r", stdin))
        puts("error opening file in "), assert(0);

    freopen("D-small-attempt1.out", "w", stdout);
    kase = 1;
#endif
    kase=fastIn<int>();
    fo(i,kase) {
        read();
        cout<<"Case #"<<i+1<<":";
        proc();
    }
    return 0;
}
