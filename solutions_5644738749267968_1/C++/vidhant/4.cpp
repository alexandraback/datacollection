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
	LL t,n,ans1,ans2,i,pos,idx,j,cases=0;
	long double temp;
	
	fscanf(fin,"%lld",&t);
	
	while(t--)
	{
		fscanf(fin,"%lld",&n);
		
		cases++;
		
		vector<long double> w1,w2;
		bool *done1=new bool[n+1];
		bool *done2=new bool[n+1];
		
		memset(done1,0,sizeof(bool)*(n+1));
		memset(done2,0,sizeof(bool)*(n+1));
		
		for(i=0;i<n;i++)
		{
			fscanf(fin,"%Lf",&temp);
			w1.pb(temp);
		}
		
		for(i=0;i<n;i++)
		{
			fscanf(fin,"%Lf",&temp);
			w2.pb(temp);
		}
		
		ans1=ans2=0;
		
		sort(w1.begin(),w1.end());
		sort(w2.begin(),w2.end());
		
		/*
		
		for(i=0;i<n;i++)
			printf("%Lf ",w1[i]);
		
		printf("\n");
		
		for(i=0;i<n;i++)
			printf("%Lf ",w2[i]);
		
		printf("\n");
		
		*/
		j=0;
		
		for(i=0;i<n;i++)
		{
			for(;j<n;j++)
			{
				if(w2[j]>=w1[i]&&done2[j]==false)
				{
					done2[j]=true;
					ans2++;
					break;
				}
			}
		}
		
		ans2=n-ans2;
		
			/*
		for(i=n-1;i>=0;i--)
		{
			done1[i]=true;
			
			//find the immediately greater one
			
			pos=-1;	//stores position of smallest unused
			idx=-1;
			
			for(j=0;j<n;j++)
			{
				if(done2[j]==false&&pos==-1)
					pos=j;
				
				if(w2[j]>=w1[i]&&done2[j]!=true)
				{
					idx=j;
					break;
				}
			}
			
			if(idx==-1)
			{
				ans2++;
				done2[pos]=true;
				//printf("n played %Lf and k played %Lf\n",w1[i],w2[pos]);
			}
			else
			{
				done2[idx]=true;
				//printf("n played %Lf and k played %Lf\n",w1[i],w2[idx]);
			}
				
		}
		*/
		memset(done1,0,sizeof(bool)*(n+1));
		memset(done2,0,sizeof(bool)*(n+1));
		
		for(i=0;i<n;i++)
		{
			
			
			idx=-1;		//pick his smallest
			
			for(j=0;j<n;j++)
				if(done2[j]==false)
				{
					idx=j;
					break;
				}
				
			if(w1[i]<w2[idx])	//waste his largest
			{
				done1[i]=true;
				
				for(j=n-1;j>=0;j--)
					if(done2[j]==false)
					{
						idx=j;
						break;
					}
					
				done2[idx]=true;
			}
			else
			{
				done1[i]=true;
				done2[idx]=true;
				
				ans1++;
			}
			
		}
		
		fprintf(fout,"Case #%lld: %lld %lld\n",cases,ans1,ans2);
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}