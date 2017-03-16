#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<stdlib.h>

#define gc getchar_unlocked()

using namespace std;

typedef unsigned long long int LL;

FILE *fin=fopen("in.txt","r");
FILE *fout=fopen("out.txt","w");

long long int in()
{
  char c;long long int t=0;
  int negative=1;
  c=gc;
  
  while((c<48||c>57)&&c!='-')c=gc;
  if(c=='-')
  {negative=-1;c=gc;}
  while(c>=48&&c<=57)
  {t=(t<<3)+(t<<1)+c-'0';c=gc;}
  return t*negative;
}

int compare(const void *a,const void *b)
{
  return (*(LL*)a-*(LL*)b);
}

int main()
{
  LL t,cases=0,n,i,l,ans,curr,j,k;
  char s[10000];
  
  fscanf(fin,"%llu",&t);
  
  while(t--)
  {
      fscanf(fin,"%s %llu",s,&n);
      
      cases++;
      ans=0;
      
      l=strlen(s);
           
      for(i=0;i+n-1<l;i++)
      {
	//curr=0;
	
	for(j=i+n-1;j<l;j++) //groups of length n
	{
	  curr=0;
	  for(k=i;k<=j;k++)
	  {
	    if(!(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u'))
	    {
	      //printf("%c ",s[k]);
	      curr++;
	    }
	    
	    else
	      curr=0;
	    
	    if(curr==n)
	    {
	      ans+=(l-j);
	      break;
	    }
	  }
	  
	  if(curr==n)
	    break;
	}
	//printf("\n");
      }
      
      fprintf(fout,"Case #%llu: %llu\n",cases,ans);
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
 
