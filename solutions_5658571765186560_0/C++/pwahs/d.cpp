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
#include <ctime>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init() {
    cout << setprecision(8)<< fixed;
}

bool solve(int testnr) {
   int X, R, C;
   cin >> X >> R >> C;
   int total = R*C;
   if (total % X != 0) return true;
   switch(X) {
      case 1: return false;
      case 2: return false;
      case 3: if (R==1 || C==1) return true;
              return false;
      case 4: if (R<=2 || C<=2) return true;
              return false;
      case 5: if (R<=2 || C<=2) return true;
              if (total == 15) return true; //W-Pentomino in 3x5
              return false;
      case 6: if (R<=3 || C<=3) return true;
              return false;
      default: return true;
   }
   return 0;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << (solve(i)?"RICHARD":"GABRIEL") << "\n";
    }
    
    return 0;
}
