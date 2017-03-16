#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
double A;
struct node {
  double t,x;
} st[10];
int main() {
  freopen("B-small-attempt1.in","r",stdin);
  freopen("B-small-attempt1.out","w",stdout);
  //freopen("B-large.in","r",stdin);
  //freopen("B-large.out","w",stdout);
  int cas,n,a;
  double D;
  scanf("%d",&cas);
  for(int t=1;t<=cas;t++) {
    scanf("%lf%d%d",&D,&n,&a);
    for(int i=0;i<n;i++) {
       scanf("%lf%lf",&st[i].t,&st[i].x);
    }
    printf("Case #%d:\n",t);
    if(n==1) {
      for(int i=0;i<a;i++) {
        scanf("%lf",&A);
        double v,v0=0,v1,s=0;
        double tmp=D;
        double needT=(sqrt(v0*v0+A*tmp*2)-v0)/A;
        s+=needT;
        printf("%.8lf\n",s);

      }
      continue;
    }
    for(int i=0;i<a;i++) {
      scanf("%lf",&A);
      double v,v0=0,v1,s=0;
      int mark=0;
      for(int j=1;j<n&&mark==0;j++) {
        long double tmp,resultA,TT;
        if(st[j].x<=D) {
          if(j==1) tmp=st[1].x;
          else tmp=st[j].x-st[j-1].x;
          TT=(st[j].t-st[j-1].t);
          tmp-=v0*TT;
          resultA=tmp*2/(TT*TT);
          //printf("resultA:%lf\n",resultA);
          if(resultA<A) {
             v1=v0+resultA*TT;
             s+=TT;
          } else {
             long double needT=(sqrt(v0*v0+A*tmp*2)-v0)/A;
             s+=needT;
             v1=v0+A*needT;
          }
          v0=v1;
        }
        else {
          TT=(st[j].t-st[j-1].t);
          if(j==1)tmp=D;
          else tmp=D-st[j-1].x;
          TT=tmp/(st[j].x-st[j-1].x)*TT;
          mark=1;
          tmp-=v0*TT;
          resultA=tmp*2/(TT*TT);
          //printf("TT:%lf\n",TT);
          //printf("resultA:%lf\n",resultA);
          if(resultA<A) {
             v1=v0+resultA*TT;
             s+=TT;
          } else {
             double needT=(sqrt(v0*v0+A*tmp*2)-v0)/A;
             s+=needT;
             v1=v0+A*needT;
          }
          v0=v1;
        }
      }
      printf("%.8lf\n",s);
    }

  }
  return 0;
}

