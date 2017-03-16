#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

void solve(int t) {
  int A, B;
  //string str;
  cin >> A >> B;
  double p;//[] = new int[A];
  double r=1; // P(correct so far)
  double exp;//[] = new int[A];
  double ans = 1+B+1;
  //cout << ans << endl;
  for (int i=0;i<A;i++) {
	cin >> p;
	r*=p;
	//p[i]=p;
	exp = (1-r) * ( (A-(i+1))*2 + (B-A)  +1 +B +1) + (r) * ( (A-(i+1))*2 + (B-A) +1 );
	//cout << r << " " << exp << " for deleting " << (A-(i+1)) << " (" << ( (A-(i+1))*2 + (B-A)  +1 +B +1) << " " << ( (A-(i+1))*2 + (B-A) +1 ) << ")" << endl;
	if (ans>exp) ans=exp;
  }
  //getline (cin,str);

  printf("Case #%d: %lf\n",t,ans);
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
