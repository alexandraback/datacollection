#include<stdio.h>
#include"iostream"
using namespace std;
typedef long long ll;
struct node
{
  char sym;
  ll sig;
};
node mult (node a,node b)
{
  node result;
  result.sig=(a.sig)*(b.sig);
  if(a.sym=='1')
    result.sym=b.sym;
  else if(b.sym=='1')
    result.sym=a.sym;
  else if(a.sym==b.sym)
    {
      result.sym='1';
      result.sig*=-1;
    }
  else if(b.sym=='i'+(a.sym-'i'+1)%3)
      result.sym='i'+'j'+'k'-a.sym-b.sym;
  else
    { 
      result.sym='i'+'j'+'k'-a.sym-b.sym;
      result.sig*=-1;
    }
  return result;
}

int main()
{
  ll t,l,i,j,k;
  ll x,posf,posl,red;
  char str[10005],ch;
  node arr[40009],start,end,ans;
  scanf("%lld",&t);
  for(j=1;j<=t;j++)
    {
      scanf("%lld%lld",&l,&x);
      scanf("%s",str);
      for(i=0;str[i]!='\0';i++)
	{
	  arr[i].sym=str[i];
	  arr[i].sig=1;
	}
      red=4;
      if(x<red)
	red=x;
      start=(node){'1',1};
      for(i=0;i<red*l;i++)
	{
	  start=mult(start,arr[i%l]);
	  if(start.sym=='i'&&start.sig==1)
	    break;
	}
      if(i==red*l)
	posf=l*x;
      else
	posf = i;
      end=(node){'1',1};
      for(i=red*l-1;i>=0;i--)
	{
	  end=mult(arr[i%l],end);
	  if(end.sym=='k'&&end.sig==1)
	    break;
	}
      if(i==-1)
	posl=0;
      else
	posl=i-red*l+x*l;
      if(posf>=posl)
	{
	  printf("Case #%lld: NO\n",j);
	  continue;
	}
      start=(node){'1',1};
      for(i=0;i<l;i++)
	  start=mult(start,arr[i]);
      end=(node){'1',1};
      for(i=0;i<x%4;i++)
	end=mult(end,start);
      if(end.sym=='1'&&end.sig==-1)
	printf("Case #%lld: YES\n",j);
      else printf("Case #%lld: NO\n",j);
    }
  return 0;
}

