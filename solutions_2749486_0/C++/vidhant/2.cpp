#include<stdio.h>
#include<map>
#include<string>
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
  int t,dx,dy,cx,cy,i,s,l,c=0,cases=0,f;
  
  fscanf(fin,"%d",&t);
  
  while(t--)
  {
    fscanf(fin,"%d %d",&dx,&dy);
    
    cases++;
    
    fprintf(fout,"Case #%d: ",cases);
    
    cx=0,cy=0;
    
    for(i=1;;i++)
    {
      if(cx!=dx)
      {
	if(i&1)
	{
	  fprintf(fout,"E");
	  cx+=i;
	}
	else
	{
	  fprintf(fout,"W");
	  cx-=i;
	}
      }
      if(cx==dx)
	break;
    }
  
    i++;
    c=1;
    
    if(dx==0)
      i=1;
    
    if(dy>0)
    {
      s=0,l=0,f=0;
      
      while((l+i)<dy)
      {
	l+=i;
	i++;
	f++;
      }
      
      for(c=1;c<=f;c++)
	fprintf(fout,"N");
      
      cy=l;c=1;
      
      for(;;i++)
      {
	if(cy!=dy)
	{
	    if(c&1)
	    {
	      fprintf(fout,"S");
	      cy-=i;
	    }
	    else
	    {
	      fprintf(fout,"N");
	      cy+=i;
	    }
	}
	if(cy==dy)
	  break;
	c++;
      }
    }
    
    else
    {
      s=0,l=0,f=0;
      
      while((l-i)>dy)
      {
	l-=i;
	i++;
	f++;
      }
      
      for(c=1;c<=f;c++)
	fprintf(fout,"S");
      
      c=1,cy=l;
      
      
      for(;;i++)
      {
	if(cy!=dy)
	{
	    if(c&1)
	    {
	      fprintf(fout,"N");
	      cy+=i;
	    }
	    else
	    {
	      fprintf(fout,"S");
	      cy-=i;
	    }
	}
	if(cy==dy)
	  break;
	c++;
      }
    }
    
    fprintf(fout,"\n");
  }
    
    
      
    
    
    
    
  
 
    
    
	
	
    
    
  
  
  
  
  
  
  
  
  
  
  return 0;
}
 
