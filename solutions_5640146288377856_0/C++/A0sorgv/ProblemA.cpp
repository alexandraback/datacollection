#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cases, index_cases;
int R,C,W;
int a,b,ming;


void main()
{

freopen("A-small-attempt0.in" , "rt" , stdin ) ;
freopen("A-small-attempt0.out" , "wt" , stdout ) ;
//freopen("A-large.in" , "rt" , stdin ) ;
//freopen("A-large.out" , "wt" , stdout ) ;

cases = 0;
//read the number of test cases 
scanf("%d",&cases);
//printf("Cases = %d\n",cases);

//Loop through all the cases
for (index_cases=0 ; index_cases<cases; index_cases++)
{

	scanf("%d",&R);
	scanf("%d",&C);
	scanf("%d",&W);
	a = C/W;
	b= C%W;

	ming = (R* a )+W;
	if (b==0) ming--;
	printf("Case #%d: %d\n",index_cases+1,ming);
}
fclose(stdin) ;
fclose(stdout) ;

}