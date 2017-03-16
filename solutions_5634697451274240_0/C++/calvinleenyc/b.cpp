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

int main(){
	if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	dri(T);
	rep(Tc,0,T){
	  cout << "Case #" << (Tc+1) << ": ";
	  string s; cin >> s;
	  int ans = 1;
	  rep(i,1,s.length()){
	    if(s[i] != s[i-1]) ans++;
	  }
	  if(s[s.length() - 1] == '+') ans--;
	  cout << ans << "\n";
	}
	return 0;
}
