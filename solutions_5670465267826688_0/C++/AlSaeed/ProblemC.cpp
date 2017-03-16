#include <cstdio>
char inp[10000];
int L;
struct N
{
  int s;
  char l;
};
typedef struct N N;

N mul(N a,N b)
{
  N r;
  if( a.l == b.l )
    r.l='1';
  else if( a.l == '1')
    r.l=b.l;
  else if( b.l == '1')
    r.l=a.l;
  else if( a.l != 'i' && b.l !='i')
    r.l='i';
  else if( a.l != 'j' && b.l !='j')
    r.l='j';
  else 
    r.l='k';
  r.s=1;
  if(a.l == b.l && a.l != '1')
    r.s=-1;
  else if( a.l == 'j' && b.l == 'i')
    r.s =-1;
  else if( a.l == 'k' && b.l == 'j')
    r.s =-1;
  else if( a.l == 'i' && b.l == 'k')
    r.s =-1;
  r.s *= a.s * b.s;
  return r;
}

void read()
{
  int l,x;
  char g;
  scanf("%d %d%c",&l,&x,&g);
  for(int i=0;i<l;i++)
    scanf("%c",&inp[i]);
  for(int j=1;j<x;j++)
    for(int i=0;i<l;i++)
      inp[i+j*l]=inp[i];
  L=l*x;
}

bool mulsToMinOne()
{
  N r;
  r.l='1';
  r.s=1;
  for(int i=0;i<L;i++)
    {
      N t;
      t.s=1;
      t.l = inp[i];
      r = mul(r,t);
    }
  return r.s==-1 && r.l=='1';
}

int findIIndx()
{
  N r;
  r.l='1';
  r.s=1;
  for(int i=0;i<L;i++)
    {
      N t;
      t.s=1;
      t.l = inp[i];
      r = mul(r,t);
      if(r.s==1 && r.l=='i')
	return i;
    }
  return L;
}
int findKIndx()
{
  N r;
  r.l='1';
  r.s=1;
  for(int i=L-1;i>=0;i--)
    {
      N t;
      t.s=1;
      t.l = inp[i];
      r = mul(t,r);
      if(r.s==1 && r.l=='k')
	return i;
    }
  return -1;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int t=1;t<=n;t++)
    {
      bool rst;
      read();
      int iIndx = findIIndx();
      int kIndx = findKIndx();
      if(mulsToMinOne() && iIndx < kIndx)
	rst=true;
      else
	rst=false;
      printf("Case #%d: %s\n",t,rst?"YES":"NO");     
    }
  return 0;
}
