#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long LL;

long long r, t;

//is it uncorrect?
bool check(LL n){
	LL a1 = 2 * r + 1, an, d = 4;
	an = a1 + (n - 1) * 4;
	LL A = a1 + an;
	LL B = t * 2 / n;
	if(A <= B) return false;
	return true;
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T, ca = 0;
	scanf("%d", &T);
	while(T--){
		ca++;
		scanf("%lld%lld", &r, &t);
		LL L = 1, R = 1e18, mid;
		while(R - L > 1){
			mid = (L + R) >> 1;
			if(check(mid)) R = mid - 1;
			else L = mid;
		}
		if(!check(R)) L = R;
		printf("Case #%d: %lld\n", ca, L);
	}
	return 0;
}