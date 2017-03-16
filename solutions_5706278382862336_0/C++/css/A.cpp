#include <iostream>
#include <cstdio>
using namespace std;

long long m, p, q, mut[41], sum;

long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y%x, x);
}

int main()
{
 //freopen("in", "r", stdin);
 //freopen("out", "w", stdout);
 mut[0] = 1;
 for (int i = 1; i <= 40; i++) mut[i] = mut[i-1]<<1;
 int t, ans;
 char ch;
 cin >> t;
 for (int count = 1; count <= t; count++) {
   cin >> p >> ch >> q;
   cout << "Case #" << count << ": ";
   m = gcd(p, q);
   if (p==0 || mut[40]%(q/m)!=0) {
     cout << "impossible";
   } else {
     sum = mut[40]/(q/m)*(p/m);
     for (int i = 0; i <= 40; i++)
       if (sum >= mut[i]) ans = i;
     cout << 40-ans;
   }
   cout << endl;
 }
}
