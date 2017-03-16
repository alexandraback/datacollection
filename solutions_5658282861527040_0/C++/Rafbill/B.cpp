#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = j; i <= (k); ++i)
#define FORD(i, j, k) for(long i = j; i >= (k); --i)

// enum class SolutionE {

// };

// struct Solution {
//   static Solution AAA(){
//     return Solution {SolutionE};
//   }
//   SolutionE p;
// };

// ostream& operator<<(ostream& str, Solution const& s){
//   switch(s.p){

//   }
//   return str;
// }

long log2(long a){
  if(a == 0) return 0;
  if(a == 1) return 0;
  else return 1 + log2(a / 2);
}

// prefixes of a and b and k ! -> MEMOIZE
map<tuple<long, long, long>, long> A;

long rec(long a, long b, long k){
  if(b < a) A[make_tuple(a, b, k)] = rec(b, a, k);
  else{
    long pk = log2(k);
    long pa = log2(a);
    long pb = log2(b);
    if(k >= a){
      A[make_tuple(a, b, k)] = (a+1)*(b+1);
      // cout << 0 << "-";
    }else if(pb > pa){
      A[make_tuple(a, b, k)] = rec(a, b & ((1<<(pa+1))-1), k) + ((b>>(pa+1)))*rec(a, (1<<(pa+1))-1, k);
      // cout << 1 << "-" << A[make_tuple(a, b & ((1<<pa)-1), k)] << " " << (((b>>pa)-1)*A[make_tuple(a, (1<<(pa+1))-1, k)]) << "-";
      // cout << a << " " << (b & ((1<<(pa+1))-1)) << "-" << a << " " << ((1<<(pa+1))-1) << "-";
    }else if(pa > pk){
      A[make_tuple(a, b, k)] = rec(a-(1<<pa), (1<<pa)-1, k) + rec((1<<pa)-1, b-(1<<pa), k) + rec((1<<pa)-1, (1<<pa)-1, k);
      // cout << 2 << "-";
    }else if(k == 0){
      A[make_tuple(a, b, k)] = rec(a-(1<<pa), (1<<pa)-1, (1<<pk)-1) + rec((1<<pa)-1, b-(1<<pa), (1<<pk)-1) + rec((1<<pa)-1, (1<<pa)-1, (1<<pk)-1);
    }else{
      A[make_tuple(a, b, k)] = rec(a-(1<<pa), b-(1<<pb), k-(1<<pk)) + rec(a-(1<<pa), (1<<pa)-1, (1<<pk)-1) + rec((1<<pa)-1, b-(1<<pa), (1<<pk)-1) + rec((1<<pa)-1, (1<<pa)-1, (1<<pk)-1);
      // cout << 3 << "-";
    }
    // cout << bitset<32>(a) << " " << bitset<32>(b) << " " << bitset<32>(k) << " " << A[make_tuple(a, b, k)] << endl;
  }
  return A[make_tuple(a, b, k)];
}


long solve(){
  long a, b, k; cin >> a >> b >> k;
  A.clear();
  // cout << a << " " << b << " " << k;
  return rec(min(a, b)-1, max(a, b)-1, k-1);
}

int main(int, char**){
  long n_test; cin >> n_test;
  FOR(t, n_test){
    cout << "Case #" << t+1 << ": " << solve() << "\n";
  }
  return 0;
}