#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

int e, r, n;
int mx;
int resp[11], v[11];

int feasible(){
	int at = e;
	for(int i = 0; i < n; ++i){
		at-= resp[i];
		if(at < 0) return 0;
		at = min(at+r, e);
		
	}
return 1;
}

void f(int k){
	if(k == n){
		//for(int i = 0; i < n; ++i) printf("%d ", resp[i]); printf("\n");
		if(feasible()){
			int res = 0;
			for(int i = 0; i < n; ++i) res += v[i]*resp[i];
			mx = max(mx, res);
		}
		return;
	}
	for(int i = 0; i <= e; ++i){
		resp[k] = i;
		f(k+1);
	}
}

int main(){
	int c = 1, t;
	
	sf("%d", &t);
	while(t--){
		scanf("%d %d %d", &e, &r, &n);
		for(int i = 0; i < n; ++i) sf("%d", &v[i]);
		mx = -1;
		f(0);
		pf("Case #%d: %d\n", c++, mx);
	}

return 0;
}
