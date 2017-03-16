#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<functional>
#include<sstream>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define allv(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).rend()
#define _foreach(it,b,e) for(__typeof__(b); it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll;//dois L's
const long double eps = 1e-5;
const int maxn = 155;
int n;
int c[maxn][2];
long double pos[maxn];//5 meters
long double next_collision(){
  long double t=1e16;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      if(c[i][0]==c[j][0] && c[i][1]>c[j][1] && pos[i]<pos[j]) { //batem
        t = min(t, (pos[j]-pos[i] - 5)/(c[i][1]-c[j][1]));
      }
    }
  }
  return t;
}
inline bool dah(long double x, long double y){
  return fabs(x-y)>=5;
}
inline bool bate(long double x, long double y){
  return x+5>=y && x<y;
}
bool comp(int a, int b){
  return pos[a]>pos[b];
}
bool update_cars(long double x){
  int ord[maxn];
  for(int i=0;i<n;i++){
    pos[i] += x*c[i][1]; 
    ord[i] = i;
  }
  bool has = true;
  sort(ord,ord+n,comp);
  for(int lll=0;lll<5;lll++){
    for(int ppp=0;ppp<n;ppp++){
      int i = ord[ppp];
      int can=1;
      int must=0;
      for(int kkk=0;kkk<n;kkk++){
        int j = ord[kkk];
        if(i==j)continue;
        if(c[i][0]!=c[j][0] && !dah(pos[i],pos[j]))can = 0;
        if(c[i][0]==c[j][0] && c[i][1]>c[j][1] && bate(pos[i],pos[j]))must = 1;
      }
      if(!can && must)return false;
      else if (must) {
        if(c[i][0]==0)c[i][0]=1;
        else c[i][0]=0;
      }
    }
  }
  return true;
}
int st[maxn][2];
long double ps[maxn];
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      scanf("%d",&n);
      for(int i=0;i<n;i++){
        char l;
        scanf(" %c %d %Lf",&l,&st[i][1],&ps[i]);
        st[i][0]=(l=='L')?0:1;
      }
      
      long double ret = 0;
      int gaga[maxn];
      for(int i=0;i<n;i++)
        gaga[i]=i;
      do{
        for(int i=0;i<n;i++){
          c[i][0]=st[gaga[i]][0];
          c[i][1]=st[gaga[i]][1];
          pos[i]=ps[gaga[i]];
        }
        long double t = 0;
        int limite = 100;
        while(limite--){
          long double x = next_collision();
          t+=x;
          if(t>1e15)break;
          if(!update_cars(x))break;
        /*printf(" %lf\n" ,x);
          for(int i=0;i<n;i++){
          printf("<%c %lf %lf>",c[i][0]?'R':'L',c[i][1],c[i][2]);
          }
          printf("\n");*/
        }
        ret = max(t,ret);
      }while(next_permutation(gaga,gaga+n));

      printf("Case #%d: ",pp);
      if(ret<1e14)
        printf("%Lf\n",ret);
      else
        printf("Possible\n");
    }
  return 0;
}
