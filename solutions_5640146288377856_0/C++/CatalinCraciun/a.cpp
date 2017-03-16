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
int r,c,w;

// Functions
void solve() {
      if (r == 1) {
            int hits = 0;
            for (int i=1;i<=c;i+=w)
                  hits++;
            g<<hits + (w-1);
      }
}

void read() {
      f>>r>>c>>w;
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
