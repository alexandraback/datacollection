#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
char world[32][32];
ll od,d,w,h;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
bool eq(ld a,ld b){return abs(a-b)<=1e-12L;}

bool check(ld ox,ld oy,ld dx,ld dy){
  ld x=ox, y=oy;
  ld tot=sqrtl(dx*dx+dy*dy);
  ld remain = od;
  while (remain>0){
    if (((x-ox)*dx+(y-oy)*dy)<0 and eq((x-ox)*dy,(y-oy)*dx)){
      return (x-ox)*(x-ox)+(y-oy)*(y-oy)<=remain*remain+1e-12L;
    }
    ld range=1e12L, rox, roy;
    if (dx>0) range=min(range,rox=(w-x)/dx); else range=min(range,rox=(0-x)/dx);
    if (dy>0) range=min(range,roy=(h-y)/dy); else range=min(range,roy=(0-y)/dy);
    if (range<=1e-12L) break; else remain-=range*tot;
    x+=dx*range, y+=dy*range;
    if (eq(range,rox)) dx=-dx;
    if (eq(range,roy)) dy=-dy;
  }
  return false;
}

int stupid(){
  cin>>w>>h>>od; for (int i=w; i--;) cin>>world[i];
  ll x,y; for (int i=w; i--;) for (int j=h; j--;) if (world[i][j]=='X') x=i,y=j;
  d=(od*=2), d*=d, w=w*2-4, h=h*2-4, x=x*2-1, y=y*2-1;

  ll res= (x*2<=od) + (y*2<=od) + ((w-x)*2<=od) + ((h-y)*2<=od);

  for (ll i=111; i-->-111;)
    for (ll j=111; j-->-111;)
      if (i!=0 and j!=0 and gcd(abs(i),abs(j))==1)
        res+=(check(x,y,i,j));

  return res;
}

int main(){
  freopen("D.in","r",stdin);
  int tests; cin>>tests; for (int test=1; test<=tests; test++) cout<<"Case #"<<test<<": "<<stupid()<<endl;
}
