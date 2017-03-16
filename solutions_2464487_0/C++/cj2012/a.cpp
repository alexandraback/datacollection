/*
ID: qazzaq71
PROG: packrec
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

ll r, t;
ll res;
ll mmax_t = 2ll * (ll)1e18;

ll mle(ll n){
//	printf("%lld\n", 2 * n + (2 * r - 1));
	return 2 * n + (2 * r - 1) <= t / n;
}
ll mbfind(ll low, ll high){
	while(low <= high){
		ll mid = (low + high) / 2;
		if(mle(mid)){
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return high;
}
int main(){
	FILE * ptrFILE=freopen("a.in","r",stdin);
	assert(ptrFILE!=NULL);
	ptrFILE=freopen("a.out","w",stdout);
	assert(ptrFILE!=NULL);
	int T;
	scanf("%d", &T);
	for(int cs = 1; cs <= T; cs++){
		scanf("%lld %lld", &r, &t);
//		printf("%lld %lld", r, t);
		res = 0;
//		ll k = -(2 * r - 1) / 4;
		res = mbfind(1, mmax_t);
		printf("Case #%d: %lld\n", cs, res);
	}
    return 0;
}
