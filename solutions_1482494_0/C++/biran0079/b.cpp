#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct A{
  int a,b;
  bool l1,l2;
  A(int a,int b):a(a),b(b){
    l1=l2=false;
  }
};
bool cmp1(A* a,A* b){
  if(a->a==b->a)return a->b > b->b;
  else return a->a < b->a;
}
bool cmp2(A* a,A* b){
  if(a->b==b->b)return a->a > b->a;
  else return a->b < b->b;
}
int main(int argc, const char *argv[])
{
  int T,n;
  scanf("%d",&T);
  for(int tm=1;tm<=T;tm++){
    vector<A> a;
    vector<A*> a1,a2;
    printf("Case #%d: ",tm);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      a.push_back(A(x,y));
    }
    for(int i=0;i<n;i++){
      a1.push_back(&a[i]);
      a2.push_back(&a[i]);
    }
    sort(a1.begin(),a1.end(),cmp1);
    sort(a2.begin(),a2.end(),cmp2);
    int ct=0,res=0,i1=0,i2=0;
    bool bad=false;
    while(1){
      while(i2<n){
        if(ct>=a2[i2]->b){
          if(a2[i2]->l1)ct++;
          else ct+=2;
          a2[i2]->l2=true;
          i2++;
          res++;
        }else break;
      }
      if(i2==n)break;
      while(i1<n){
        if(a1[i1]->l2){
          i1++;
          continue;
        }else{
          if(ct<a1[i1]->a){
            bad=true;
            break;
          }
          a1[i1]->l1=true;
          ct++;
          res++;
          i1++;
          if(ct>=a2[i2]->b)
            break;
        }
      }
      if(ct<a2[i2]->b){
        bad=true;
        break;
      }
    }
    if(bad)printf("Too Bad\n");
    else printf("%d\n",res);
  }
  return 0;
}
