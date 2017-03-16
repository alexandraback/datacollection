# include <math.h>
# include <stdlib.h>
# include <stdio.h>

#include <iostream>

using namespace std;

typedef struct p{ int x;int y;}point;

int compare(const void *a,const void *b){
    point x = *(point *)a;
    point y = *(point *)b;
    return (x.y - y.y);
    
 
}
 
int compare2 (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
} 
 
//qsort(a,n,sizeof(point),compare);

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
	
	
typedef struct node
{
	long long int state;
	long long int pointer;
	long long int neighbours[10];
	long long int colour;
	long long int c2;
}node;

int flag;

void visit_dfs(node** V,node u)
{
	long long int i;
	(*V)[u.state].colour = 1;
	for (i=0;i<u.pointer;i++)
	{
		if ( (*V)[u.neighbours[i]].colour == 0)
		{ 
			visit_dfs(V,(*V)[u.neighbours[i]]);
		}
		else
		{
				flag = 1;
		}
	}
	(*V)[u.state].colour = 2;
	(*V)[u.state].c2 = 1;
}


	
void dfs (node** V,long long int N)
{
	long long int i,k;
	for ( i =1;i<=N;i++)
	{
		(*V)[i].colour = 0;
		(*V)[i].c2 = 0;
	}
	for ( i = 1;i<=N;i++)
	{
		if ((*V)[i].c2 == 0)
		{
			for ( k  = 1; k<= N;k++)
			{
				(*V)[k].colour = 0;
			}
			visit_dfs(V,(*V)[i]);
		}
	}
}



int main()
{
    long long int T,i,j,k,N,M,f;
	node *V;
	
    FILE *f1;
 
    f1 = fopen("out.txt","w");
	
	
	V =  (node*)malloc(sizeof(node)*(1000+1)) ;
    scanf("%lld",&T);
    for ( i = 0; i < T;i++)
    {
		scanf("%lld",&N);
		flag = 0;
		for ( j = 1 ; j <= N ; j++)
		{
			scanf("%lld",&M);
			V[j].pointer = M;
			V[j].state = j;
			for ( k = 0;k<M;k++)
			{
				scanf("%lld",&f);
				V[j].neighbours[k] = f;
			}
			
		}
		
		dfs(&V,N);
		if ( flag)
		{
			printf("Case #%lld: Yes\n",i+1);
			fprintf(f1,"Case #%lld: Yes\n",i+1);
		}
		else
		{
			printf("Case #%lld: No\n",i+1);
			fprintf(f1,"Case #%lld: No\n",i+1);
		}
        
        
    }
   
    fclose(f1);
    return 0;
}

