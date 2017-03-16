#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int K,C,S;
int main(){
#ifdef QWERTIER
  freopen("d.in.txt","r",stdin);
  freopen("d.out.txt","w",stdout);
#endif
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    scanf("%d%d%d",&K,&C,&S);
    printf("Case #%d: ",kase);
    FOR(i,K)
      printf("%d ",i);
    puts("");
  }
  return 0;
}
