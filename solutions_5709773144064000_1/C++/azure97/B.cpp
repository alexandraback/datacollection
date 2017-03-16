#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void open(){
 freopen("B-large.in","r",stdin);
 freopen("Bf.out","w",stdout);
}

void close(){
 fclose(stdin);
 fclose(stdout);
}

double c,f,x,acct,accx,ans;
int tc;

int main(){
 open();
 scanf("%d",&tc);
 for(int t=1;t<=tc;t++){
  ans=2000000000.0;
  scanf("%lf %lf %lf",&c,&f,&x);
  acct=0.0;
  accx=2.0;
  for(int i=0;i<=200000;i++){
   ans=min(ans,acct+x/accx);
   acct+=c/accx;
   accx+=f;
  }
  printf("Case #%d: %.7lf\n",t,ans);
 }
 close();
 return 0;
}
