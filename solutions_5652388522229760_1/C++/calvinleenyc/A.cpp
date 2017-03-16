#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<cassert>
#include<cmath>

//code by cl3488

#define dri(X) int (X); scanf("%d", &X)
#define drii(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define driii(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define pb push_back
#define mp make_pair
#define rep(i, s, t) for ( int i=(s) ; i <(t) ; i++)
#define fill(x, v) memset (x, v, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define why(x) cerr << #x << ": " << (x) << endl;
#define whisp(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define exclam cerr << "!!\n"
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const ll inf = (ll)1e9 + 70;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 1000;

string to_stringg(ll n){
  string ans = "";
  while(n != 0){
    ans = ans + (char)(n % 10 + '0');
    n = n / 10;
  }
  return ans;
}

int main(){
	if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	dri(T);
	rep(Tc,0,T){
	  cout << "Case #" << (Tc+1) << ": ";
	  dri(N);
	  if(N == 0){
	    cout << "INSOMNIA" << "\n";
	    continue;
	  }
	  vector<bool> seen(10);
	  ll n = N;
	  while(true){
	    //process n
	    string s = to_stringg(n);
	    rep(e,0,s.length()){
	      seen[s[e] - '0'] = true;
	    }
	    bool done = true;
	    rep(e,0,10) if(!seen[e]) done = false;
	    if(done){
	      cout << n << "\n";
	      break;
	    }
	    n += N;
	  }
	}
	return 0;
}
