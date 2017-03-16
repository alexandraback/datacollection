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

int put(int di, vi &mark){
  REPD(value,mark.size()){
    if(mark[value]){
      if(value + di < mark.size()){
	mark[value+di] = 1;
      }
    }
  }
  return 0;
}

int main(){ IO;
  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int c, d, v;
    cin >> c >> d >> v;

    vi denomination(d);
    REP(i,d) cin >> denomination[i];

    vi mark(v+1);
    mark[0] = 1;

    REP(i,d){
      int di = denomination[i];
      put(di, mark);
    }

    int ans = 0;
    REP(i,mark.size()) if(mark[i] == 0){
      put(i, mark);
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
