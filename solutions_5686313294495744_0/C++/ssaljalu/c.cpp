#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

#define N 1000
#define M 2001

int T,TT;
int n;
char s1[21],s2[21];
int cnt1,cnt2;
map<string,int> m1,m2;
int g[M+1][M+1];
int q[M+1],v[M+1],chk[M+1],hd,tl;
int ans;

int bfs(){
  int i;
  hd=tl=0;
  while(hd<=tl){
    for(i=1;i<=M;i++){
      if(g[q[hd]][i] && chk[i]!=ans){
        tl++;
        q[tl]=i;
        v[tl]=hd;
        chk[i]=ans;
        if(i==M)return 1;
      }
    }
    hd++;
  }
  return 0;
}

int main() {
  int i;
  scanf("%d",&TT);
  for(T=1;T<=TT;T++){
    m1.clear();
    m2.clear();
    cnt1=1;
    cnt2=N+1;
    memset(g,0,sizeof(g));
    memset(chk,-1,sizeof(chk));
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s%s",s1,s2);
      if(m1.find(s1)==m1.end())
        m1[s1]=cnt1++;
      if(m2.find(s2)==m2.end())
        m2[s2]=cnt2++;
      g[m1[s1]][m2[s2]]=1;
    }
    for(i=1;i<cnt1;i++)g[0][i]=1;
    for(i=N+1;i<cnt2;i++)g[i][M]=1;
    for(ans=0;bfs();ans++){
      while(tl){
        g[q[v[tl]]][q[tl]]=0;
        g[q[tl]][q[v[tl]]]=1;
        tl=v[tl];
      }
    }
    for(i=1;i<cnt1;i++)ans+=g[0][i];
    for(i=N+1;i<cnt2;i++)ans+=g[i][M];
    ans=n-ans;
    printf("Case #%d: %d\n",T,ans);
  }
  return 0;
}
