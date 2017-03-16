#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1e-7

typedef pair<int,int> ii;

int C=1,T;
int n,X,sum,a;
ii v[256];
double res[256];

int cmpf(double a, double b){
  if(fabs(a-b)<=EPS) return 0;
  return a<b?-1:1;
}

bool sempreganho(ii val,double p){
  double dX=(double)X;
  double meuvalor = (double)val.first + dX*p;

  // find meuvaloe
  double sum=0.0;
  int cnt=0;
  for(int i=0;i<n;i++) if(v[i].second!=val.second){
    if(cmpf((double)v[i].first,meuvalor)<0){
      sum+=v[i].first;
      cnt++;
    }
  }
  return cmpf((double)cnt*meuvalor,sum+dX*(1-p))>0;
}

double busca(ii v){
  double ini=0.0,fim=1.0;
  double meio=(ini+fim)/2.0;
  for(int i=0;i<100;i++){
    if(sempreganho(v,meio))
      fim=meio;
    else
      ini=meio;
    meio=(ini+fim)/2.0;
  }
  return meio*100.0;
}

int main(){

  scanf("%d",&T);
  while(T--){
    printf("Case #%d: ",C++);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      v[i]=ii(a,i);
    }
    X=0; for(int i=0;i<n;i++) X+=v[i].first;
    sort(v,v+n);
    for(int i=0;i<n;i++)
      res[v[i].second] = busca(v[i]);

    for(int i=0;i<n;i++){
      if(i) printf(" ");
      printf("%lf",res[i]);
    }
    printf("\n");
  }

  return 0;
}
