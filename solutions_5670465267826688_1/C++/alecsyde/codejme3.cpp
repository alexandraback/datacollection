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

ii  pro(ii x,ii y){
  int i=x.X+y.X;
  ii z;
  z.X=i%2;
  if(x.Y==0||y.Y==0) z.Y=x.Y+y.Y;
  else if(x.Y==y.Y) {
    z.X=(i+1)%2;z.Y=0;
  }else if(x.Y==1&&y.Y==2){
    z.Y=3;
  }else if(x.Y==1&&y.Y==3){
    z.Y=2;z.X=(i+1)%2;
  }else if(x.Y==2&&y.Y==1){
    z.X=(i+1)%2;z.Y=3;
  }else if(x.Y==2&&y.Y==3){
    z.Y=1;
  }else if(x.Y==3&&y.Y==1){
    z.Y=2;
  }else{
    z.X=(i+1)%2;z.Y=1;
  }
  return z;
}

char s[10005];
ii a[10000],arr[1000005];
int sum[1000005];
int main(){
  int t;
  ii i=mp(0,1),j=mp(0,2),k=mp(0,3);

  scanf("%d",&t);
  REPP(m,1,t+1){
    int l,n,f;
    ll x;
    scanf("%d %lld",&l,&x);
    scanf("%s",s);
    REP(p,l) if(s[p]=='i') a[p]=i; else if(s[p]=='j') a[p]=j; else a[p]=k;
    ii z=mp(0,0);
    REP(p,l) z=pro(z,a[p]);
  //  debug(z.X);debug(z.Y);
    if(z==mp(0,0)){
      printf("Case #%d: NO\n",m);
      continue;
    }
    if(z==mp(1,0)&&(x%2)==0){
      printf("Case #%d: NO\n",m);
      continue;
    }
    if(z!=mp(1,0)&&x%4!=2){
      printf("Case #%d: NO\n",m);
      continue;
    }
    if(z==mp(1,0)&&x>=3) x=3;
    if(z!=mp(1,0)&&x>=18) x=18;
    n=x*l;
    REP(p,x) REP(q,l) arr[p*l+q]=a[q];
    ii y=mp(0,0);
    f=n;
    REPP(p,0,n){
      y=pro(y,arr[p]);
      if(y==i) {
        f=p; break;
      }
    }
    int g=0;
    y=mp(0,0);
    for(int p=n-1;p>=0;p--){
      y=pro(arr[p],y);
      if(y==k){
        if(f<p) g=1;
        break;
      }
    }
    if(g==0)   printf("Case #%d: NO\n",m);
    else   printf("Case #%d: YES\n",m);
  }
  return 0;
}
