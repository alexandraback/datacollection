#include <stdio.h>
#include <string.h>
#include <math.h>

int d(int n)
{
	return pow(10,n);
}

int fin = 0;
int repe[100];

int existe(int n)
{
	for(int i=0;i<fin;i++)
		if ( repe[i] == n )
			return 1;
	return 0;
}

void mete(int n)
{
	repe[fin++] = n;
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
			fin = 0;
			temp = i;
			sprintf(a,"%d%d",i,i);
			int size = strlen(a)/2;
			for(int j=0;j<size-1;j++)
			{
				temp = temp - ((a[j]-'0') * d(size-1));
				temp*=10;
				temp = temp + (a[j+size] -'0');
				if ( i < temp && temp <= B && !existe(temp)){
					mete(temp);
					//printf("%d %d\n",i,temp);
					cont++;
				}
			}
		}
		printf("Case #%d: %d\n",k,cont);		
	}	
	return 0;
}