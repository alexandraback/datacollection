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

typedef long long ll;

ll K, C;
int S;

vector<ll> calc()
{
  vector<ll> ret;
  int N = (K+C-1) / C;
  if(N > S) return ret;

  for(int i=0; i<N; i++)
  {
    ll cur = 0;
    for(int j=0; j<C; j++)
    {
      int z = min(i*C+j, K-1);
      cur = cur * K + z;
    }
    cur++;
    ret.PB(cur);
  }

  return ret;
}

int main() {
  IOS;

  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>K>>C>>S;
    vector<ll> ans = calc();
    cout<<"Case #"<<t<<":";
    if(ans.empty())
      cout<<" IMPOSSIBLE";
    else
      for(auto x: ans)
        cout<<" "<<x;
    cout<<endl;
  }

  return 0;
}
