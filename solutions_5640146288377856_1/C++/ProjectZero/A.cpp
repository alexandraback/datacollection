#include <bits/stdc++.h>
using namespace std;

int R,C,W;

void run(int test){
	scanf("%d %d %d",&R,&C,&W);
	if(W == 1){
		printf("Case #%d: %d\n",test,R*C);
		return ;
	}

	int ans = 0,included = false;
	for(int i=1;i<=R;i++){
		for(int j=W;j<=C;j+=W){
			ans++;
			if(i == R && j+W > C && j != C){
				ans++;
			}
		}
	}
	ans += W-1;
	printf("Case #%d: %d\n",test,ans);
}

int main(){
	// freopen("A.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}