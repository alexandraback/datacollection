#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <bitset>
#include <ctime>

#define NMax 100005

#define pb push_back
#define po pop_back

#define mp make_pair

using namespace std;

ifstream f("input");
ofstream g("output");

// Global properties
int k,l,s;
string actual;
string keys;
string target;
float occ = 0; // Total posibilities found
int bananas[30];
int maximum = -1;

// Functions
void found() {
      occ++;
      int toGive = 0;
      for (int i=0;i<actual.size();i++) {
            if (target.size()+i-1 < actual.size()) {
                  bool ok = true;

                  for (int j=i;j<target.size()+i && ok;j++) {
                        if (target[j-i] != actual[j])
                              ok = false;
                  }

                  if (ok)
                        toGive++;
            }
      }

      bananas[toGive]++;
      maximum = max(toGive, maximum);
}

void go(int k) {
      if (k == s) {
            found();
            return;
      }

      for (int i=0;i<keys.size();i++) {
            actual += keys[i];
            go(k+1);
            actual.po();
      }
}

void solve() {
      occ = 0;
      maximum = -1;
      for (int i=0;i<25;i++)
            bananas[i] = 0;
      go(0);

      // Finding the answer, the percentage
      float tun = 0;
      for (int i=0;i<15;i++)
            if (bananas[i] > 0) {
                  tun += (float)i * (bananas[i]/occ);
            }
      g<<fixed<<setprecision(9)<<((float)maximum)-tun;
}

void read() {
      f>>k>>l>>s;
      f>>keys;
      f>>target;

      solve();
}

int main() {

      // Main code
      float oldTime = clock();

      int t; f>>t;
      for (int i=1;i<=t;i++) {
            g<<"Case #"<<i<<": ";
            read();
            g<<'\n';
      }

      cout<<"\nExecution took "<<fixed<<setprecision(5)<<(clock()-oldTime)/CLOCKS_PER_SEC<<"\n\n";


      f.close(); g.close();
      return 0;
}
