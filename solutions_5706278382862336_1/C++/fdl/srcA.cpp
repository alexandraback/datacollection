#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define DBG 0
#define name "A-large"
#define DB(a) #a " == " << (a) << ";	"
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define lli long long int
#define ulli unsigned lli

namespace solution{
	const int NMAX = 40;
	lli plog[NMAX+1];


	void precount(){
		plog[0] = 1; FOR(i,1,NMAX+1) plog[i] = plog[i-1]*2;
	}

	int binlog(lli inn){
		lli n = 0, N = inn;
		while (N / 2 > 0) N /= 2, ++n;
		return n;
		/*int n = 0; while (N >= plog[n]) ++n;
		return n-1;*/
	}



	int solve(){
		lli P,Q;
		scanf("%I64d/%I64d", &P, &Q);

		lli p = P, q = Q, d = 1;
		while (!(q%2)) q /= 2;
		d = q, q = Q;
		if (p%d)
			return -1;
		else
			p /= d, q /= d;
		return binlog(q) - binlog(p);

	}

}


int main(){
	if (DBG <= 2) freopen(name".in","r",stdin);
	if (DBG <= 1) freopen(name".out","w",stdout);
	solution::precount();

	int T;
	cin >> T;
	FOR(t,0,T){
		printf("Case #%d: ", t+1);
		int ans = solution::solve();
		if (ans == -1)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}













esc:
#if DBG // == 0
	if (DBG <= 2) freopen("CON","r",stdin);
	if (DBG <= 1) freopen("CON","w",stdout);
	system("pause");
#endif
	return 0;
}
