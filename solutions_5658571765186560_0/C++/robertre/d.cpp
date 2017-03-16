#include <iostream>

using namespace std;

bool runtc() {
  int x, r, c;
  cin>>x>>r>>c;
  
  if(x==1) {
    return true;
  }
  if(x==2) {
    return (r*c)%2 == 0;
  }
  if(x==3) {
    if(r==3 && c==3) return true;
    if(r==4 && c==3) return true;
    if(r==3 && c==4) return true;
    if(r==3 && c==2) return true;
    if(r==2 && c==3) return true;
    return false;
  }
  if(x==4) {
    if(r==4 && c==4) return true;
    if(r==4 && c==3) return true;
    if(r==3 && c==4) return true;
    return false;
  }
}

int main(int argc, char** argv) {
  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    bool res = runtc();
    string rr;
    if(!res) {
      rr = "RICHARD";
    } else {
      rr = "GABRIEL";
    }
    cout<<"Case #"<<(i+1)<<": "<<rr<<endl;
  }
}
