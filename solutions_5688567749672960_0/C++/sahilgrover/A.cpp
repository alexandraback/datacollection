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


int ar[1000006],visit[1000006];
queue <int> q;
void bfs(){
  q.push(1);
  ar[1]=1;
  visit[1]=1;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    int k=p,s=0;
    while(k>0){
      s=s*10+k%10;
      k=k/10;
    }
    k=s;
    if(k<1000001 && visit[k]==0){ ar[k]=ar[p]+1;
      visit[k]=1;
      q.push(k);
    }
    k=p+1;
    if(k<1000001 && visit[k]==0){ ar[k]=ar[p]+1;
      visit[k]=1;
      q.push(k);
    }
  }
}
int main(){
  bfs();
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    int n;
    scanf("%d",&n);
    printf("Case #%d: %d\n",i,ar[n]);
  }
  return 0;
}
