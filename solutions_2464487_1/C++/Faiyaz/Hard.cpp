/* Bismillahir Rahmanir Rahim */
/*Coder: Ahmad Faiyaz*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL unsigned long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

# define VI vector<int>
# define VS vector<string>
# define VC vector<char>

#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

template <class stl>
void DBGSTL (stl a) { // for deque, vector , set
    FORIT(i,a){
        cerr<<*i<<" ";
    }
    cerr<<"\n";
    return;
}
LL R,T;

LL eqn (LL n){
    return (2*R*n + ((2+(n-1)*4)*n)/2);
}

LL bsearch(LL lo,LL hi){
    LL mid;
    LL rs=0;
    while(lo <= hi){
        mid= (lo+hi)>>1;
        LL ret= eqn(mid);
        if(ret > T){
            hi= mid-1;
        }
        else{
            lo=mid+1;
            rs= max(mid,rs);
        }
    }
    return rs;
}

int main(){
    #if defined( faiyaz_pc )
        READ("A-large.in");
        WRITE("big.txt");
    #endif
    int t,chk=1;
    cin>>t;
    while(t--){
        cin>>R>>T;
        printf("Case #%d: ",chk++);
        cout<<bsearch(1,min(T, 707106782ULL))<<endl;
    }

    return 0;
}
