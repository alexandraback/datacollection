#include<cstdio>
#include<algorithm>
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
#define MAX 2000000
void solve(){
  //TODO
  int A,B,cnt=0;
  scanf("%d %d",&A,&B);
  typedef pair<int,int> p2;
  set<p2> seen;
  for(int i=A;i<=B;i++){
    char buf[20]={};
    sprintf(buf,"%d",i);
    int len=strlen(buf);
    for(int j=1;j<len;j++)if(buf[j]!='0'){
      int val=0;
      for(int k=j;k<len;k++)val=10*val+buf[k]-'0';
      for(int k=0;k<j;k++)val=10*val+buf[k]-'0';
      if(val>i&&val<=B&&!seen.count(p2(i,val))){
        //printf("%d %d\n",i,val);
        seen.insert(p2(i,val));
        ++cnt;
      }
    }
  }
  printf("%d\n",cnt);
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
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}
