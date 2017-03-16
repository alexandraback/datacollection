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

int used[10];

int calc(int x)
{
  if(x == 0) return -1;
  for(int i=0; i<10; i++)
    used[i] = false;

  for(int i=1; ; i++)
  {
    int now = x * i;
    while(now)
    {
      used[now%10] = true;
      now /= 10;
    }
    bool ok = true;
    for(int j=0; j<10; j++)
      if(!used[j])
        ok = false;
    if(ok)
      return x * i;
  }
}

int main() {
  IOS;

  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    int N;
    cin>>N;
    int res = calc(N);
    cout<<"Case #"<<t<<": ";
    if(res == -1)
      cout<<"INSOMNIA"<<endl;
    else
      cout<<res<<endl;
  }

  return 0;
}
