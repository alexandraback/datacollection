#include <bits/stdc++.h>
using namespace std;

void solve(){
	int R,C,W;
	int ans,tmp;
	scanf("%d%d%d",&R,&C,&W);
	if(W==1){
		printf("%d\n",R*C);
		return;
	}
	tmp = C/W;
	if(C%W){
		ans = R * (tmp + W);
	}else{
		if(tmp == 1)ans = R * W;
		else
		ans = R * min( tmp -1 + W, tmp + W);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		printf("Case #%d: ",cas+1);
		solve();
	}
	return 0;
}
