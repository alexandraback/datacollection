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
const int MAXL=10005;
int l;
long long x;
char pre[MAXL]={0};
int pref[MAXL]={0};
int suff[MAXL]={0};
char suf[MAXL]={0};
char op[MAXL]={0};
char tot;
int totf;
void open()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
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
void init()
{
  RI(l);
  cin >> x;
  MS(pre,0);
  MS(suf,0);
  MS(pref,0);
  MS(suff,0);
  RS(op+1);
  pre[0]='1';
  int f=1;
  REP(i,1,l)
  {
    pre[i]=calc(pre[i-1],op[i],f);
    pref[i]=f;
  }
  suf[l+1]='1';
  f=1;
  REPD(i,l,1)
  {
    suf[i]=calc(op[i],suf[i+1],f);
    suff[i]=f;
  }
  //一次 
  long long k=x;
  char tmp=pre[l];
  int tmpf=pref[l];
  tot='1';
  totf=1;
  while (k)
  {
    if (k&1)
    {
	  totf*=tmpf;
	  tot=calc(tot,tmp,totf);
	}
	tmpf*=tmpf;
	tmp=calc(tmp,tmp,tmpf);
    k>>=1;
  }
}
void work()
{
  if (tot=='1' && totf==-1)
  {
    char tmp='1';
	int f=1;
	char a='1';
	int af=1;
	const long long MAXdd=1LL*l*x;
	long long ii=MAXdd,kk=0;
	REP(i,0,x-1)
	{
	  //已然一个周期 
	  if (i && tmp=='1' && f==1)
	    break;
	  REP(j,1,l)
	  {
	  	af=pref[j]*f;
	    a=calc(tmp,pre[j],af);
	    if (a=='i' && af==1)
	    {
		  ii=1LL*l*i+j;
		  break;
		}
	  }
	  if (ii!=MAXdd)
	    break;
	  f=af;
	  tmp=a;
	}
	//  suf * tmp
	tmp='1';
	f=1;
	a='1';
	af=1;
	REP(i,0,x-1)
	{
	  if (i && tmp=='1' && f==1)
	    break;
	  REPD(j,l,1)
	  {
	    af=suff[j]*f;
	    a=calc(suf[j],tmp,af);
	    if (a=='k' && af==1)
	    {
		  kk=1LL*l*(x-i-1)+j;
		  break;
		}
	  }
	  if (kk!=0)
	    break;
	  f=af;
	  tmp=a;
	}
	if (ii>=kk)
	  printf("NO\n");
	else 
	  printf("YES\n");
  }
  else 
    printf("NO\n");
}
int main()
{
  open();
  int _=0;
  RI(_);
  REP(__,1,_)
  {
    printf("Case #%d: ",__);
    init();
    work();
  }
  close();
  return 0;
}

