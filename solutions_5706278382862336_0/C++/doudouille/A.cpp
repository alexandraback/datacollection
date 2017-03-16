
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	int T;	
	cin >> T;

  for(int t = 1; t <= T; t++) {

    string S;
    cin >> S;
    for(int i = 0; i < S.length(); i++) if(S[i] == '/') S[i] = ' ';
    stringstream SS(S);
    long long P, Q;
    SS >> P >> Q;


    long long gcd = __gcd(P, Q);
    P /= gcd;
    Q /= gcd;

    int nb = 0;
    bool impossible = false;
    while(P > 0) {
      if(Q % 2 != 0) {impossible = true; break;}
      P /= 2;
      Q /= 2;
    }
    while(Q != 1) {
      if(Q %2 != 0) {impossible = true; break;}
      Q = Q/2;
      nb++;
    }


    if(impossible) cout << "Case #" << t << ": impossible" << endl;
    else cout << "Case #" << t << ": " << (nb+1) << endl;



  }


}
