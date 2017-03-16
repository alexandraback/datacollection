#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int n;
char s[1010];
int main(){
#ifdef QWERTIER
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%d%s",&n,&s);
    int ans=0,cnt=0;
    REP(i,n+1)if(s[i]-'0'){
      if(cnt<i){
        ans+=i-cnt;
        cnt=i;
      }
      cnt+=s[i]-'0';
    }
    printf("%d\n",ans);
  }
  return 0;
}
