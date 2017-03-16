#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t;
long long ggg = 1, x, y, z;
long long gcd(long long a, long long b){
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}


int main(){
	freopen("A0.in","r",stdin);
	freopen("A0.out","w",stdout);
	for (int i = 1; i <= 40; i++)
		ggg *= 2;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		scanf("%lld/%lld", &x, &y);
	    z = gcd(x, y);
	    x /= z;
	    y /= z;
	    printf("Case #%d: ", i);
	    if (ggg % y){
	    	printf("impossible\n");
	    }
	    else{
	    	z = ggg / y * x;
	    	int ans = 40;
	    	while (z){
	    		z/=2;
	    		ans--;
	    	}
	    	printf("%d\n", ans+1);
	    }
	}
	return 0;
}
