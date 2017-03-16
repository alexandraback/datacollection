#include <cstdio>
#include <cstring>
int R, C, W;
int main(){
	int ans, TN, ca=0;
	scanf("%d", &TN);
	while(TN--){
		scanf("%d%d%d", &R, &C, &W);
		// if(R==1){
			if(C>W){
				ans=(C-W)/W;
				if(C%W==0){
					ans+=W;
				}
				else{
					ans+=W+1;
				}
			}
			else if(C==W){ //C==W
				ans=W;
			}
			else{
				ans=0;
			}
		// }
		ans+=(R-1)*(C/W);

		printf("Case #%d: %d\n", ++ca, ans);
	}
	return 0;
}