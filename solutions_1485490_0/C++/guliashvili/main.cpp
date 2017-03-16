#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>



#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define FO(i,s,n,p) for(int i=(s);i<(n);i+=p)
#define FOE(i,s,n,p) for(int i=(s);i<=(n);i+=p)
#define FOR(i,s,n) for(int i=(s);i<(n);i++)
#define FORE(i,s,n) for(int i=(s);i<=(n);i++)
#define FORD(i,s,n) for(int i=(s);i>(n);i--)
#define FORDE(i,s,n) for(int i=(s);i>=(n);i--)



#define GI(i) scanf("%d",&i)
#define GLL(i) scanf("%lld",&i)
#define GLLU(i) scanf("%llu",&i)
#define GW(s) scanf("%s",s)
#define GS(s) gets(s)

#define PUTI(i) printf("%d",i)
#define PUTS(s) printf("%s",s)
#define PUTC(c) putchar(c)

typedef long long ll ;
typedef unsigned long long llu;


#define ML(type,c) (type *)malloc(sizeof(type)*c)
#define CL(type,c) (type *)calloc(sizeof(type),c)



#define cmptype int
int tcmp(const cmptype*n1,const cmptype*n2)
{
  return *n1-*n2;
}
int cmp(const void * n1,const void * n2)
{
  return tcmp((cmptype*)n1,(cmptype*)n2);
}




int intcmp(const void * n1,const void * n2)
{
  return (*(int*)n1)-(*(int*)n2);
}

ll tab[110][110];
ll boxn[110],boxt[110];
ll toyn[110],toyt[110];

ll doit(int a,int b)
{
  if(a<0 || b<0)
    return 0;
  ll max=0;

  if(tab[a][b]==-1)
    {

   ll sbn=boxn[a],stn=toyn[b];

      //tryicki

      ll  mmax=0;

      if(boxt[a]==toyt[b])
        {
          mmax=MIN(boxn[a],toyn[b]);
          if(boxn[a]==toyn[b])
            {
              boxn[a]=toyn[b]=0;
              mmax+=doit(a-1,b-1);
            }
          else if(boxn[a]<toyn[b])
            {
              toyn[b]-=boxn[a];
              mmax+=doit(a-1,b);
            }
          else
            {
              boxn[a]-=toyn[b];
              mmax+=doit(a,b-1);
            }



          max=mmax;

        }
      ll t1=doit(a-1,b);
      if(t1>max)
        {
          max=t1;
          toyn[b]=stn;
          boxn[a]=sbn;
        }
      t1=doit(a,b-1);
      if(t1>max)
        {
          max=t1;
          toyn[b]=stn;
          boxn[a]=sbn;
        }





      tab[a][b]=max;

    }
  return tab[a][b];
}


ll func()
{
  memset(tab,-1,sizeof(ll)*110*110);

  int n,m;
  GI(n);
  GI(m);
  FORDE(i,n-1,0)
  {
    GLL(boxn[i]);
    GLL(boxt[i]);
  }

  FORDE(i,m-1,0)
  {
    GLL(toyn[i]);
    GLL(toyt[i]);
  }


  return doit(n-1,m-1);

}







#define contest
//#undef contest

int main()
{
#ifndef contest
  freopen("C:\\a","r",stdin);
#else
  freopen("C:\\a","r",stdin);
  freopen("C:\\b","w",stdout);
#endif
  int t;
  GI(t);
  FORE(T,1,t)
  {
    printf("Case #%d: %lld\n",T,func());

  }



  return 0;
}
