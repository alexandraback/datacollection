#include<stdio.h>
#include<stdlib.h>
long int ar[2000000];
long int rev(long int n)
{
   long int reverse=0;
   while (n != 0)
   {
      reverse=reverse*10;
      reverse=reverse+n%10;
      n=n/10;
   }  
   return(reverse);
}
long int digit(long int m,long int i)
{
     int k1=0,k2=0;
   while(m!= 0)
   {
      m=m/10;
      k1++;
   } 
   while(i!= 0)
   {
      i=i/10;
      k2++;
   }  
   if(k1==k2)
   return(0);
   else
   return(1);
}
int main()
{
    long int i,j,k,l,m,n,p,q,t,r;
    FILE *fi,*fo;
	fo=fopen("test.txt", "w+");
	fi=fopen("abc.txt","r");
	fscanf(fi,"%ld",&t);
	for(i=1;i<=20;i++)
	ar[i]=i;
	for(i=21;i<1000100;i++)
	{
                           m=rev(i);
                           if(m<i&&ar[m]<ar[i-1]&&digit(m,i)==0) 
                           ar[i]=ar[m]+1;
                           else
                           ar[i]=ar[i-1]+1;
    }
	for(q=0;q<t;q++)
	{
                    fscanf(fi,"%ld",&n);
                    fprintf(fo,"Case #%ld: %ld\n",q+1,ar[n]);
    }
    //system("pause");
    return(0);
}
