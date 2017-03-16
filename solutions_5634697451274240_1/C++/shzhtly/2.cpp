#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

char str[maxn];

int main(){
//	freopen("B-large.in", "r", stdin);
//	freopen("out_b_large.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		char pre = '0';
		int cnt = 0;
		for(int i = 0; str[i]; ++i){
			if(str[i] != pre){
				pre = str[i];
				++cnt;
			}
		} 
		if(pre == '+') --cnt;
		printf("Case #%d: %d\n", ++cases, cnt);
	} 
	return 0;
}
