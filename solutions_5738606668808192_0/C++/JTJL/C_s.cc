#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("Cs0.in", "r", stdin);
	freopen("Cs0.out", "w", stdout);
	int T, n, m;
	cin>>T>>n>>m;
	printf("Case #1:\n");
	/*
	int low = (1 << (n - 1)) + 1, high = (1 << n);
	for(int i = 0; i < n / 2; i++){
		
	}*/
	n -= 2;
	n /= 2;
	for(int i = 1; i <= m; i++){
		printf("1");
		for(int j = 0; j < n; j++) 
			if ((i >> j) & 1)
				printf("11");
			else
				printf("00");
		printf("1");
		for(int j = 2; j <= 10; j++)
			printf(" %d", j & 1 ? 2 : j + 1);
		puts("");
	}
	return 0;
} 
