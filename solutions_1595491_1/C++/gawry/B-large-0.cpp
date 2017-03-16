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
int n,s,p,t[123],m[123][123];
void solve(){
  //TODO
  scanf("%d %d %d",&n,&s,&p);
  for(int i=1;i<=n;i++)scanf("%d",&t[i]);
  memset(m,-1,sizeof(m));
  m[0][0]=0;
  for(int i=0;i<n;i++)for(int j=0;j<=s;j++)if(m[i][j]>-1)for(int a=0;a<=10;a++)for(int b=0;b<=10;b++)for(int c=0;c<=10;c++)if(a+b+c==t[i+1]&&min(a,min(b,c))+2>=max(a,max(b,c))){
    bool add=min(a,min(b,c))+2==max(a,max(b,c));
    m[i+1][j+add]=max(m[i+1][j+add],m[i][j]+(max(a,max(b,c))>=p));
  }
  printf("%d\n",m[n][s]);
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
