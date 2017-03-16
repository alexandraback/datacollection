
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
#define RS(X) scanf("%s",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy((X),(Y),sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
void open()
{
  freopen("D.in","r",stdin);
  freopen("D.out","w",stdout);
}
void close()
{
  fclose(stdin);
  fclose(stdout);
}
int x,n,m;
//开始没有判断 x>6 QAQ large还是不会啊 
void find_in_table()
{
  //打表可得。。。 
  if ((n * m) % x) 
    printf("RICHARD\n"); 
  else
  {
	if (x <= 2) 
	  printf("GABRIEL\n");
	else
	{
	  if (n > m) 
	    swap(n, m);
	  if (x == 3)
	  {
		if (n == 1) 
		  printf("RICHARD\n");
		else 
		  printf("GABRIEL\n");
	  }
	  if (x == 4)
	  {
		if (n <= 2) 
		  printf("RICHARD\n");
		else 
		  printf("GABRIEL\n");
	  }
	  if (x == 5)
	  {
		if (n <= 3) 
		  printf("RICHARD\n");
		else 
		  printf("GABRIEL\n");
	  }
	  if (x == 6)
	  {
		if (n <= 4)
		  printf("RICHARD\n");
		else
		  printf("GABRIEL\n");
	  }
	  if (x > 6) //好像绝对就是这个 
	    printf("GABRIEL\n");
	}
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
	RI(x);
    RI(n);
    RI(m);
    find_in_table();
	
  }
  close();
  return 0;
}

