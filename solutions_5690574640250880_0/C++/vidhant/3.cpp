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
	LL t,row,col,m,i,j;
	LL a,b,c,d;
	LL cases=0;
	char ch[10];
	
	fscanf(fin,"%lld",&t);
	
	while(t--)
	{
		fscanf(fin,"%lld %lld %lld",&row,&col,&m);
		
		cases++;
		
		fprintf(fout,"Case #%lld:\n",cases);
		
		//find the answer in pregenerated file for the combo
		
		FILE *gen=fopen("ans.txt","r");
		
		while(1)
		{
			fscanf(gen,"%lld %lld %lld %lld",&a,&b,&c,&d);
			
			//printf("read %lld %lld %lld %lld\n",a,b,c,d);
			
			if(a==row&&b==col&&c==m)	//matched
			{
				if(d==0)
				{
					fprintf(fout,"Impossible\n");
					for(i=0;i<a;i++)
					{
					
							fscanf(gen,"%s",ch);
							//fprintf(out,"%d",ch);
					
					
						//fprintf(fout,"\n");
					}
				}
				
				else
				{
					for(i=0;i<a;i++)
					{
						fscanf(gen,"%s",ch);
						fprintf(fout,"%s",ch);
						fprintf(fout,"\n");
					}
				}
				
				break;
			}
			
			else
			{
				for(i=0;i<a;i++)
				{
					
						fscanf(gen,"%s",ch);
						//fprintf(out,"%d",ch);
					
					
					//fprintf(fout,"\n");
				}
			}
			
		}
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}