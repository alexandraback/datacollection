#include <cstdio>
#include <vector>
#define LL long long
using namespace std;
LL ans;
int maxE, plusE, n;
int arr[10000];
void recu(int idx, int got, LL win){
	if(idx == n){
		ans = max(ans, win);
	}else{
		for(int i = 0; i <= got; i++){
			recu(idx + 1, min(maxE, got - i + plusE), win + (LL)i * arr[idx]);
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		ans = 0;
		scanf("%d %d %d", &maxE, &plusE, &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		recu(0, maxE, 0);
		printf("Case #%d: %lld\n", test, ans);
	}
	return 0;
}

