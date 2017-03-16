#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#define REP(I,A,B) for(int I=A,END=B;I<=END;I++)
#define REPD(I,A,B) for(int I=A,END=B;I>=END;I--)
#define RI(X) scanf("%d",&X)
#define RS(X) scanf("%s",X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy((X),(Y),sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
/*
*/
const int MAXL=10505;
char op[MAXL]={0};
int x,l;
void open()
{
  freopen("C.in","r",stdin);
  freopen("C_BF.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
void init()
{
  RS(op+1);
  REP(i,1,x)
    REP(j,1,l)
      op[(i-1)*l+j]=op[j];
}
inline char calc(char a,char b,int &f)
{
  if (a=='1')
    return b;
  if (b=='1')
    return a;
  if (a==b)
  {
  	f*=-1;
    return '1';
  }
  if (a=='i')
  {
    if (b=='j')
      return 'k';
    else 
    {
      f*=-1;
      return 'j';
    }
  }
  else if (a=='j')
  {
    if (b=='i')
    {
	  f*=-1;
	  return 'k';
	}
	else
	  return 'i';
  }
  else if (a=='k')
  {
    if (b=='i')
      return 'j';
    else
    {
	  f*=-1;
	  return 'i';
	}
  }
}
void work()
{
  l*=x;
  int ii=l+1,kk=0;
  char tmp='1';
  int f=1;
  REP(i,1,l)
  {
    tmp=calc(tmp,op[i],f);
	if (tmp=='i' && f==1)
    {
	  ii=i;
      break;
	}
  }
  tmp='1',f=1;
  REPD(i,l,1)
  {
    tmp=calc(op[i],tmp,f);
    if (tmp=='k' && f==1)
    {
	  kk=i;
	  break;
	}
  }
  if (ii>=kk)
  {
    printf("NO\n");
    return ;
  }
  tmp='1',f=1;
  REP(i,1,l)
  {
    tmp=calc(tmp,op[i],f);
  }
  if (tmp=='1' && f==-1)
  {
    printf("YES\n");
  }
  else 
  {
    printf("NO\n");
  }
}
int main()
{
  open();
  int _=0;
  RI(_);
  REP(__,1,_)
  {
  	printf("Case #%d: ",__);
    RI(l);
    RI(x);
    init();
    work();
  }
  close();
  return 0;
}

