#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
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
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define MAXN 1000005
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

//Main code starts here
int main()
{
    int t = GI;
    for (int ii = 1; ii <= t; ii++) {
        long long E, R, N;
        cin>>E>>R>>N;

        vector<long long> V(N);
        map<long long, long long> extras;
        vector<int> good(N, 0);

        REP (i, N) cin>>V[i];

        long long gain = 0;
        long long cur = E;
        if (E >= R) {

            int maxx = -1;

            for (int i = N - 1; i >= 0; i--) {

                if (V[i] >= maxx) {
                    good[i] = 1;
                    maxx = V[i];
                }
            }

            //sort(V.rbegin(), V.rend());

            REP (i, N) {
                if (good[i]) {
                    gain += cur * V[i];
                    cur = R;
                    extras.clear();
                }
                else {
                    long long extra = cur + R - E;

                    extras[-V[i]] += R;

                    if (extra > 0) {
                        //gain += extra * V[i];
                        cur = E;

                        long long sum = 0;
                        TR(extras, it) {
                            long long take = min(extra - sum, it -> second);
                            extras[it->first] -= take;
                            gain += take * (-1 * it->first);
                            extra -= take;
                            if (extra == 0) 
                                break;
                        }
                        assert(extra == 0);
                    }
                    else {
                        cur = cur + R;
                    }
                }
            }
        }
        else {
            REP (i, N) {
                gain += E * V[i];
            }
        }

        cout<<"Case #"<<ii<<": "<<gain<<endl;

    }
	return 0;
}
