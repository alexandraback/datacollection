#include <iostream>
#include <vector>
#include <string>

using namespace std;

int runtc() {
  int smax;
  cin>>smax;
  string ss;
  cin>>ss;
  vector<int> s;
  for(int i=0;i<=smax;++i) {
    s.push_back(ss[i]-'0');
  }

  int f = 0;
  int p = 0;
  for(int i=0;i<=smax;++i) {
    if(p < i) {
      f++;
      p++;
    }
    p += s[i];
  }

  return f;
}

int main(int argc, char** argv)  {
  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    int res = runtc();
    cout<<"Case #"<<(i+1)<<": "<<res<<endl;
  }
}
