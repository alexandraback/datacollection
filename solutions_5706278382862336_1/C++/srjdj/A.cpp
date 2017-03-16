#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef unsigned long long ull;

#define findmax(a,b) (a)>(b)?a:b
#define findmin(a,b) (a)<(b)?a:b

long long int gcd(long long int m,long long int n)
{
	if(m%n==0)
	return n;
	
	else
	return gcd(n,m%n);
	
}

int check(long long int p,long long int q)
{
	long long int r=p/q;
	if(q==1)
	return 1;
	if(r==1)
 	return check(p-q,q);
	else if(r>1)
	return 0;
	
	else
	{
		if(q%2==0)
		return check(p,q/2);
		
		else
		return 0;
	}
	
}

int main()
{
	FILE *in,*out;
	in=fopen("A-large.in","r");
	out=fopen("A-large.out","w");
	int t;
	//cin>>t;
	fscanf(in,"%d",&t);
	for(int z=1;z<=t;z++)
	{
		long long int p,q,impossible=0,count=0,mod,loop=0;
		fscanf(in,"%lld/%lld",&p,&q);
		if(p>=q)
		mod=gcd(p,q);
		else
		mod=gcd(q,p);
		p=p/mod; q=q/mod;
		while(p<q)
		{
			loop=1;
			if(q%2==0)
			{q=q/2;count++;}
			else
			{impossible=1;break;}	
		}		
		if(!impossible)
		{long long int r=p/q;
	
	if(!loop&&p-q!=0)
	count++;
	
		if(r==1&&check(p-q,q)==1)
		fprintf(out,"Case #%d: %lld\n",z,count);
		else
		fprintf(out,"Case #%d: impossible\n",z);
	
		}
		else
		fprintf(out,"Case #%d: impossible\n",z);
			
	}//end of while
	
	return 0;
}