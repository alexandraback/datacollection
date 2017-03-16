#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef struct el_ {
  int a,b;
  int foi;
} el;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int C=1,T;
int n,a,b,res;
el v[1024];
map<iii,int> PD;


int run(int bm1,int bm2,int stars){
  if(stars==2*n) return 0;
  if(PD.find(iii(ii(bm1,bm2),stars))!=PD.end()) return PD[iii(ii(bm1,bm2),stars)];
  int res=0x3f3f3f3f;
  int op1,op2;

  // para cada ligado
  for(int i=0;i<n;i++) if((bm1&(1<<i))){
    op1=op2=0x3f3f3f3f;
    if(stars>=v[i].a and !(bm2&(1<<i)))
      op1=1+run(bm1,bm2^(1<<i),stars+1);
    if(stars>=v[i].b)
      op2=1+run(bm1^(1<<i),bm2,stars+((bm2&(1<<i))?1:2));
    res=min(res,min(op1,op2));
  }
  return PD[iii(ii(bm1,bm2),stars)]=res;
}

int main(){

  scanf("%d",&T);
  while(T--){
    printf("Case #%d: ",C++);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d %d",&a,&b);
      el in = {a,b,0};
      v[i]=in;
    }
    PD.clear();
    res=run(0xffffffff,0,0);
    if(res==0x3f3f3f3f)
      printf("Too Bad\n");
    else
      printf("%d\n",res);
  }

  return 0;
}
