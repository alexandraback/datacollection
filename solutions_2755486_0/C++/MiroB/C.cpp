#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
class ATK{
  public:
    int str, left,right;
    ATK(int str_, int left_, int right_):str(str_),left(left_),right(right_){}
    ATK(){}
};
bool operator<(const ATK &a,const ATK &b) {
return 0;
//  return a.left-b.left;
}
int main() {
  int T;cin>>T;


  REP(tt,T) {
    int n;
    cin>>n;
    vector<pair<int, ATK> > attacks;
    REP(i,n) {
      int d,num,w,e,s,dd,dp,ds;
      cin>>d>>num>>w>>e>>s>>dd>>dp>>ds;
      REP(j,num) {
        attacks.push_back(make_pair(d+dd*j,ATK(s+j*ds,w+dp*j,e+dp*j)));
      }
    }
//    cout<<"A"<<endl;
    sort(attacks.begin(), attacks.end());
  //  cout<<"B"<<endl;
    int i=0;
    int O=420;
    vector<int> W(O*2);
    int rval=0;
    while(i<(int)attacks.size()) {
      int j=i+1;
      while(j<(int)attacks.size() && attacks[j].first==attacks[i].first) ++j;
      for(int k=i;k<j;++k) {
        int pre=0;
        ATK &a=attacks[k].second;
        for(int x=a.left;x<a.right;++x) if(W[x+O]<a.str) pre=1;
        rval+=pre;
      }
      for(int k=i;k<j;++k) {
        ATK &a=attacks[k].second;
        for(int x=a.left;x<a.right;++x) W[x+O]=max(W[x+O],a.str);
      }
      i=j;
    }

    cout<<"Case #"<<(tt+1)<<": "<<rval<<endl;
  }

}
// issue choosing small type
