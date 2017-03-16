#include <bits/stdc++.h>
using namespace std;

const int N = 32, M = 500;
const int pri[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int a[60];

bool check(){
	vector<int> ans;
	for(int k = 2; k <= 10; k++){
		bool flag = 0;
		for(int j = 0; j < 25 && !flag; j++){
			int cnt = 0;
			for(int i = N - 1; i >= 0; i--){
				cnt = cnt * k + a[i];
				cnt %= pri[j];
			}
			if(cnt == 0) ans.push_back(pri[j]), flag = 1;
		}
		if(!flag) return 0;
	}
	for(int i = N - 1; i >= 0; i--) printf("%d", a[i]);
	for(auto v : ans) printf(" %d", v);
	printf("\n");
	return 1;
}

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int ans = 0; printf("Case #1:\n");
	for(int i = 1; ; i += 2){
		for(int j = 0; j < N; j++) a[j] = (i >> j) & 1;
		a[N - 1] = 1;
		if(check()) ans++;
		if(ans == M) break;
	}
	return 0;
}
