#include <cstdio>
#include <iostream>
using namespace std;
int arr[20], e, r, n;

int solve(int item, int energy){
	if(energy > e) energy = e;
	if(item == n-1) return energy * arr[item];
	int ret = 0;
	for(int i = 0; i <= energy; ++i)
		ret = max(ret, arr[item]*i + solve(item+1, energy - i + r));
//	printf("f(%d, %d) = %d\n", item, energy, ret);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		printf("Case #%d: %d\n", kase, solve(0,e));
	}
}
