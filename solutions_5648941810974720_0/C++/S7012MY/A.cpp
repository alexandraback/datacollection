#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string inp;
int T,fr[26];
char arr[]={'Z','W','X','G','H','R','F','V','I','O'};
string dig[]={"ZERO","TWO","SIX","EIGHT","THREE","FOUR","FIVE","SEVEN","NINE","ONE"};
int d[]={0,2,6,8,3,4,5,7,9,1};

int main() {
  ifstream f("ia.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>inp;
    //cout<<inp<<'\n';
    string rz;
    memset(fr,0,sizeof(fr));
    for(int i=0; i<inp.size(); ++i) ++fr[inp[i]-'A'];
    for(int i=0; i<10; ++i) {
      int nr=fr[arr[i]-'A'];
      //cout<<dig[i]<<' '<<nr<<'\n';
      for(int j=0; j<nr; ++j) rz+=d[i]+'0';
      for(int j=0; j<dig[i].size(); ++j) fr[dig[i][j]-'A']-=nr;
    }
    sort(rz.begin(),rz.end());
    g<<"Case #"<<t<<": "<<rz<<'\n';
  }
}