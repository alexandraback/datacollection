#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#define LL long long
using namespace std;

string a,b;
int T;

string min(string a,string b) {
  string ra=a,rb=b;
  reverse(ra.begin(),ra.end());
  reverse(rb.begin(),rb.end());
  //cout<<a<<' '<<b<<" "<<a.compare("")<<'\n';
  //if(a.compare("")==0) return b;
  if(ra>rb) return b;
  return a;
}

int main() {
  ifstream f("ib.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>a>>b;
    //tin cea mai mare diferenta, cea mai mica si cea mai apropiata de 0
    LL dc[]={0,0,0};
    string sca[3],scb[3];
    LL _10=1;
    for(int pz=a.size()-1; pz>=0; --pz,_10*=10LL) {
      int li=0,Li=9,lj=0,Lj=9;
      if(a[pz]!='?') li=Li=a[pz]-'0';
      if(b[pz]!='?') lj=Lj=b[pz]-'0';
      LL dn[]={-(1LL<<62),(1LL<<62),(1LL<<62)};
      string sna[3]={"-","-","-"},snb[3]={"-","-","-"};
      //cout<<pz<<' '<<li<<' '<<Li<<' '<<lj<<' '<<Lj<<'\n';
      for(int i=li; i<=Li; ++i) for(int j=lj; j<=Lj; ++j) for(int l=0; l<3; ++l)
        {
          if(dn[0]<=_10*(i-j)+dc[l]) {
            
            if(dn[0]<_10*(i-j)+dc[l]) {
              sna[0]=sca[l]+char(i+'0');
              snb[0]=scb[l]+char(j+'0');
            }else {
              sna[0]=min(sna[0],sca[l]+char(i+'0'));
              snb[0]=min(snb[0],scb[l]+char(j+'0'));
            }
            dn[0]=_10*(i-j)+dc[l];
          }
          if(dn[1]>=_10*(i-j)+dc[l]) {
            
            if(dn[1]>_10*(i-j)+dc[l]) {
              sna[1]=sca[l]+char(i+'0');
              snb[1]=scb[l]+char(j+'0');
            }else {
              sna[1]=min(sna[1],sca[l]+char(i+'0'));
              snb[1]=min(snb[1],scb[l]+char(j+'0'));
            }
            dn[1]=_10*(i-j)+dc[l];
          }
          if(abs(dn[2])>=abs(_10*(i-j)+dc[l])) {
            
            if(abs(dn[2])>abs(_10*(i-j)+dc[l])) {
              sna[2]=sca[l]+char(i+'0');
              snb[2]=scb[l]+char(j+'0');
            }else {
              sna[2]=min(sna[2],sca[l]+char(i+'0'));
              snb[2]=min(snb[2],scb[l]+char(j+'0'));
            }
            dn[2]=_10*(i-j)+dc[l];
          }
        }
      for(int l=0; l<3; ++l) {
        dc[l]=dn[l];
        sca[l]=sna[l];
        scb[l]=snb[l];
      }
      //cout<<dc[0]<<' '<<dc[1]<<' '<<dc[2]<<'\n';
      //cout<<"A:"<<sna[0]<<' '<<sna[1]<<' '<<sna[2]<<'\n';
      //cout<<"B:"<<snb[0]<<' '<<snb[1]<<' '<<snb[2]<<'\n';
      //cout<<'\n';
    }
    reverse(sca[2].begin(),sca[2].end());
    reverse(scb[2].begin(),scb[2].end());
    //cout<<dc[2]<<'\n';
    g<<"Case #"<<t<<": "<<sca[2]<<' '<<scb[2]<<'\n';
  }

}