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
const double eps = 1e-9;
const int maxn = 21;
const int maxt = 211;
int dah[(1<<maxn)+10];
int tipo[maxt];

int init[maxt];
int tem[maxt][maxt];
int n;

int gaga(int a)
{
  if(a==((1<<n)-1))return 1;
  if(dah[a]==-1){
    dah[a]=0;
    int disp[maxt];
    for(int i=0;i<maxt;i++)disp[i]=init[i];

    for(int i=0;i<n;i++){
      if(a&(1<<i)){
	for(int j=0;j<maxt;j++)disp[j]+=tem[i][j];
	disp[tipo[i]]--;
      }
    }

    for(int i=0;i<n;i++){
      if(!(a&(1<<i))){
	if(disp[tipo[i]]>0 && gaga(a+(1<<i))){
	  dah[a] = 1;
	}
      }
    }

  }
  return dah[a];
}
int main (){
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++){
      memset(dah,-1,sizeof(dah));
      memset(init,0,sizeof(init));
      memset(tem,0,sizeof(tem));
      memset(tipo,0,sizeof(tipo));

      int k;
      scanf(" %d %d",&k,&n);
      for(int i=0;i<k;i++){
	int a;
	scanf("%d",&a);
	init[a]++;
	assert(a<201);
      }
      for(int i=0;i<n;i++){
	int a;
	scanf("%d %d",&tipo[i],&a);
	assert(tipo[i]<201);
	for(int j=0;j<a;j++){
	  int b;
	  scanf("%d",&b);
	  tem[i][b]++;
	  assert(b<201);
	}
      }
      
      int ret[maxn];
      int at = 0;
      int bla[maxt];
      for(int i=0;i<maxt;i++)bla[i]=init[i];
      bool ok=false;

      for(int i=0;i<n;i++){
	ok =false;
	for(int j=0;j<n;j++){
	  if(at & (1<<j))continue;
	  if(bla[tipo[j]]>0 && gaga(at + (1<<j))){
	    ret[i]=j;
	    at += (1<<j);
	    bla[tipo[j]]--;
	    for(int m=0;m<maxt;m++)
	      bla[m]+=tem[j][m];
	    ok = true;
	    break;
	  }
	}
	if(!ok)break;
      }
      if(!ok)assert(at==0);
      else assert(at==(1<<n)-1);
      printf("Case #%d:",pp);
      if(ok){
	for(int i=0;i<n;i++)printf(" %d",ret[i]+1);
	printf("\n");
      }
      else{
	printf(" IMPOSSIBLE\n");
      }
    }
  return 0;
}
