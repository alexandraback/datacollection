#include <bits/stdc++.h>
#define LL long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORIT(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; for (int i = 0 ; i < v.size(); ++i) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p)
{ return s << "(" << p.first << "," << p.second << ")"; }

LL rev(LL n){
  stringstream ss;
  ss<<n;
  string st = ss.str();
  reverse(st.begin(),st.end());
  stringstream ss1(st);
  LL ret;
  ss1>>ret;
  return ret;
}

map<LL,int> dp;

int search(LL n){
  if(n == 0) return 0;
  if(dp.find(n) != dp.end()) return dp[n];

  int r_val = 100000000;
  if(n % 10 != 0){
    int r_try = rev(n);
    if(r_try < n){
      r_val = 1 + search(rev(n));
    }
  }

  int m_val = 1 + search(n-1);
  
  int val = MIN(r_val,m_val);
  dp[n] = val;
  //cout << n << " " << val << endl;
  return val;
}

int greedy(LL n){
  int c = 0;
  while(n > 0){
    int r_val = 1000000000;
    if(n % 10 != 0){
      r_val = rev(n);
    }
    int m_val = n-1;
    n = MIN(r_val,m_val);
    c++;
  }
  return c;
}

int main(){
  int TC;cin>>TC;
  FOR(tc,TC){
    int N;cin>>N;
    cout << "Case #" << tc+1 << ": " << search(N) << endl;
  }
}

