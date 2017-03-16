#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int factorial(int n)
{
 int i=1,fact;
 while(i<=n)
 {
  fact*=i;
 }
 return fact;
}

int min(int x,int y)
{
 if(x<y)
  return x;
 else
  return y; 
} 


int main()
{
 int T,N,flag,i,j,k,l,m,res,tmp,scount[26],fcount[26],bcount[26],tcount[26],tempcount[26],fact;
 char A[101][1000];
 
 FILE *f=fopen("B-small-attempt0.txt","r");
 FILE *fp=fopen("Bsmall.txt","w");
 
 fscanf(f,"%d",&T);
 
 
 
 for(i=0;i<T;i++)
 {
  for(k=0;k<26;k++)
 {
  fcount[k]=0;
  scount[k]=0;
  bcount[k]=0;
  tcount[k]=0;
 }
 flag=0;
 res=0;
  fscanf(f,"%d",&N);
  
  for(j=0;j<N;j++)
    fscanf(f,"%s",A[j]);
  for(j=0;j<N;j++)
  {
   for(k=0;k<26;k++)
     tempcount[k]=0;
   tmp=A[j][0]-97;
   fcount[tmp]++;
   k=0;
   while(A[j][k]!='\0')
   {
    tmp=A[j][k]-97;
    tempcount[tmp]++;
    k++;
   } 
   tmp=A[j][k-1]-97;
   bcount[tmp]++;
   for(k=0;k<26;k++)
   {
    if(tempcount[k]>0)
     scount[k]++;
     tcount[k]+=tempcount[k];
   }
  }
  
 
 for(j=0;j<26;j++)
 {
  if((fcount[j]+bcount[j])<scount[j])
  {
   flag=1;
   res=0;
   goto end;
  }
 
 }
 for(j=0;j<N;j++)
 {
  k=1;
  while(A[j][k]!='\0')
  {
   if(A[j][k+1]!='\0')
   {
   tmp=A[j][k]-97;
   if((A[j][k]!=A[j][k-1]) && (A[j][k]!=A[j][k+1]) && (tcount[tmp]>1))
   {
    flag=1;
    res=0;
    goto end;
   }
   }
   k++;
  }
 }
  end:
  if(flag==1)
    fprintf(fp,"Case #%d: %d\n",i+1,res);  
  else
  {
   for(j=0;j<26;j++)
   {
    if(fcount[j]==bcount[j])
    {
      if(fcount[j]>1)
       res+=fcount[j]+bcount[j];
      else
       res+=fcount[j]; 
    }  
    else if((fcount[j]>0) && (bcount[j]==0))
      res--;   
    else if((fcount[j]!=0) && (bcount[j]!=0)) 
      res+=min(fcount[j],bcount[j]); 
   }
    if(res<0)
     res=0;
   fprintf(fp,"Case #%d: %d\n",i+1,res); 
  }
    
 }
 
 return 0;
}
