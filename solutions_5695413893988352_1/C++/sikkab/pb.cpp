#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007
#define MAXN 205

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
void domod(int &a, ll b){a=(a+b)%MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
int getint(){int a;scanf("%d",&a);return a;}
char *s, *t;
int n;
int best[55];

int dp(int ix, int cr, int nm=true){
  if(ix==n){
    ll a=0,b=0;
    for(int i=0;i<n;i++){
      a = a*10 + s[i]-'0';
      b = b*10 + t[i]-'0';
    }
    return abs(a-b);
  }
  if(cr==1){
    ll a=0, b=0;
    bool sq, tq;
    for(int i=0;i<n;i++){
      sq=false, tq=false;
      if(s[i]=='?')s[i]='0',sq=true;
      if(t[i]=='?')t[i]='9',tq=true;
      a = a*10 + s[i]-'0';
      b = b*10 + t[i]-'0';
      if(sq && nm)s[i]='?';
      if(tq && nm)t[i]='?';
    }
    return a-b;
  }
  if(cr==2){
    //t is larger
    ll a=0, b=0;
    bool sq, tq;
    for(int i=0;i<n;i++){
      sq=false, tq=false;
      if(s[i]=='?')s[i]='9',sq=true;
      if(t[i]=='?')t[i]='0',tq=true;
      a = a*10 + s[i]-'0';
      b = b*10 + t[i]-'0';
      if(sq && nm)s[i]='?';
      if(tq && nm)t[i]='?';
    }
    return b-a;
  }
  ll ret1,ret2;
  if(s[ix]=='?' && t[ix]=='?'){
    s[ix]='1',t[ix]='0';
    ret1=dp(ix+1,1,nm);
    best[ix]=1;
    s[ix]='0',t[ix]='1';
    ret2=dp(ix+1,2,nm);
    if(ret2<=ret1)ret1=ret2,best[ix]=2;
    s[ix]='0',t[ix]='0';
    ret2=dp(ix+1,0,nm);
    if(ret2<=ret1)ret1=ret2,best[ix]=0;
    if(nm){ s[ix]=t[ix]='?'; }
    else {
      if(best[ix]==0)s[ix]=t[ix]='0';
      else if(best[ix]==1)s[ix]='1',t[ix]='0';
      else s[ix]='0',t[ix]='1';
    }
    return ret1;

  }else if(s[ix]=='?'){
    s[ix]=t[ix];
    best[ix]=0;
    ret1=dp(ix+1,0,nm);
    if(t[ix]<'9'){
      s[ix]=t[ix]+1;
      ret2=dp(ix+1,1,nm);
      if(ret2<ret1)ret1=ret2,best[ix]=1;
    }
    if(t[ix]>'0'){
      s[ix]=t[ix]-1;
      ret2=dp(ix+1,2,nm);
      if(ret2<=ret1)ret1=ret2,best[ix]=2;
    }
    if(nm){
      s[ix]='?';
    } else {
      if(best[ix]==0)s[ix]=t[ix];
      else if(best[ix]==1)s[ix]=t[ix]+1;
      else s[ix]=t[ix]-1;
    }
    return ret1;
  }else if(t[ix]=='?'){
    t[ix]=s[ix];
    best[ix]=0;
    ret1=dp(ix+1,0,nm);
    if(s[ix]<'9'){
      t[ix]=s[ix]+1;
      ret2=dp(ix+1,2,nm);
      if(ret2<ret1)ret1=ret2,best[ix]=2;
    }
    if(s[ix]>'0'){
      t[ix]=s[ix]-1;
      ret2=dp(ix+1,1,nm);
      if(ret2<=ret1)ret1=ret2,best[ix]=1;
    }
    if(nm){
      t[ix]='?';
    } else {
      if(best[ix]==0)t[ix]=s[ix];
      else if(best[ix]==1)t[ix]=s[ix]-1;
      else t[ix]=s[ix]+1;
    }
    return ret1;
  }else{
    if(s[ix]>t[ix]){
      ret1=dp(ix+1,1,nm);
      best[ix]=1;
    }else if(s[ix]<t[ix]){
      ret1=dp(ix+1,2,nm);
      best[ix]=2;
    }else{
      ret1=dp(ix+1,0,nm);
    }
    return ret1;
  }
}

void doit() {
  s = new char[MAXN];
  t = new char[MAXN];
  memset(best,0,sizeof(best));
  scanf("%s %s",s,t);
  n=strlen(t);
  dp(0,0);
  int ix=0;
  while(ix<n && best[ix]==0){
    if(s[ix]=='?' && t[ix]=='?'){s[ix]=t[ix]='0';}
    else if(s[ix]=='?')s[ix]=t[ix];
    else if(t[ix]=='?')t[ix]=s[ix];
    ix++;
  }
  if(ix<n){
    if(best[ix]==0){
      if(s[ix]=='?' && t[ix]=='?')s[ix]=t[ix]='0';
      else if(s[ix]=='?')s[ix]=t[ix];
      else if(t[ix]=='?')t[ix]=s[ix];
    }else if(best[ix]==1){
      if(s[ix]=='?' && t[ix]=='?')s[ix]='1',t[ix]='0';
      else if(s[ix]=='?')s[ix]=t[ix]+1;
      else if(t[ix]=='?')t[ix]=s[ix]-1;
    }else if(best[ix]==2){
      if(s[ix]=='?' && t[ix]=='?')s[ix]='0',t[ix]='1';
      else if(s[ix]=='?')s[ix]=t[ix]-1;
      else if(t[ix]=='?')t[ix]=s[ix]+1;
    }
    dp(ix+1,best[ix],0);
  }

  printf("%s %s", s,t);
  delete[]s, delete[] t;
}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
    cout<<endl;
  }
  return 0;
}
