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


void init(){
    cout << setprecision(8)<< fixed;
}

class quat {
   public:
      enum ijk{
         one = 0,
         i,
         j,
         k,
         ijkmax
      } value;
      bool minus;
      quat(ijk v = one, bool m = false) : value(v), minus(m) {}
      quat(char c):value(one), minus(false) {
         switch (c) {
         case 'i': value = i; break;
         case 'j': value = j; break;
         case 'k': value = k; break;
         }
      }
      quat(const quat &other) {
         value = other.value;
         minus = other.minus;
      }
      quat &operator=(const quat &other) {
         value = other.value;
         minus = other.minus;
         return *this;
      }
      
      bool operator==(const quat &other) {
         return value == other.value && minus == other.minus;
      }
      bool operator!=(const quat &other) {
         return not (*this == other);
      }
      
      friend ostream & operator<<(ostream &stream, const quat &q) {
         stream << (q.minus?'-':'+');
         switch (q.value) {
            case one: stream << "1"; break;
            case i: stream << "i"; break;
            case j: stream << "j"; break;
            case k: stream << "k"; break;
         }
         return stream;
      }
      
      quat &times(const quat &other) {
         bool sign = false;
         switch(value) {
            case one:
               value = other.value;
               break;
            case i:
               switch(other.value) {
                  case one:
                     break;
                  case i:
                     value = one;
                     sign = true;
                     break;
                  case j:
                     value = k;
                     break;
                  case k:
                     value = j;
                     sign = true;
                     break;
               }
            break;
            case j:
               switch(other.value) {
                  case one:
                     break;
                  case i:
                     value = k;
                     sign = true;
                     break;
                  case j:
                     value = one;
                     sign = true;
                     break;
                  case k:
                     value = i;
                     sign = false;
                     break;
               }
            break;
            case k:
               switch(other.value) {
                  case one:
                     break;
                  case i:
                     value = j;
                     sign = false;
                     break;
                  case j:
                     value = i;
                     sign = true;
                     break;
                  case k:
                     value = one;
                     sign = true;
                     break;
               }
            break;
         }
         minus = (minus xor other.minus xor sign);
         return *this;
      }
      
      quat &rev_times(const quat &other) {
         quat result(other);
         result.times(*this);
         *this = result;
         return *this;
      }
};

string solve(int testnr){
   ll L, X; 
   cin >> L >> X;
   vector<quat> word;
   const quat ONE;
   const quat MINUS_ONE(quat::one, true);
   const quat I('i');
   const quat J('j');
   const quat K('k');
   quat product(ONE);
   for(int ind=0; ind < L ; ind++) {
      char c = ' ';
      cin >> c;
      word.push_back(c);
      product.times(word[ind]);
   }
   //cerr << product << endl;
   
   if (product == ONE) return "NO";
   if (product == MINUS_ONE && X%2 == 0) return "NO";
   if (product != MINUS_ONE && X%4 != 2) return "NO";
   int first = -1;
   quat p;
   for(int iter = 0; iter < 4 && first == -1; iter++) {
      for(int ind = 0; ind < L && first == -1; ind++) {
         p.times(word[ind]);
//         cerr << p << ",";
         if (p == I) {
            first = iter * L + ind + 1;
         }
      }
   }
//   cerr << endl;
   if (first == -1) return "NO";
   quat q;
   int last = -1;
   for(int iter = 0; iter < 4 && last == -1; iter++) {
      for(int ind = L - 1; ind >= 0 && last == -1; ind--) {
         q.rev_times(word[ind]);
//         cerr << q << ",";
         if (q == K) {
            last = iter * L + L - ind;
         }
      }
   }
//   cerr << endl;
   if (last == -1) return "NO";
   if (first + last >= X * L) return "NO";
   return "YES";
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
