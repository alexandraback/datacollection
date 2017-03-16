#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define lowbit(x)(((x)&(-x)))
using namespace std;
struct node
{
      int a,b; 			 
}p[1500000];
int num[25],rcd[1500000];
int L[1500000],R[1500000];
bool cmp(node p1,node p2)
{
      if(p1.a!=p2.a)return p1.a<p2.a;
			return p1.b<p2.b; 		 
}
void out(int x)
{
 		  bool f=false;
 		  for(int i=1;x!=0;x>>=1,i++) 
 		  if(x%2)
 		  {
			   if(f)printf(" ");f=true;
				 printf("%d",num[i]); 			 
      }
 			puts("");
}
int main()
{
     // freopen("a.in","r",stdin);
      //freopen("a.out","w",stdout);
      int T,n;
      scanf("%d",&T);
      n=1;
      for(int i=0;i<20;i++)
      {
			    rcd[n]=i+1;
			    n*=2;
      }
      for(int cas=1;cas<=T;cas++)
      {
        scanf("%d",&n);
        printf("Case #%d:\n",cas);
        memset(L,0,sizeof(L));
        for(int i=1;i<=n;i++)scanf("%d",&num[i]);
        int t=1<<n;
        p[0].a=0;
        bool flag=false;
				for(int i=1;i<t;i++)
				{
				    p[i].b=i;
						p[i].a=p[i-lowbit(i)].a+num[rcd[lowbit(i)]] ;			
						if(L[p[i].a]!=0)
						{
						     flag=true;
				        out(L[p[i].a]);out(p[i].b);								
				        break;
					  }	
					  L[p[i].a]=i;
			  }
			  
			  
			 /* sort(p+1,p+t,cmp);
			  bool flag=false;
			  
			  for(int i=2;i<t;i++)
			  if(p[i].a==p[i-1].a)
			  {
				    flag=true;
				    out(p[i].b);out(p[i-1].b);
						break;												
			  }*/
			  if(!flag)puts("Impossible");
		  }


      return 0;
}
