#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>

using namespace std;

unsigned long gcd(unsigned long u, unsigned long v)
{
  long shift;
 
  /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
  if (u == 0) return v;
  if (v == 0) return u;
 
  /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
  for (shift = 0; ((u | v) & 1) == 0; ++shift) {
         u >>= 1;
         v >>= 1;
  }
 
  while ((u & 1) == 0)
    u >>= 1;
 
  /* From here on, u is always odd. */
  do {
       /* remove all factors of 2 in v -- they are not common */
       /*   note: v is not zero, so while will terminate */
       while ((v & 1) == 0)  /* Loop X */
           v >>= 1;
 
       /* Now u and v are both odd. Swap if necessary so u <= v,
          then set v = v - u (which is even). For bignums, the
          swapping is just polonger movement, and the subtraction
          can be done in-place. */
       if (u > v) {
         unsigned long t = v; v = u; u = t;}  // Swap u and v.
       v = v - u;                       // Here v >= u.
     } while (v != 0);
 
  /* restore common factors of 2 */
  return u << shift;
}

unsigned long potenciaDeDos(unsigned long q){
	unsigned long res = 1;
	while(q > 2){
		//cout << q << "  "; 
		if((q & 1) == 1){
			return -1;
		}
		else{
			++res;
			q = q >> 1;
		}
	}
	if(q == 1){return -1;}
	//cout << "res " << res << endl;
	return res;

}

unsigned long potenciaDeDosImpar(unsigned long q){
	unsigned long res = 0;
	while(q > 1){
		++res;
		q = q >> 1;
	}
	return res;

}

int main(){
	
	int t;
	unsigned long p,q,a,b,c;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		cin >> p;
		cin >> q;
		//cout << p << " " << q << endl;
		c = gcd(p,q);
		p = p/c;
		q = q/c;
		a = potenciaDeDos(q);
		//cout << a << endl;
		if(a == -1){
			cout << "impossible" << endl;
			continue;
		}
		b = potenciaDeDosImpar(p);
		cout << a-b << endl;
	}




	return 0;
}

