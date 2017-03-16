#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define repd(i,a,b) for(int (i)=(b)-1;(i)>=(a);(i)--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair
#define countbits(x) __builtin_popcount(x)
#define countbitslld(x) __builtin_popcountll(x)

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int inside(int mask, int c, int w){
  int ship = (1 << w) - 1;
  REP(i,c){
    if(i + w > c) break;
    int t = ship << i;
    if((mask & t) == 0) return true;
  }
  return false;
}

int f2(int k, int mask, int c, int w){
  int i = k - 1;
  int j = k + 1;
  while((i >= 0) and ((mask >> i) & 1) == 0) i--;
  while((j < c) and ((mask >> j) & 1) == 0) j++;

  int len = j - i - 1;
  if(len == w) return w - 1;
  else if(len > w) return w;
  else assert(false);
}

int dp[1<<25];

int found, notfound;
int f(int mask, int c, int w){
  if(dp[mask]) return 0;
  dp[mask] = 1;

  REP(i,c){
    if(((mask >> i) & 1) == 0){
      mask ^= 1 << i;
      if(inside(mask, c, w) == false){
	notfound = min(notfound, countbits(mask));
	int cnt = countbits(mask) + f2(i, mask, c, w);
	found = min(found, cnt);
      }else{
	f(mask, c, w);
      }
      mask ^= 1 << i;
    }
  }

  return 0;
}

int main(){ IO;
  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int r, c, w;
    cin >> r >> c >> w;

    memset(dp, 0, sizeof dp);
    found = INT_MAX, notfound = INT_MAX;
    f(0, c, w);
    cout << found + (r-1) * notfound << endl;
  }

  return 0;
}
