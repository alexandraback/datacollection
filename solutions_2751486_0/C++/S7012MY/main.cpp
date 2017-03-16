#include <iostream>
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
      int rez=0;
      for(int i=0; i<s.size(); ++i) {
        nr[i]=isc(s[i]);
        for(int j=i; j<s.size(); ++j) {
          int ok=0;
          if(j>i) {
            if( isc(s[j])) nr[j]=nr[j-1]+1;
            else nr[j]=0;
          }
          for(int k=i; k<=j; ++k) if(nr[k]>=n) ok=1;
          rez+=ok;
        }
      }
      g<<"Case #"<<T<<": ";
      g<<rez<<"\n";
    }
    return 0;
}
