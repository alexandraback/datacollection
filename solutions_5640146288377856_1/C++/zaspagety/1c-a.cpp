#include <bits/stdc++.h>

#define REP(i, b) for (int i = 0; i < int(b); i++) 
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
  
#define pb push_back
#define mp make_pair
#define fi first
#define se second
           
#define INF 2000000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair< int, ii> ipii;
typedef vector<ii> vii;
typedef set<int> si;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


int main(){
	int T, R, C, W;
	scanf("%d", &T);
	REP(tt, T){
		scanf("%d%d%d", &R, &C, &W);
		int k=C/W;
		int ans=k*R;
		ans+=W;
		if(k*W==C)ans--;
		printf("Case #%d: %d\n", tt+1, ans);
	}
}