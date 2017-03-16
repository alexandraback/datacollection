#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#define REP(I,A,B) for (int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for (int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define RLL(X) scanf("%I64d",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
long long a[21];
int main()
{
	 freopen("A-large.in","r",stdin);
	 freopen("A_ans.out","w",stdout);
	 int T;
	 scanf("%d",&T);
	 int ttx=0;
	 while(T>0)
	 {
	 	  tty++;
	      T--;
	      int i,j;
          long long n;
          scanf("%I64d",&n);
          if(n<10)
          {
               printf("Case #%d: %I64d\n",tty,n);
               continue;
          }
          long long s=10;
          /*
		    find the answer..
		    #include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#define REP(I,A,B) for (int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for (int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define RLL(X) scanf("%I64d",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
long long n;
long long ten[16]={0};
map <long long,int> ans;
void open()
{
  freopen("A.in","r",stdin);
  freopen("A_large.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}

int get_high(long long n)
{
  int i;
  while (n)
  {
    i=n%10;
    n/=10;
  }
  return i;
}
int get_dig(long long n)
{
  int i=0;
  while (n)
  {
    i++;
    n/=10;
  }
  return i;
}
long long rev(long long n)
{
  long long a=0;
  while (n)
  {
    a=a*10+n%10;
    n/=10;
  }
  return a;
}
long long dfs(long long n)
{
  if (n<=19)
    return n;
  int high=get_high(n),dig=get_dig(n);
  if (n==ten[dig-1]+1)
    return dfs(n-2)+2;
  long long ans=n;  
  if (n%10==0)
    return dfs(n-1)+1;
  REP(i,1,dig-1)
    if (rev(n-n%ten[i]+1)<n)
      ans=min(n%ten[i]-1+dfs(rev(n-n%ten[i]+1))+1,ans); 
  return ans;
}
int main()
{
  open();
  int _=0;
  RI(_);
  ten[0]=1;
  REP(i,1,16)
    ten[i]=ten[i-1]*10;
  REP(__,1,_)
  {
    printf("Case #%d: ",__);
    RI(n);
	printf("%I64d\n",dfs(n));
  }
  close();
  return 0;
}

		  */
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
          printf("Case #%d: %I64d\n",tty,s);
     }
     return 0;
}
