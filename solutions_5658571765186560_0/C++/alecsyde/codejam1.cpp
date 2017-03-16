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
  int arr[10005];
  int t,n,m,ans,sum,mx;

  scanf("%d",&t);
  REPP(m,1,t+1){
    int x,r,c;
    scanf("%d %d %d",&x,&r,&c);
    if((x>r)&&(x>c)){
      printf("Case #%d: RICHARD\n",m);
      continue;
    }
    if((r*c)%x!=0){
      printf("Case #%d: RICHARD\n",m);
      continue;
    }
    if(x>=7){
      printf("Case #%d: RICHARD\n",m);
      continue;
    }
    if(x==1||x==2){
      printf("Case #%d: GABRIEL\n",m);
      continue;
    }
    if(r>c) swap(r,c);
    if(x==3){
      if(r>=2){
        printf("Case #%d: GABRIEL\n",m);
        continue;
      }
      printf("Case #%d: RICHARD\n",m);
      continue;
    }
    if(x==4){
      if(r>2){
        printf("Case #%d: GABRIEL\n",m);
        continue;
      }
      printf("Case #%d: RICHARD\n",m);
      continue;
    }
    if(x==5){
      if(r<3||r==3&&c==5){
        printf("Case #%d: RICHARD\n",m);
        continue;
      }
      printf("Case #%d: GABRIEL\n",m);
      continue;

    }

    if(x==6){
      if(r<=3){
        printf("Case #%d: RICHARD\n",m);
        continue;
      }
      printf("Case #%d: GABRIEL\n",m);
      continue;

    }

  }
  return 0;
}
