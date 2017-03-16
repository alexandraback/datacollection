#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>

using namespace std;

bool solve();

int main(){
	int cases;
	bool ans;
	scanf("%d", &cases);

	for(int i=0; i<cases; i++){
		printf("Case #%d: ", i+1);
		ans = solve();
		if(ans){
			printf("GABRIEL\n");
		}else{
			printf("RICHARD\n");
		}
	}
	return 0;
}

bool solve(){
	int x, r, c, minv, maxv;
	scanf("%d %d %d", &x, &r, &c);

	minv = (r<c?r:c);
	maxv = (r>c?r:c);

	if(x==1){
		return true;
	}else if(x==2){
		if(minv*maxv%2==0)
			return true;
		return false;
	}else if(x==3){
		if(minv*maxv%3!=0 || minv == 1)
			return false;
		return true;
	}else{
		if(minv*maxv%4!=0 || minv < 3)
			return false;
		return true;
	}
}