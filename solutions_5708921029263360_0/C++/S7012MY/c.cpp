#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#define LL long long
using namespace std;

set<string> s;
int T,n[3],k,fr[3][55][55],prm[3];

void bk(int p,string c) {
  if(p==3){
    if(fr[0][c[0]-'0'][c[1]-'0']<k && fr[1][c[1]-'0'][c[2]-'0']<k && fr[2][c[0]-'0'][c[2]-'0']<k) {
      s.insert(c);
      fr[0][c[0]-'0'][c[1]-'0']++; fr[1][c[1]-'0'][c[2]-'0']++; fr[2][c[0]-'0'][c[2]-'0']++;
    }
    return;
  }
  for(int i=0; i<n[prm[p]]; ++i) bk(p+1,c+char(i+'0'));
}

int main() {
  ifstream f("ic.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n[0]>>n[1]>>n[2]>>k;
    memset(fr,0,sizeof(fr));
    s.clear();
    prm[0]=0; prm[1]=1; prm[2]=2;
    int lst=-1;
    bk(0,"");
    /*do {
      memset(fr,0,sizeof(fr)); s.clear();
      bk(0,"");
      if(lst!=-1 && s.size()!=lst) cout<<n[0]<<' '<<n[1]<<' '<<n[2]<<'\n';
      lst=s.size();
    }while(next_permutation(prm,prm+3));*/
    g<<"Case #"<<t<<": "<<s.size()<<'\n';
    memset(fr,0,sizeof(fr));
    for(auto i:s) {
      for(int j=0; j<i.size(); ++j) g<<int(i[j]-'0')+1<<' ';
      ++fr[0][i[0]][i[1]]; ++fr[1][i[1]][i[2]]; ++fr[2][i[0]][i[2]];
      if(fr[0][i[0]][i[1]]>k) cout<<"naspa";
      if(fr[1][i[1]][i[2]]>k) cout<<"naspa";
      if(fr[2][i[0]][i[2]]>k) cout<<"naspa";
      g<<'\n';
    }
  }
}