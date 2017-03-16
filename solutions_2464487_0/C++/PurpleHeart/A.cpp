#include <cstdio>
#include <cmath>

int cases;
long long R, T;

bool check(long long v){
	long long q1 = 2 * v - 1;
	long long q2 = 2 * v;
	long long tot1 = q1 * q2 / 2;
	long long nowx = T - tot1;
	if(nowx < 0) return false;
	long long cnt = nowx / R;
	if(cnt >= 2 * v) return true;
	else return false;
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%I64d%I64d", &R, &T);
		long long l = 0, r = sqrt(T);
		while(l <= r){
			long long mid = (l + r) / 2;
			if(check(mid)){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		long long ans;
		for(long long i = l - 10; i <= r + 10; ++i)
			if(check(i)) ans = i;
		printf("Case #%d: %I64d\n", xx, ans);
	}
}
