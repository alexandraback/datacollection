#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[21];
int main()
{
	 freopen("A-large.in","r",stdin);
	 freopen("A-large.out","w",stdout);
	 int T;
	 scanf("%d",&T);
	 int ttx=0;
	 while(T>0)
	 {
	 	  ttx++;
	      T--;
	      int i,j;
          long long n;
          scanf("%I64d",&n);
          if(n<10)
          {
               printf("Case #%d: %I64d\n",ttx,n);
               continue;
          }
          long long s=10;
          if(n%2==0)
          {
               n--;
               s++;
          }
          long long t=n;
          int p=0;
          long long ttt=1;
          while(t!=0)
          {
          	   ttt=ttt*(long long)10;
               p++;
               a[p]=t%(long long)10;
               t=t/(long long)10;
          }
          ttt=ttt/(long long)10;
          for(i=1;i<=p/2;i++)
          {
               long long txt=a[i];
               a[i]=a[p+1-i];
               a[p+1-i]=txt;
          }
          int pp=2;
          long long t1=10,t2=9,t3=1;
          t=10;
          int ss=0;
          while(pp<p)
          {
     	       long long tx=t1+t2;
     	       s+=tx-t;
     	       s++;
     	       t=t*(long long)10;
     	       tx=(t1/t3)*t2+(long long)1;
     	       s+=t-tx;
     	       pp++;
     	       t1=t1*(long long)10;
     	       ss++;
     	       if(ss%2==1)
     	            t1=t1;
     	       else
     	       {
     	            t3=t3*(long long)10;
     	            t2=t2*(long long)10+(long long)9;
     	       }
          }
          long long ex=1;
          long long te=0;
          long long ansx=(long long)10000000*(long long)10000000;
          ansx=min(ansx,n-t);
          for(i=1;i<=p/2;i++)
          {
               long long sx=0;
               te=te+a[i]*ex;
               long long sm=0;
               for(j=i+1;j<=p;j++)
                    sm=sm*(long long)10+a[j];
               if(sm!=0)
               {
                    sx+=te;
                    sx++;
                    sx+=sm-(long long)1;
               }
               else
               {
                    te--;
                    for(j=i+1;j<=p;j++)
                         sm=sm*(long long)10+a[j];
                    sx+=te;
                    sx++;
                    sx+=(ttt/ex)-(long long)1;
               }
               if(a[i]!=0)
                    ansx=min(ansx,sx);
               ex=ex*(long long)10;
          }
          s+=ansx;
          printf("Case #%d: %I64d\n",ttx,s);
     }
     return 0;
}
