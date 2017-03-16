#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;

int dp[1005][1005];

int main(){
  int arr[10005];
  int t,n,m,ans,sum,mx;
  FILL(dp,0);
  REPP(i,1,1001) REPP(j,1,1001){
    if(i>=j) dp[i][j]=0;
    else{
      dp[i][j]=1e9;
      REPP(k,1,j/2+1) dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
    }
  }
  scanf("%d",&t);
  REPP(m,1,t+1){
    scanf("%d",&n);
    mx=0;
    ans=1e9;
    REP(i,n){
      scanf("%d",&arr[i]);
      mx=max(mx,arr[i]);
    }
    REPP(i,1,mx+1){
      sum=i;
      REP(k,n) sum+=dp[i][arr[k]];
      if(sum<ans) ans=sum;
    }
    printf("Case #%d: %d\n",m,ans);
  }
  return 0;
}
