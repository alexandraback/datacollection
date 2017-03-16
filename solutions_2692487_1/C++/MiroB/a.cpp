#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int num;
int main() {
int T;
cin>>T;
REP(tt,T) {
  num a;
  int n;
  cin>>a>>n;
  vector<num> x(n);REP(i,n) cin>>x[i];
  sort(x.begin(), x.end());
  int rval=n;
  int op=0;
if(a>1)  REP(i,n) {
    while(a<=x[i]) {
      op++;
      a+=a-1;
    }
    a+=x[i];
    rval=min(rval, op+n-i-1);
  }
  cout<<"Case #"<<(tt+1)<<": "<<rval<<endl;
}

}
// issue choosing small type
