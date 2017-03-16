#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int ans[500];
double res[500];
int main() {
  freopen("A-small-attempt3.in","r",stdin);
  freopen("A-small-attempt3.out","w",stdout);
  int cas,n;
  scanf("%d",&cas);
  for(int t=1;t<=cas;t++) {
    scanf("%d",&n);
    int X=0;
    for(int i=0;i<n;i++)scanf("%d",&ans[i]),X+=ans[i],res[i]=-1;
    double avg=X*2.0/n;
    double tmp=X*2.0;
    printf("Case #%d:",t);
    int num=n;
    for(int i=0;i<n;i++) {
      if(avg<=ans[i]) {
        res[i]=0;
        tmp-=ans[i];
        num--;
      }
    }
    //cout<<"tmp:"<<tmp<<"num:"<<num<<endl;
    avg=tmp/num;
    for(int i=0;i<n;i++) {
      if(res[i]==-1) {
        res[i]=(avg-ans[i])*100.0/X;
      }
    }
    for(int i=0;i<n;i++) {
      printf(" %lf",res[i]);
    }
    printf("\n");
  }
  return 0;
}
