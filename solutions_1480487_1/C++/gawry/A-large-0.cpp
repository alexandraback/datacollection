#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,s[210];
void solve(){
  scanf("%d",&n);
  FOR(i,n)scanf("%d",&s[i]);
  int X=accumulate(s,s+n,0);
  FOR(i,n){
    long double from=0,to=1;
    FOR(z,100){
      long double y=(from+to)/2;
      long double sum=y;
      FOR(j,n)if(i!=j)sum+=max((long double)0.0,y+(long double)(s[i]-s[j])/X);
      if(sum>1)to=y;else from=y;
    }
    printf(" %.6Lf",from*100);
  }
  printf("\n");
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d:",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

