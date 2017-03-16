#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#define LL long long
using namespace std;

string inp;
int T,n;
LL m;

int main() {
  ifstream f("ib.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n>>m; string rz="POSSIBLE";
    int pd=0;
    for(;(1LL<<pd)<=m; ++pd); --pd;
    if(pd>n-2 || (pd==n-2 && m>(1LL<<pd)))rz="IMPOSSIBLE";
    string ma[55];
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) ma[i]+='0';
    for(int i=0; i<n-1; ++i) ma[i][i+1]='1';
    int ld=pd+2;
    for(int i=0; i<ld; ++i) for(int j=i+1; j<ld; ++j) ma[i][j]='1';
    //
    for(--pd;pd>=0;--pd) if(m&(1LL<<pd)) {
      cout<<n<<' '<<pd<<' '<<m<<'\n';
      ma[pd+1][n-1]='1';
    }
    
    g<<"Case #"<<t<<": "<<rz<<'\n';
    if(rz=="POSSIBLE")
      for(int i=0; i<n; ++i) g<<ma[i]<<'\n';
  }
}