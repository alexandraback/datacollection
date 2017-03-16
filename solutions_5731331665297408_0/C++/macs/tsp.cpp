#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 51
int cs,c,n,m,i,x,y,s;
string mn,str;
int P[lim],M[lim][lim],S[lim];
char A[lim][10];
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
      scanf("%s",A[i]);
      P[i]=i;
    }
    memset(M,0,sizeof M);
    while(m--)
    {
      scanf("%d%d",&x,&y);
      x--;
      y--;
      M[x][y]=M[y][x]=1;
    }
    mn="";
    while(1)
    {
      s=0;
      S[s++]=P[0];
      for(i=1;i<n;i++)
      {
        while(s>0 && !M[S[s-1]][P[i]])
          s--;
        if(s==0)
          break;
        S[s++]=P[i];
      }
      if(i==n)
      {
        str="";
        for(i=0;i<n;i++)
          str+=A[P[i]];
        if(mn=="" || str<mn)
          mn=str;
      }
      if(!next_permutation(P,P+n))
        break;
    }
    printf("Case #%d: %s\n",c,mn.c_str());
  }
	return 0;
}
