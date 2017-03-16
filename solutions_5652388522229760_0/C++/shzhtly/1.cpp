#include<bits/stdc++.h>
using namespace std;

int n, cnt;
bool vis[15];

bool div(int num){
	while(num){
		int tmp = num % 10;
		num /= 10;
		if(!vis[tmp]){
			vis[tmp] = 1;
			cnt++;
		}
	}
	return cnt == 10;
}

void solve(int num){
	memset(vis, 0, sizeof(vis));
	cnt = 0;
	int tmp = num;
	while(1){
		if(div(tmp)){
			printf("%d\n", tmp);
			return ;
		}
		else tmp += num;
	}
}

int main(){
//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT){
		scanf("%d", &n);
		printf("Case #%d: ", TT);
		if(n == 0){
			puts("INSOMNIA");
			continue;
		}	
		solve(n);
	}
	return 0;
} 
