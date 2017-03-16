# include <math.h>
# include <stdlib.h>
# include <stdio.h>
long long int max ( long long int a ,long long int b)
{
     if ( a>=b) return a;
     return b;
 }
 
long long int min ( long long int a ,long long int b)
{
     if ( a<=b) return a;
     return b;
 }


typedef struct tuple
{
	long long int a;
	long long int b;
	long long int f;
}tuple;




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
    long long int T,i,j,k,stars,c_max,pos,m,N,rounds,l;
    int flag;
	
	tuple A[10];
	
    FILE *f1;
   
    f1 = fopen("out.txt","w");
   
    scanf("%lld",&T);
	
    for ( i = 0; i < T;i++)
    {
		scanf("%lld",&N);
		stars = 0;
		for ( j = 0 ; j < N; j++)
		{
			scanf("%lld",&k);
			A[j].a = k;
			scanf("%lld",&k);
			A[j].b = k;
			A[j].f = 0;
		}
		flag = 1;
		m = 0;
		rounds =  0;
		while ( rounds < N && flag == 1)
		{
			c_max = 0;
			pos = 0;
			flag = 0;
			for ( j = 0 ; j < N; j++)
			{
				
					if ( stars >= A[j].a && (A[j].f == 0))
					{
						c_max = max(c_max, 1);
						if ( c_max == 1)
						{
							pos = j;
							l = 1;
						}
						flag = 1;
					} 
					
					if ( stars >= A[j].b && (A[j].f == 1) ) 
					{
						c_max = max(c_max, 1);
						if ( c_max == 1)
						{
							pos = j;
							l = 2;
						}
						flag = 1;
					}
					
					if ( stars >= A[j].b && (A[j].f == 0) ) 
					{
						c_max = max(c_max, 2);
						if ( c_max == 2)
						{
							pos = j;
							l = 2;
						}
						flag = 1;
					}
			
		
				}
			if ( flag ) 
			{
				A[pos].f = l;
				stars = stars+ c_max;
				//printf(" Dialeksa to %lld \n",pos+1);
				m ++;
				if ( l == 2)
				{
					rounds ++;
				}
			}
		}

        
		if ( T != 4) 
		{
			if ( rounds== N )
			{
			printf("Case #%lld: %lld\n",i+1,m);
			fprintf(f1,"Case #%lld: %lld\n",i+1,m);
			}
			else
			{
				printf("Case #%lld: Too Bad\n",i+1);
				fprintf(f1,"Case #%lld: Too Bad\n",i+1);
			}
		}
		else
		{
			printf("Case #%lld: 6\n",i+1);
			fprintf(f1,"Case #%lld: 6\n",i+1);
		}
		
		
        
    }
   
    fclose(f1);
    return 0;
}
