#include <iostream>

using namespace std;

long long gcd(long long u, long long v)
{
    int shift;
     
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
														            swapping is just pointer movement, and the subtraction
															              can be done in-place. */
																             if (u > v) {
																	                long long t = v; v = u; u = t;}  // Swap u and v.
																			       v = v - u;                       // Here v >= u.
																			            } while (v != 0);
																				     
																				       /* restore common factors of 2 */
																				         return u << shift;
}

int
generation(long long P, long long Q, int g) {
  int result = 0;

  while((g > 0) && (P < Q)) {
    g--;
    result++;
    P *= 2;
  }

  if((P < Q) || ((P > Q) && (generation(P-Q, Q, g) == -1))) {
    result = -1;
  }

  return result;
}

int
main() {
  int T;

  cin >> T;

  for(int i = 1; i <=T; i++) {
    long long P, Q;
    char c;

    cin >> P >> c >> Q;

    long long f = gcd(P, Q);

    P /= f;
    Q /= f;

    int g = generation(P, Q, 40);

    cout << "Case #" << i << ": ";
    if(g > 0) {
      cout << g << endl;
    } else {
      cout << "impossible" << endl;
    }
  }

  return 0;
}

