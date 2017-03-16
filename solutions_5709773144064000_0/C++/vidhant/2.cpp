#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>

#define gc getchar_unlocked()
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mod 1000000007
#define swap(a,b) ((b)=(a)^(b)^((a)=(b)))
#define INF 100000000000000000LL
#define fill(a,b,c) memset(a,0,sizeof(b)*(c));
#define pb push_back

using namespace std;

typedef long long int LL;

LL power(LL b,LL p)
{	LL a=1;	while(p) { if(p&1) {	a*=b;	a%=mod;	}	b*=b;	b%=mod;	p=p>>1;	}	return a%mod;	}
	

FILE *fin=fopen("in.txt","r");
FILE *fout=fopen("out.txt","w");

LL in()
{
  char c;LL t=0,negative=1;
  c=gc;
  
  while((c<48||c>57)&&c!='-')c=gc;
  if(c=='-')
  {negative=-1;c=gc;}
  while(c>=48&&c<=57)
  {t=(t<<3)+(t<<1)+c-'0';c=gc;}
  return t*negative;
}

int compare(const void *a,const void *b)	//qsort(arr,n,sizeof(LL),compare)
{
  return (*(LL*)a-*(LL*)b);
}

int main()
{
	LL t,cases=0;
	long double c,f,x,curr,prev,incr_curr,incr_prev;
	
	fscanf(fin,"%lld",&t);
	
	while(t--)
	{
		fscanf(fin,"%Lf %Lf %Lf",&c,&f,&x);
		
		cases++;
		
		incr_curr=incr_prev=2;
		
		curr=prev=x/2;
		
		if(x<=c)
			fprintf(fout,"Case #%lld: %.7Lf\n",cases,x/2);
		else
		{
			prev=x/2;
			
			while(1)
			{	
				incr_curr=incr_prev+f;
				
				curr=prev+(c-x)/incr_prev;
				curr+=x/incr_curr;
				
				//printf("%Lf\n",curr);
				
				if(curr>prev)
					break;
				
				incr_prev=incr_curr;
				prev=curr;

			}
			
			fprintf(fout,"Case #%lld: %.7Lf\n",cases,prev);
			
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}