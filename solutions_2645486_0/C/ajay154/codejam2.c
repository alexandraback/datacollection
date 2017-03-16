// @AUTHOR ajay yadav//
#include<stdio.h>
#include<math.h>
inline void S(int *);
inline void S(int *a)
{
char c = 0;
while(c<33)
//c = fgetc_unlocked(stdin);
c = getc(stdin);
*a = 0;
while(c>33)
{
*a = *a*10 + c - '0';
//c = fgetc_unlocked(stdin);
c = getc(stdin);
}
}
#define max2(a,b) a>b?a:b
int val[20],e,r,n,max1;
void fun(int idx,int en,int gain)
{
    int i;
                   if(idx==n)
                   {


                             max1=max2(max1,gain);
                             return ;
                   }


                   for(i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         fun(idx+1,(en-i)+r,gain+val[idx]*i);
                                         else
                                         fun(idx+1,e,gain+val[idx]*i);
                   }

                   return ;
}
int main()
{
    int t,i,j;
 S(&t);
 for(i=1;i<=t;i++)
 {
     printf("Case #%d: ",i);
    S(&e);
    S(&r);
    S(&n);
    for(j=0;j<n;j++)
    {
        S(&val[j]);
    }
    max1=0;
    fun(0,e,0);
    printf("%d\n",max1);
 }
}
