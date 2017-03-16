#include <bits/stdc++.h>
using namespace std;
#define TR(i,v)       for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x)      cout<<#x<<" = "<<x<<endl
#define SIZE(p)       (int)(p).size()
#define MP(a,b)       make_pair((a),(b))
#define ALL(p)        (p).begin(),(p).end()
#define rep(i,n)      for(int i=0;i<(int)(n);++i)
#define REP(i,a,n)    for(int i=(a);i<(int)(n); ++i)
#define FOR(i,a,b)    for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a)   for(int i=(int)(b);i>=(int)(a);--i)
#define CLR(x,y)      memset((x),(y),sizeof((x)))
typedef long long LL;
typedef pair<int,int> pii;
bool v[1000005];
int dp[1000005],pre[1000005];
LL p0[15];
int glen(LL x){
  int len=0;
  while(x)++len,x/=10;
  return len;
}
LL get(LL a,LL b){
  char ss[30];
  sprintf(ss,"%lld",b);
  int m=strlen(ss);
  
  LL res=0;
  LL t=0;
  FORD(i,m/2-1,0)t=t*10+(ss[i]-'0');
  if(t==1)++res;
  else{
    t+=p0[m-1];  
    res+=t-a;
    ++res;
  }
  LL o=b;
  rep(i,m-m/2)o/=10;
  rep(i,m-m/2)o*=10;
  o+=1;
  //DEBUG(b);
  //DEBUG(o);
  res+=b-o;
  //DEBUG(res);
  return res;
}
int main(){
  queue<int> q;
  q.push(1);v[1]=1;
  dp[1]=0;
  while(!q.empty()){
    int x=q.front();q.pop();
    int y;
    char ss[30];sprintf(ss,"%d",x);reverse(ss,ss+strlen(ss));
    y=atoi(ss);
    if(!v[y] && y<=1000000){
      v[y]=1;
      dp[y]=dp[x]+1;
      q.push(y);  
      pre[y]=x;
    }
    y=x+1;
    if(!v[y] && y<=1000000){
      v[y]=1;
      dp[y]=dp[x]+1;
      pre[y]=x;
      q.push(y);
    }    
  }  
  int T;scanf("%d",&T);  
  p0[0]=1;
  FOR(i,1,14)p0[i]=10LL*p0[i-1];
  FOR(cs,1,T){
    LL n;scanf("%lld",&n);
    printf("Case #%d: ",cs);
    if(n<100){
      printf("%d\n",dp[n]+1);
      continue;
    }
    LL res=1;
    if(n%10==0)--n,++res;
    LL x=1;
    int nlen=glen(n);    
    while(glen(x)<nlen){
      //DEBUG(x);
      //DEBUG(res);
      int l=glen(x);
      LL s=0;
      rep(i,l/2)s=s*10+9;
      res+=s;
      // ////DEBUG(s);
      if(s)++res;
      LL t=1;
      for(int i=l-1,j=0;j<l/2;++j,--i)t+=9*p0[i];
      LL nxt=1;
      rep(i,l)nxt*=10;
      // ////DEBUG(t);
      // ////DEBUG(nxt);
      res+=nxt-t;
      x=nxt;
    }
    //DEBUG(res);
    res+=get(x,n);
    printf("%lld\n",res);
  }
  return 0;
}