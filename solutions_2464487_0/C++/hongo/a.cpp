#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define lli long long int 

#define sf scanf
#define pf printf
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repr(i, a, b) for(int i = (a); i <= (b); --i)

lli r, t;

int main(){
	int c = 1, test;
	
	sf("%d", &test);
	while(test--){
		scanf("%lld %lld", &r, &t);
		lli res = 0;
		
		lli i = 0;
		while(t>0){
			t -= ((r+i+1)*(r+i+1) - (r+i)*(r+i));
			i+=2;
			if(t >= 0) res++;
			//printf("%llu\n", t);
		}
		pf("Case #%d: %lld\n", c++, res);
	}
	

return 0;
}
