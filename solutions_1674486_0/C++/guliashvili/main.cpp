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


bool g[1010][1010];
int n;
bool tab[1010];
bool used[1010];
int bfs(int i)
{
  used[i]=1;

  FORE(j,1,n)
  {
    if(g[i][j]==1)
      {
        if(tab[j]==1)
          return 1;
        else
          tab[j]=1;
        if(bfs(j))
          return 1;
      }
  }
  return 0;
}




int func()
{
  memset(g,0,1010*1010);

  GI(n);
  FORE(i,1,n)
  {
    int t;
    GI(t);
    FOR(j,0,t)
    {
      int tmp;
      GI(tmp);
      g[i][tmp]=1;
    }
  }

  memset(used,0,1010);
  FORE(i,1,n)
  {
    if(used[i]==0)
      {

        memset(tab,0,1010);
        if(bfs(i))
          return 1;
      }
  }

  return 0;

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
    printf("Case #%d: ",T);
    if(func()==1)
      printf("Yes\n");
    else
      printf("No\n");



  }



  return 0;
}
