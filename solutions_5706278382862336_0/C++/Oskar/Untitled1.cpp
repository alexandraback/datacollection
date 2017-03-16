#include <cstdio>

int n, j;
long long x, y;

void func(int k){
	if(x == 0){
		printf("%d\n", j);
		return;
	}
	if(y % 2 || x == 0 || k > 40){
		printf("impossible\n");
		return;
	}
	y /= 2;
	if(x >= y){
		if(!j) j = k;
		x -= y;
		func(k + 1);
		return;
	}
	func(k + 1);
}

int main(){
	freopen("abc.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%I64d/%I64d", &x, &y);
		printf("Case #%d: ", i);
		j = 0;
		func(1);
	}
	scanf("\n");
	return 0;
}
