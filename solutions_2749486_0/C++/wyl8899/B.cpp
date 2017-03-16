//#define FILE_IO

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef double lf; 

typedef pair<int,int> pii;
typedef pair<lf,lf> pff;
#define mp make_pair
#define X first
#define Y second  

#define pb push_back
#define forI_(i,V,_) for(typeof(V.end())i=_;i!=V.end();++i)
#define forI(i,V) forI_(i,V,V.begin())

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T,Case=0;
  int x,y;
  for(scanf("%d",&T);T--;){
    printf("Case #%d: ",++Case);
    scanf("%d%d",&x,&y);
    while(x>0)
      printf("WE"),--x;
    while(x<0)
      printf("EW"),++x;
    while(y>0)
      printf("SN"),--y;
    while(y<0)
      printf("NS"),++y;
    puts("");
  }
  return 0;
}
