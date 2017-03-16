#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;


int R, C, W;

int main(){
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++){
		scanf("%d %d %d", &R, &C, &W);

		int holes = C/W;

		int ans;
		if(W == 1){
			ans = C*R;
		}else{
			if(C%W > 0) ans = holes*R + W;
			else ans = holes*R + W-1;
		}

		printf("Case #%d: %d\n", t, ans);
	}
}
