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

int r,n,m,k;
int val[20];
int prod[20];
map<int,int> tab;

huge best;
int ret[20];
int gaga[20];

int certo[20];
int dif;
int med = 0;
void tenta(int a, int last){
  if(a==n){
    tab.clear();
    for(int i=0;i<(1<<n);i++){
      int p=1;
      for(int j=0;j<n;j++){
	if(i&(1<<j))p*=val[j];
      }
      //      printf("%d\n",p);
      tab[p]++;
    }
    huge bate = 1;
    for (int i=0;i<k;i++){
      bate = bate*(tab[prod[i]]+1)*(tab[prod[i]]+1);
      if(bate<0)break;
    }
    // for(int i=0;i<n;i++)printf("%d ",val[i]);
    //    printf("%d\n",bate);
    if(bate > best || bate<0){
      best=bate;
      for(int i=0;i<n;i++)ret[i]=val[i];
    }
    return;
  }
  for(int i=last;i<=m;i++){
    if(certo[i]==0)
      continue;
    int falta = n-a+1;
    if(falta<dif)continue;
    val[a]=i;
    gaga[val[a]]++;
    if(gaga[val[a]]==1)dif--;
    if(gaga[val[a]]<=med)
      {
	tenta(a+1, val[a]);
      }
    if(gaga[val[a]]==1)dif++;
    gaga[val[a]]--;
  }
}
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      memset(gaga,0,sizeof(gaga));
      memset(certo,0,sizeof(certo));
      scanf("%d %d %d %d",&r,&n,&m,&k);
      printf("Case #%d:\n",pp);
      for(int rr=0;rr<r;rr++){
	for(int i=0;i<k;i++)
	  scanf("%d",&prod[i]);
	for(int i=0;i<k;i++){
	  for(int j=2;j<=m;j++){
	    if(prod[i]%j==0){certo[j]=1;}
	  }
	}
	
	dif = 0;
	for(int i=0;i<10;i++)
	  dif+=certo[i];
	med = n/dif + 1;

	best=0;
	for(int i=0;i<n;i++)ret[i]=2;
	tenta(0,2);
	for(int i=0;i<n;i++)
	  printf("%d",ret[i]);
	printf("\n");
      }
    }
  return 0;
}
