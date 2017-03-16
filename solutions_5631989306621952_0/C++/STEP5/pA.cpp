#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
  return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
  s<<"[ ";
  for (auto it : c) s << it << " ";
  s<<"]";
  return s;
}
// Let's Fight!

string s;

string calc()
{
  string ret = "";
  for(auto c: s)
  {
    ret = max(ret + c, c + ret);
  }

  return ret;
}

int main() {
  IOS;

  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>s;
    string ans = calc();
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }

  return 0;
}
