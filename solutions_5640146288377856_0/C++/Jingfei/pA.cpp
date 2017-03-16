#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		int ans,R,C,W;
		scanf("%d%d%d",&R,&C,&W);
		if(C==W) ans=C;
		else if(C<=W*2) ans=W+1;
		else ans=(C-1)/W+W;
		printf("Case #%d: %d\n",Case,ans);	
	}
	return 0;
}
