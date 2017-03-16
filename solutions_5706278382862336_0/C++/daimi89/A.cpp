#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

long long gcd(long long n, long long m) {
  return m==0 ? n : gcd(m,n%m);
};

main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    string S;
    cin >> S;
    size_t pos = S.find("/");
    string s1=S.substr(0,pos), s2=S.substr(pos+1);
    long long p = atoll(s1.c_str()), q=atoll(s2.c_str());
    long long g = gcd(p,q);
    p=p/g, q=q/g;

    long long lq = 0, lp=0;
    while ((q&1)==0) lq++, q>>=1;
    while (p>0) lp++, p>>=1;
    if (q!=1) // q not power of two
      cout << "Case #" << t << ": impossible" << endl;
    else
      cout << "Case #" << t << ": " << (lq-lp+1) << endl;
      
  };
};
