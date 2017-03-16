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

const int MAXN = 1010;

int N;
int out[MAXN];
int clen[MAXN];
int cyc[MAXN];
bool used[MAXN];
int zmax[MAXN];

int calc()
{
  int ans = 0;
  for(int i=0; i<N; i++)
    zmax[i] = 0;
  for(int v=0; v<N; v++)
  {
    int cur = v;
    clen[v] = 0;
    for(int i=0; i<N; i++)
      used[i] = false;
    used[v] = true;
    for(int i=1; ; i++)
    {
      cur = out[cur];
      if(used[cur])
      {
        cyc[v] = cur;
        clen[v] = i;
        break;
      }
      used[cur] = true;
    }
  }
  //for(int i=0; i<N; i++) cout<<clen[i]<<" ";cout<<endl;
  //for(int i=0; i<N; i++) cout<<cyc[i]<<" ";cout<<endl;

  for(int i=0; i<N; i++)
  {
    int c = cyc[i];
    if(c != i && clen[c] == 2)
      zmax[c] = max(zmax[c], clen[i] - 2);
  }

  int two = 0;
  for(int i=0; i<N; i++)
  {
    if(cyc[i] != i) continue;
    int a = clen[i];
    if(a == 2)
    {
      a += zmax[i] + zmax[out[i]];
      if(i < out[i])
        two += a;
    }
    else
    {
      ans = max(ans, a);
    }
  }

  ans = max(ans, two);

  return ans;
}

int main() {
  IOS;

  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>N;
    for(int i=0; i<N; i++)
    {
      cin>>out[i];
      out[i]--;
    }

    int ans = calc();
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }

  return 0;
}
