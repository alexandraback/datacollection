#include <cstdio>
char inp[40000];
long X,TotalLength;
int l,L;
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
  char g;
  scanf("%d %ld%c",&l,&X,&g);
  for(int i=0;i<l;i++)
    scanf("%c",&inp[i]);
  for(int j=1;j<4;j++)
    for(int i=0;i<l;i++)
      inp[j*l+i]=inp[i];
  L=4*l;
  TotalLength=X*l;
}

bool mulsToMinOne()
{
  N r ;
  r.s=1;r.l='1';
  for(int i=0;i<l;i++)
    {
      N t;t.l=inp[i];t.s=1;
      r=mul(r,t);
    }
  int res = X%4;
  N a; a.l='1';a.s=1;
  for(int i=0;i<res;i++)
    a = mul(a,r);
  return a.l=='1' && a.s==-1;
}

long findIIndx()
{
  N r;r.l='1';r.s=1;
  for(int i=0;i<L;i++)
    {
      N t; t.l=inp[i];t.s=1;
      r=mul(r,t);
      if(r.l=='i' && r.s==1)
	return (long)i;
    }
  return TotalLength;
}
long findKIndx()
{
  N r;r.l='1';r.s=1;
  for(int i=L-1;i>=0;i--)
    {
      N t; t.l=inp[i];t.s=1;
      r=mul(t,r);
      if(r.l=='k' && r.s==1)
	return TotalLength-L+i;
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
      long iIndx = findIIndx();
      long kIndx = findKIndx();
      if(mulsToMinOne() && iIndx < kIndx)
	rst=true;
      else
	rst=false;
      printf("Case #%d: %s\n",t,rst?"YES":"NO");     
    }
  return 0;
}
