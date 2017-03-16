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

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T, ca = 0;
	scanf("%d", &T);
	while(T--){
		ca++;
		long long r, t, ans = 0;
		scanf("%lld%lld", &r, &t);
		for(int i = r; 2 * i + 1 <= t; i += 2){
			t -= 2 * i + 1;
			ans++;
		}
		printf("Case #%d: %lld\n", ca, ans);
	}

	return 0;
}