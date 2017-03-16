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

	if(x>=7)
		return false;
	if(x==1)
		return true;
	if(r*c%x!=0)
		return false;


	minv = (r<c?r:c);
	maxv = (r>c?r:c);

	if(x==2){
		return true;
	}else if(x==3){
		if(minv == 1)
			return false;
		return true;
	}else if(x==4){
		if(minv < 3)
			return false;
		return true;
	}else if(x==5){
		if(minv < 3)
			return false;
		if(minv == 3){
			if(maxv==5)
				return false;
			else
				return true;
		}
		return true;
	}else if(x==6){
		if(minv < 4)
			return false;
		return true;
	}
}
