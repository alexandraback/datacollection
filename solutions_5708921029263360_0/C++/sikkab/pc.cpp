#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
void addmod(int &a, ll b){a=(a+b); if(a>=MODV)a-=MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
int getint(){int a;scanf("%d",&a);return a;}
ll getll(){ll a;scanf("%lld",&a);return a;}

void doit() {
  map<pi,int> xy, yz, xz;
  vector<pair<pi,int>> ans;
  int j=getint(), p=getint(),s=getint(), k=getint(), ret=0;
  for(int x=1;x<=j;x++)
  for(int y=1;y<=p;y++)
  for(int z=1;z<=s;z++){
   if(xy[{x,y}]>=k)continue; 
   if(yz[{y,z}]>=k)continue; 
   if(xz[{x,z}]>=k)continue; 
   ans.pb({{x,y},z});
   xy[{x,y}]+=1;
   yz[{y,z}]+=1;
   xz[{x,z}]+=1;
   ret++;
  }

  printf("%d\n",ret);
  for(auto i:ans){
    printf("%d %d %d\n",i.fi.fi,i.fi.se,i.se);
  }

}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
  }
  return 0;
}
