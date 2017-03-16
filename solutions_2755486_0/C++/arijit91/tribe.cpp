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

const int MAX_NUM_DAYS = 686060;

struct attack {
    int w, e, s;

    attack(int _w, int _e, int _s) {
        w = _w, e = _e, s = _s;
    }
};

vector<vector<attack> > attack_list;
map<int, int> M;

int main()
{
    int t = GI;
    FOR (cas, 1, t) {
        attack_list.clear();
        attack_list.resize(MAX_NUM_DAYS);
        M.clear();

        int N = GI;
        vector<attack> attacks;
        REP (i, N) {
            int d, n, w, e, s, delta_d, delta_p, delta_s;
            cin>>d>>n>>w>>e>>s>>delta_d>>delta_p>>delta_s;

            REP(j, n) {
                attack_list[d].push_back(attack(2*w, 2*e, s));

                d += delta_d;
                w += delta_p;
                e += delta_p;
                s += delta_s;
            }
        }

        int succ = 0;

        REP(i, MAX_NUM_DAYS) {
            REP (j, attack_list[i].size()) {
                attack a = attack_list[i][j];

                bool is_suc = false;
                FOR (k, a.w, a.e) {
                    if (M.find(k) == M.end() || M[k] < a.s) {
                        is_suc = true;
                        break;
                    }
                }

                if (is_suc) {
                    succ++;
                }

            }

            REP (j, attack_list[i].size()) {
                attack a = attack_list[i][j];

                FOR (k, a.w, a.e)
                    M[k] = max(M[k], a.s);
            }
        }

        cout<<"Case #"<<cas<<": "<<succ<<endl;
    }
	return 0;
}
