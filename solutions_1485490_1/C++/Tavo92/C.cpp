#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define forn(a, n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a, all) for(typeof((all).begin()) a = (all).begin(); a != (all).end(); ++a)

#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define dforsn(a,s,n) for(int a = (n)-1; a>=(s); --a)
#define dforall(a, all) for(typeof((all).rbegin()) a = (all).rbegin(); a != (all).rend(); ++a)

#define contains(mask, bit) ((mask & (1LL<<bit)) != 0LL)

typedef long long tint;

int T, n, m, tipo[2][104];
tint cant[2][104];

tint dp[104][104];
tint calc(int a, int b){
	if(a == n || b == m) return 0;
	
	tint &ret = dp[a][b];
	if(ret != -1) return ret;
	ret = max(calc(a+1,b), calc(a,b+1));
//	int oa = a, ob = b;
	tint ra = cant[0][a], rb = cant[1][b], rr = 0;
//	cout << ra << " " << rb << endl;
	while(tipo[0][a] == tipo[1][b]){
		rr += min(ra,rb);
		if(ra > rb){
			ra -= rb;
			rb = 0;
		}else{
			rb -= ra;
			ra = 0;
		}
		
//		cout << "Wiii " << rr << " " << ra << " " << rb << endl;
		ret = max(calc(a+1,b+1)+rr, ret);
		if(ra == 0 && rb == 0) break;
		if(ra != 0){
			int sb = -1;
			forsn(j, b+1, m) if(tipo[1][j] == tipo[0][a]){
				sb = j;
				break;
			}
			if(sb == -1) break;
			b = sb;
			rb = cant[1][b];
		}else{
			int sa = -1;
			forsn(j, a+1, n) if(tipo[0][j] == tipo[1][b]){
				sa = j;
				break;
			}
			if(sa == -1) break;
			a = sa;
			ra = cant[0][a];
		}
	}
	
//	cout << oa << " " << ob << " " << ret << endl;
//	cout << a << " " << b << endl;
	return ret;
}

int main()
{
#ifdef __YO__
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
#endif
	
	cin >> T;
	forn(t,T){
		cin >> n >> m;
		forn(i,n)
			cin >> cant[0][i] >> tipo[0][i];
		forn(i,m)
			cin >> cant[1][i] >> tipo[1][i];
		
		memset(dp,-1,sizeof(dp));
		
//		calc(0,0);
		printf("Case #%i: ", t+1);
		cout << calc(0,0) << endl;
	}

	return 0;
}
