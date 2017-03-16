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



int main(){
  char s[10005];
  int t,n,m,ans,sum;
  scanf("%d",&t);
  REPP(n,1,t+1){
    scanf("%d",&m);
    scanf("%s",s);
    ans=0;
    sum=0;
    REP(i,m+1){
      if(sum<i&&s[i]!='0'){
        ans+=i-sum;
        sum=i;
      }
      sum+=s[i]-'0';
    }
    printf("Case #%d: %d\n",n,ans);
  }
  return 0;
}
