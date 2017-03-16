#include<stdio.h>      
#include<stdlib.h>      
#include<math.h>  
#include <gmp.h>
//use of gmplib   http://gmplib.org/


int main() { 
	
	
	mpz_t r, t, r1, r2, r3; 
	
	int T,i; 
	scanf("%d",&T);
	//unsigned long long r,t;
	for (i=1; i<=T; i++)
	{
		gmp_scanf ("%Zd", r);
		gmp_scanf ("%Zd", t);
		
		mpz_init (r1); 
		mpz_init (r2); 
		mpz_init (r3); 
	
		mpz_mul_si(r1,r,2L);
		
		mpz_sub_ui(r1,r1,1L);
		
		mpz_mul_si(r1,r1,-1L);

		mpz_mul(r2, r1,r1);
		
		mpz_mul_si(r3,t,8L);
		
		mpz_add(r2,r2,r3);

		mpz_sqrt(r2,r2);
		
		mpz_add(r1,r1,r2);
		
		unsigned long z=mpz_fdiv_q_ui(r3,r1,4L);

		
		

		gmp_printf("Case #%d: %Zd\n",i,r3);
	}
	return 0;
}