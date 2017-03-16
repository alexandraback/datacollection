#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

void solve() {
cout << setprecision(9) << fixed;
long double C,F,X;   
cin >> C >> F >> X;

bool done = false;
long double best = 100000000.0;
long double curr = 0.0;
long double rate = 2.0;
while(!done) {
   // check if better than best
   if(X / rate + curr < best)
      best = X/rate + curr;
   else
      done = true;

   // buy farm
   curr += C/rate;
   rate += F;
}
cout << best;
}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
