/*#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string s;
int t,n,nr[1000005];

int isc(char c) {
  return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}

int main()
{
    ifstream f("input.txt");
    ofstream g("output.txt");
    f>>t;
    for(int T=1; T<=t; ++T) {
      f>>s>>n;
      long long rez=0;
      int zeros=0,sj=0;
      for(int i=0; i<s.size(); ++i) nr[i]=0;
      for(int i=0,j=0; i<s.size(); ++i) {
        if(i) {
           if(!isc(s[i-1])) --zeros;
           else if(zeros==0) --sj;
        }
        //cerr<<i<<' '<<j<<' '<<sj<<' '<<zeros<<'\n';
        for(;sj<n && j<s.size();) {
          if(!nr[j]) {
            if(isc(s[j])) ++sj;
            else {
              ++zeros;
              sj=0;
            }
          }
          nr[j]=1;
          //cerr<<n<<' '<<i<<' '<<j<<' '<<sj<<' '<<zeros<<'\n';
          if(sj==n) break;
          ++j;
        }
        if(sj<n) continue;
        rez+=s.size()-j;
        //cerr<<i<<' '<<j<<' '<<sj<<' '<<zeros<<'\n';
      }
      g<<"Case #"<<T<<": ";
      g<<rez<<"\n";
      //while(1);
    }
    return 0;
}
*/
