# include <math.h>
# include <stdlib.h>
# include <stdio.h>
double min ( double a ,double b)
{
     if ( a<=b) return a;
     return b;
 }
 
 long long int gcd (long long int a ,long long int b)
  {
	    long long int temp;
	   while ((a!=0) && (b!=0 )) 
	   {
	         
	         if (a >= b)
	         {   
	             temp = b;
	             b = a % b;
	             a = temp;             
	         }
	         else
	         {
	             temp = a;
	             a = b % a;
	             b = temp;
	         }     
	   }
	   if (a > 0 )
	   { return a;  
	   }
	   else {return b;} 
	  
	   
	      
	} 
 
 


int main()
{
    long long int T,i,j,A,B;
    double c_min;
    double p,q,k,result;

    FILE *f1;
   
    f1 = fopen("out.txt","w");
   
    scanf("%lld",&T);
    
    for ( i = 0; i < T;i++)
    {
		
		scanf("%lld",&A);
		scanf("%lld",&B);
		
		
		c_min = 3.0*B;
		p = 1.0;
		q = p * ( B+1 + A) ;
		//printf(" q == %lf \n",q);
		c_min = min (q,c_min);
		for (j = A-1; j >= 0 ;j--)
		{
			
			scanf("%lf",&k);
			//printf("Diavasa to k == %lf\n",k);
			p = p * k;
			//printf(" to p == %lf\n",p);
			q = p * ( B+1 -A + 2*j) + ( 1 - p)* ( 2*B + 2 - A +2*j);
			//printf(" q == %lf \n",q);
			c_min = min (q,c_min);
			
		}
		
		q = B + 2.0;
		c_min = min(q,c_min);
		result = c_min;	
		
       
        printf("Case #%lld: %lf\n",i+1,result);
        fprintf(f1,"Case #%lld: %lf\n",i+1,result);
        
        
    }
   
    fclose(f1);
    return 0;
}
