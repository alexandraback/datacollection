#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		//Solve 1*N
		int R, C, W, ans;
		scanf("%d %d %d", &R, &C, &W);
		ans = C/W;
		ans = ans * R;
		
		if(C % W == 0){
			ans += W-1;
		} else{
			ans += W;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}