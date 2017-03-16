#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int N_size = 102;
int f[N_size][N_size ];
ifstream input;
ofstream output;

int update(int& a,int b) {
  a =  max(a,b);
  return a;
}

void Work() {
  int n,s,p;
  input>>n>>s>>p;
  memset(f,-1,sizeof(f));
  //-1 invalid
  f[0][0] = 0;
  vector <int> ssum(n+1, 1);
  for (int i = 1;i<= n;++i ) {
    input>>ssum[i];
    //cout<<ssum[i]<<" ";
  }
  int si;
  for (int i = 1;i <= n;++i) {
    int t = ssum[i]/3;
    int res = ssum[i] - 3 *t;
    switch(res) {
      case 0:
        for (si = 0; si<= s;++si)
          if (f[i-1][si]>=0) {
            if (t >= 1 && t < 10) { 
              update(f[i][si+1], f[i-1][si] + (t+1>=p));
            }
            update(f[i][si], f[i-1][si] + (t>=p));
          }
        break;
      case 1:
        for (si = 0;si<=s;++si)
          if (f[i-1][si]>=0) {
            if (t >=1) {
              update(f[i][si+1], f[i-1][si]+ (t+1>=p));
            }
            update(f[i][si],f[i-1][si] + (t+1>=p));
          }
        break;
      case 2:
        for (si = 0;si<=s;++si)
          if (f[i-1][si]>=0) {
            if ( t < 9)
             update(f[i][si+1],f[i-1][si] + (t+2>=p));
             update(f[i][si],f[i-1][si] + (t+1>=p));
          }
        break;
    }
  }
  //cout<<f[n][s]<<endl;
  output<<f[n][s]<<endl;  
}

int main() {
  int t = 0;
  string inputfile("inputB.in");
  string outputfile("outputB.out");
  input.open(inputfile.c_str());
  output.open(outputfile.c_str());
  input>>t;
  
  int tcase = 0;
  while( t--) {
    ++tcase;
    output<<"Case #"<<tcase<<": "; 
    Work();
  }
}
