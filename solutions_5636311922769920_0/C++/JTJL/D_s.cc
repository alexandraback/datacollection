#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("Ds0.in", "r", stdin);
	freopen("Ds0.out", "w", stdout);
	int T, K, C, S;
	cin>>T;
	for(int i = 1; i <= T; i++){
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", i);
		for(int j = 1; j <= S; j++)
			printf(" %d", j);
		puts("");
	}
	return 0;
} 
