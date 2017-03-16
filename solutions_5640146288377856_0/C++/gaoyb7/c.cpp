#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int cas=0;
	scanf("%d",&t);
	while(t--){
		int ans;
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		ans = (c/w)*r +w-1;
		if(c%w!=0)
			ans++;
		printf("Case #%d: %d\n",++cas,ans);
	}
}