#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define lli long long int 

#define sf scanf
#define pf printf
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repr(i, a, b) for(int i = (a); i <= (b); --i)

lli r, t, a1, n;

lli buscaBinaria( lli in, lli fim, lli x) {
   lli e, m, d;
   e = in; d = fim;
   while (e <= d) { 
      m = (e + d)/2; 
      if (2*t == m*(2*a1+(m-1)*4)) return m;
      if (2*t < m*(2*a1+(m-1)*4)) d = m - 1;
      else e = m+1;
   }
   while(2*t < e*(2*a1+(e-1)*4)){
		e--;
	}
   return e;
}

int main(){
	int c = 1, test;
	
	sf("%d", &test);
	while(test--){
		scanf("%lld %lld", &r, &t);
		lli res = 1;
		
		a1 = (r+1)*(r+1) - (r*r);
		n = 1;
		while(2*t > n*(2*a1+(n-1)*4)){
			n*=2;
		}
		//printf("%lld\n", n); 
		//res += buscaBinaria(2, n,
		/*while(2*t < n*(2*a1+(n-1)*4)){
			n--;
		}*/
		res = buscaBinaria(n/2, n, a1);
		//res = n;
		
		pf("Case #%d: %lld\n", c++, res);
	}
	

return 0;
}
