#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

using namespace std;

struct tipo{
  string a,b;
  bool operator < (const struct tipo &t)const{return (a<t.a||(a==t.a&&b<t.b));};
};

int main()
{
  string a,b,c,d,act;
  map<struct tipo,int> listos;
  struct tipo temp;
  int T,n,t,max,i,j;
  scanf("%d",&T);
  for(t=1;t<=T;t++)
  {
    cin>>a>>b;
    d=a;
    max=0;
    n=a.size();
      for(i=1;i<n;i++)
      {
	
	a=d;
	
	do{
	  c=a;
	  act="";
	  for(j=n-i;j<n;j++)
	    act+=c[j];
	  c.erase(n-i);
	  act+=c;
	  if(act>=a&&act<=b&&act!=a)
	  {
	    temp.a=a;
	    temp.b=act;
	    if(listos[temp]==0)
	    {
	      listos[temp]=1;
	      temp.a=act;
	      temp.b=a;
	      listos[temp]=1;
	      max++;
	    }
	  }
	  for(j=n-1;j>=0;j--)
	  {
	    if(a[j]<'9')
	    {
	      a[j]+=1;
	      break;
	    }
	    else
	    {
	      a[j]='0';
	    }
	  }
	  
	}while(a<=b&&a[0]!='0');
      }
    printf("Case #%d: %d\n",t,max);
    listos.clear();
  }
  return 0;
}