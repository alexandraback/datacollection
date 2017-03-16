#include <iostream>
using namespace std;
int f(int a, int b, int k) {
   int ans = 0;
   for (int i = 0; i<a; i++)
      for (int j = 0 ; j < b; j++) 
         if ((i&j)<k) 
            ans ++;
   return ans;
}
int main() {
  int t;
   cin >> t ;
  for (int ii = 1; ii<=t; ii++) {
     cout <<"Case #"<<ii<<": ";
     int a,b,k;
     cin >> a>> b>> k;
     cout << f(a,b,k) << endl;

  }
  return 0;
}
