#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);	
    freopen("B.out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;	cin>>T;
	FOR(cs,1,T) {
		printf("Case #%d: ", cs);
		int A, B, K;	cin>>A>>B>>K;
		int res=0;
		rep(i,A)
		rep(j,B) if((i&j)<K)
			++res;
		printf("%d\n", res);
	}
	return 0;
}