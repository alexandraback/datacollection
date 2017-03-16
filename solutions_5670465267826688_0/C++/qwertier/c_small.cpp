#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int next[5]={0,0,3,4,2};
int mul(int a,int b){
  int tmp=a/abs(a)*b/abs(b);
  a=abs(a),b=abs(b);
  if(a==1 || b==1)return a*b*tmp;
  if(a==b)return -tmp;
  if(a==next[b])tmp*=-1;
  return tmp*(9-a-b);
}

char s[10010];
int t[10010],n,m,l;
int main(){
#ifdef QWERTIER
  freopen("c_small.in","r",stdin);
  freopen("c_small.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%d%d%s",&n,&m,s);
    l=0;
    REP(j,m)REP(i,n){
      if(s[i]=='i')
        t[l++]=2;
      else if(s[i]=='j')
        t[l++]=3;
      else
        t[l++]=4;
    }
    bool flagi=false,flagk=false;
    int cur=1;
    REP(i,l){
      cur=mul(cur,t[i]);
      if(cur==2)flagi=true;
      else if(flagi && cur==4)
        flagk=true;
    }
    if(flagk && cur==-1)puts("YES");
    else puts("NO");
  }
  return 0;
}
