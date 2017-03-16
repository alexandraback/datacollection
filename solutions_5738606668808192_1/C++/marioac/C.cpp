#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;

//ifstream cin("C-small-attempt0.in");
ofstream fout("C-large.out");
int main() {
    int T; cin >> T;
    int N,J;
    cin >> N >> J;
    int divisors[6] = {2,3,5,7,11,13}; 
    int storage[11];
    int mult,res;
    fout << "Case #1:" << endl;
    while (J > 0) {
      unsigned int z = (1<<(N-1))+1;
      for (int i=1; i<N-1; i++) { z |= ((rand()&1) << i); }
      for (int j=2; j<=10; j++) { storage[j] = 0;
        for (int k=0; k<6; k++) {
            mult=1; res=0;
            for (int i=0; i<N; i++) { res += ((z>>i)&1)*mult; mult = (mult*j)%divisors[k]; }
            if (res%divisors[k] == 0) storage[j] = divisors[k];
          }
        }
        bool nope=false;
        for (int j=2; j<=10; j++) if (storage[j] == 0) { nope = true; break; } 
        if (nope) continue;
        for (int i=N-1; i>=0; i--) fout << ((z>>i)&1);
        for (int j=2; j<=10; j++) fout << " " << storage[j]; fout << endl;
        J--;
    }
return 0;
}
