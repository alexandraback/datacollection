#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

ll p2[50];
ll gcd(ll x, ll y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	p2[0] = 1;
	REP(i,1,50) p2[i] = p2[i-1]*2;
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		printf("Case #%d: ", csn);
		ll P,Q;
		scanf("%lld/%lld", &P, &Q);
		ll g = gcd(P,Q);
		P/=g; Q/=g;
		int fd = -1;
		REP(i,0,50) {
			if(p2[i]==Q){
				fd = i;
				break;
			}
		}
		if(fd==-1){
			puts("impossible");
			continue;
		}
		int ans = 0;
		for(int i=fd; i>=0; i--){
			ans++;
			ll x = P;
			x = min(p2[i-1], P);
			if(x==p2[i-1]) break;
			P = x;
		}
		if(ans>40) cerr << "dangerous?";
		cout << ans << endl;
	}
	return 0;
}