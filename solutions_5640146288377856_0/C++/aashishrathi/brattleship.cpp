#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		int r,c,w;
		scanf("%d %d %d",&r, &c, &w);
		int a = (c%w==0)?0:1;
		int ans = r*(c/w + w - 1 + a);
		printf("Case #%d: %d\n",i,ans);
	}
}