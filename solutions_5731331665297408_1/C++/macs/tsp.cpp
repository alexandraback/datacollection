#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <numeric>
using namespace std;
#define p(x) cerr<<#x<<":"<<x<<"\n"
#define lim 51
int cs,c,n,m,i,x,y,s,ss,j;
string mn,str;
int P[lim],M[lim][lim],S[lim],B[lim],V[lim];
char A[lim][10];
pair <string,int> R[lim];
void dfs(int x,int ind)
{
  int i;
  if(ind<=ss)
    dfs(S[ind],ind+1);
  V[x]=1;
  for(i=0;i<n;i++)
    if(M[x][i] && !V[i])
      dfs(i,1000000);
}
void greedy(int x)
{
  int z,i,j,k;
  B[x]=1;
  S[s++]=x;
  mn+=A[x];
  if(mn.size()==5*n)
    return;
  z=s-1;
  while(z>0)
  {
    ss=z-1;
    memcpy(V,B,sizeof B);
    dfs(S[0],0);
    if(accumulate(V,V+n,0)==n)
      z--;
    else
      break;
  }
  //printf("%d %d\n",s,z);
  k=-1;
  for(i=s-1;i>=z;i--)
    for(j=0;j<n;j++)
      if(M[S[i]][j] && !B[j])
        if(k==-1 || strcmp(A[j],A[k])<0)
          k=j;
  greedy(k);
  //z++;
}
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    if(c==35)
      p(c);
    scanf("%d%d",&n,&m);
    j=0;
    for(i=0;i<n;i++)
    {
      scanf("%s",A[i]);
      if(strcmp(A[i],A[j])<0)
        j=i;
      //R[i].f=A[i];
      //R[i].s=i;
      P[i]=i;
    }
    //sort(R,R+n);
    memset(M,0,sizeof M);
    memset(B,0,sizeof B);
    while(m--)
    {
      scanf("%d%d",&x,&y);
      x--;
      y--;
      M[x][y]=M[y][x]=1;
    }
    s=0;
    mn="";
    greedy(j);//R[0].s);
    printf("Case #%d: %s\n",c,mn.c_str());
  }
	return 0;
}
