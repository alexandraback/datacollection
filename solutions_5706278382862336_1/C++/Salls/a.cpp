#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

typedef unsigned long long ULL;

ULL GCD(ULL a, ULL b)
{
  ULL c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

void solve() {
char ch;
   ULL P,Q;
   cin >> P >> ch >> Q;
   ULL gcd = GCD(P,Q);
   P/=gcd;
   Q/=gcd;

   //cout << endl << P << " " << Q <<" "<< gcd << endl;

   bool good = false;
   for(ULL i = 1; i<=ULL(1)<<60; i*=2) {
      if(i == Q) 
         good = true;
   }
   if(!good){
         cout << "impossible";
         return;
   }

   int c = 1;
   for(ULL i = 2; i<=ULL(1)<<60; i*=2) {
      ULL factor = Q/i;
      if(factor <= P) {
         cout << c;
         return;
      }
      c++;
   }

   cout <<"ERROR";
   exit(0);

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
