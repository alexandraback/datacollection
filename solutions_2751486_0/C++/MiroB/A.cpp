#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
int main() {
  int T;
  cin>>T;
  REP(tt,T) {
    string s;
    int k;
    cin>>s>>k;
    vector<int> a;
    long long int n=s.size();
    REP(i,n) {
      if(string("aeiou").find(s[i])!=string::npos) {
        a.push_back(0);
      } else {
        a.push_back(1);
      }
    }
    long long int rval=0;
    for(int i=n-2;i>=0;--i) {
      if(a[i])a[i]+=a[i+1];
    }
    long long int b=-1;
    for(int i=n-1;i>=0;--i) {
      if(a[i]>=k) {
        b=i;
      }
      if(b!=-1) {
        rval+=n-(b+k-1);
      }
    }


    cout<<"Case #"<<(tt+1)<<": "<<rval<<endl;
  }
}
// issue choosing small type
