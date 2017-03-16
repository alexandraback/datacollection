#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anumber[100],bnumber[100],number[100];
int adigit,bdigit,ndigit;

void printA()
{
	int i;
	for(i=0;i<adigit;i++)
	printf("%d ",anumber[i]);
	
	printf("\n");
}

void next ()
{
	int mid=(ndigit-1)/2,i;
	while(number[mid]==9 && mid>-1)
	{
		number[mid]=0;
		number[ndigit-1-mid]=0;
		mid--;
	}
	if(mid!=-1)
	{
		number[mid]++;
		if(mid!=ndigit-1-mid)
		number[ndigit-1-mid]++;
		return;
	}
	
	ndigit++;
	
	for(i=0;i<ndigit;i++)
	{
		number[i]=0;
	}
	number[0]=1;
	number[ndigit-1]=1;
}

void printP(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[99-n+i+1]);
	
	printf("\n");
}

int palindromo(int a[],int n)
{
	int i;
	for(i=0;i<n/2;i++)
	{
		if(a[99-i]!=a[99-n+1+i])
		return 0;
	}
	return 1;
}

void printN()
{
	int i;
	for(i=0;i<ndigit;i++)
	printf("%d ",number[i]);
	
	printf("\n");
}

void printB()
{
	int i;
	for(i=0;i<bdigit;i++)
	printf("%d ",bnumber[i]);
	
	printf("\n");
}

int square ()
{
	int i,j;
	int product[100];
	int pdigit;
	for(i=0;i<100;i++)
	{
		product[i]=0;
	}
	for(i=0;i<ndigit;i++)
	{
		for(j=0;j<ndigit;j++)
		{
			int num=number[ndigit-i-1]*number[ndigit-j-1],x;
			product[99-i-j]+=num;
			x=99-i-j;
			while(product[x]>=10)
			{
				product[x-1]+=product[x]/10;
				product[x]=product[x]%10;
				x--;
			}
		}
	}
	for(i=0;product[i]==0;i++);
	pdigit=99-i+1;
	
	/*printN();
	printP(product,pdigit);
	printf(" %d ",pdigit);*/
	if(pdigit<adigit)
	return 0;
	
	if(pdigit==adigit)
	{
		for(i=0;i<adigit;i++)
		{
			if(anumber[i]>product[99-pdigit+i+1])
			return 0;
			if(anumber[i]<product[99-pdigit+i+1])
			i=pdigit;
		}
	}
	
	
	
	if(pdigit>bdigit)
	return 2;
	
	/*printf("secondo\n");*/
	
	if(pdigit==bdigit)
	{
		for(i=0;i<pdigit;i++)
		{
			if(bnumber[i]<product[99-pdigit+i+1])
			return 2;
			if(bnumber[i]>product[99-pdigit+i+1])
			i=pdigit;
		}
	}
	
	/*printf("terzo\n");*/
	if(palindromo(product,pdigit))
	{
	/*printf("SI\n");*/
	return 1;
	
	}
	
	return 3;
}


void printCase(int i)
{
	printf("Case #%d: ",i+1);
}

int main()
{
	int cases,k;
	char c;
	scanf("%d",&cases);
	scanf("%c",&c);
	for(k=0;k<cases;k++)
	{
		
		int i,aux,ans=0;
		adigit=0;
		bdigit=0;
		ndigit=0;
		
		scanf("%c",&c);
		do
		{
			anumber[adigit++]=c-48;
			scanf("%c",&c);
		}while(c!=' ');
		
		scanf("%c",&c);
		do
		{
			bnumber[bdigit++]=c-48;
			scanf("%c",&c);
		}while(c!='\n');
		
		
		ndigit=(adigit+1)/2;
		
		for(i=0;i<ndigit;i++)
		{
			number[i]=0;
		}
		number[0]=1;
		number[ndigit-1]=1;
		
		do
		{
			aux=square();
			next();
			if(aux==1)
			ans++;
			/*printf("ESITO: %d\n",aux);*/
		} while(aux!=2);
		
		printCase(k);
		printf("%d\n",ans);
	}
	return 0;
}
