#include<stdio.h>
#include<stdlib.h>

int main()
{
 long long int T,i,j,k,P,Q,tmp,count,counter;
 char str[100];
 double res;
 
 FILE *f=fopen("A-large.txt","r");
 FILE *fp=fopen("Alarge.txt","w");
 
 fscanf(f,"%lld",&T);
 
 for(i=0;i<T;i++)
 {
  count=0;
  counter=0;
  fscanf(f,"%s",str);
  j=0;
  P=0;
  Q=0;
  while(str[j]!='/')
  {
   tmp=str[j]-48;
   P=P*10;
   P+=tmp;
   j++;
  }
  j++;
  while(str[j]!='\0')
  {
   tmp=str[j]-48;
   Q*=10;
   Q+=tmp;
   j++;
  }
  res=(double)P/(double)Q;
  tmp=(long long int)res;
  while((res-tmp)!=0)
  {
   res=res*2;
   tmp=(long long int)res;
   if(res<1)
     counter++;
   count++;  
   if(count>40)
    break;
  }
  if(count<=40)
     fprintf(fp,"Case #%lld: %lld\n",i+1,counter+1);
  else
     fprintf(fp,"Case #%lld: impossible\n",i+1);   
 }
 
 return 0;
}
