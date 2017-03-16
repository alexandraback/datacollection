#include <stdio.h>
#include <string.h>

int d(int n)
{
	if ( n == 0 )
		return 1;
	if ( n == 1 )
		return 10;
	if ( n == 2 )
		return 100;
	if ( n == 3)
		return 1000;
	if ( n == 4 )
		return 10000;
}

int main()
{
	char a[1000];
	int A,B;
	int n;
	int temp;
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		int cont = 0;
		scanf("%d %d",&A,&B);
		for(int i=A;i<B;i++)
		{						
			temp = i;
			sprintf(a,"%d%d",i,i);
			int size = strlen(a)/2;
			for(int j=0;j<size-1;j++)
			{
				temp = temp - ((a[j]-'0') * d(size-1));
				temp*=10;
				temp = temp + (a[j+size] -'0');
				if ( i < temp && temp <= B ){
					//printf("%d %d\n",i,temp);
					cont++;
				}
			}
		}
		printf("Case #%d: %d\n",k,cont);		
	}	
	return 0;
}