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
int calc1(vector<double>& naomi, vector<double>& ken) {
  int n = naomi.size();
  int used[n];
  REP (i, n) used[i] = 0;
  int ans = 0;

  REP (i, n) {
    bool f = false;
    REP (j, n) {
      if (used[j] == 0 && ken[j] > naomi[i]) {
        used[j] = 1;
        f = true;
        break;
      }
    }
    if (f == false) {
      ans++;
      REP (j, n) {
        if (used[j] == 0) {
          used[j] = 1;
          break;
        }
      }
    }
  }
  return ans;
}

int calc2(vector<double>& naomi, vector<double>& ken) {
  int n = naomi.size();
  for (int i = n; i >= 1; i--) {
    bool f = true;
    for (int j = 0; j < i; j++) {
      if (naomi[n-i+j] < ken[j]) {
        f = false;
        break;
      }
    }
    if (f) return i;
  }
  return 0;
}

int main()
{
  int t = GI;
  int num = 0;
  for (int cas = 1; cas <= t; cas++) {
    printf("Case #%d: ", cas);
    int n = GI;
    vector<double> naomi, ken;
    REP (i, n) { double x = GF; naomi.push_back(x); }
    REP (i, n) { double x = GF; ken.push_back(x); }
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());

    int ans1 = calc1(naomi, ken);
    int ans2 = calc2(naomi, ken);
    assert(ans2 >= ans1);
    printf("%d %d\n", ans2, ans1);
  }
	return 0;
}
