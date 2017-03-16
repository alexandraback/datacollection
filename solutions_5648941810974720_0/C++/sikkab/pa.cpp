#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007
#define MAXN 2005

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
void domod(int &a, ll b){a=(a+b)%MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
int getint(){int a;scanf("%d",&a);return a;}


bool findnext(int n,char *s, vi &res){
  if(strchr(s,'Z')){
    bool zd=false, ed=false,rd=false,od=false;
    for(int i=0;i<n;i++){
      if(s[i]=='Z' && !zd)s[i]=' ',zd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
      if(s[i]=='R' && !rd)s[i]=' ',rd=true;
      if(s[i]=='O' && !od)s[i]=' ',od=true;
    }
    res.pb(0);
    return true;
  }
  if(strchr(s,'W')){
    bool td=false, wd=false,od=false;
    for(int i=0;i<n;i++){
      if(s[i]=='T' && !td)s[i]=' ',td=true;
      if(s[i]=='W' && !wd)s[i]=' ',wd=true;
      if(s[i]=='O' && !od)s[i]=' ',od=true;
    }
    res.pb(2);
    return true;
  }
  if(strchr(s,'U')){
    bool fd=false, ud=false,od=false,rd=false;
    for(int i=0;i<n;i++){
      if(s[i]=='F' && !fd)s[i]=' ',fd=true;
      if(s[i]=='O' && !od)s[i]=' ',od=true;
      if(s[i]=='U' && !ud)s[i]=' ',ud=true;
      if(s[i]=='R' && !rd)s[i]=' ',rd=true;
    }
    res.pb(4);
    return true;
  }
  if(strchr(s,'X')){
    bool sd=false, id=false,xd=false;
    for(int i=0;i<n;i++){
      if(s[i]=='S' && !sd)s[i]=' ',sd=true;
      if(s[i]=='I' && !id)s[i]=' ',id=true;
      if(s[i]=='X' && !xd)s[i]=' ',xd=true;
    }
    res.pb(6);
    return true;
  }
  if(strchr(s,'G')){
    bool ed=false,id=false, gd=false,hd=false,td=false;
    for(int i=0;i<n;i++){
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
      if(s[i]=='I' && !id)s[i]=' ',id=true;
      if(s[i]=='G' && !gd)s[i]=' ',gd=true;
      if(s[i]=='H' && !hd)s[i]=' ',hd=true;
      if(s[i]=='T' && !td)s[i]=' ',td=true;
    }
    res.pb(8);
    return true;
  }
  if(strchr(s,'O')){
    bool nd=false, ed=false,od=false;
    for(int i=0;i<n;i++){
      if(s[i]=='O' && !od)s[i]=' ',od=true;
      if(s[i]=='N' && !nd)s[i]=' ',nd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
    }
    res.pb(1);
    return true;
  }
  if(strchr(s,'H')){
    bool ed=false,rd=false, eed=false,hd=false,td=false;
    for(int i=0;i<n;i++){
      if(s[i]=='T' && !td)s[i]=' ',td=true;
      if(s[i]=='H' && !hd)s[i]=' ',hd=true;
      if(s[i]=='R' && !rd)s[i]=' ',rd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
      if(s[i]=='E' && !eed)s[i]=' ',eed=true;
    }
    res.pb(3);
    return true;
  }
  if(strchr(s,'F')){
    bool fd=false, id=false,vd=false,ed=false;
    for(int i=0;i<n;i++){
      if(s[i]=='F' && !fd)s[i]=' ',fd=true;
      if(s[i]=='I' && !id)s[i]=' ',id=true;
      if(s[i]=='V' && !vd)s[i]=' ',vd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
    }
    res.pb(5);
    return true;
  }
  if(strchr(s,'V')){
    bool ed=false,sd=false, eed=false,vd=false,nd=false;
    for(int i=0;i<n;i++){
      if(s[i]=='S' && !sd)s[i]=' ',sd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
      if(s[i]=='V' && !vd)s[i]=' ',vd=true;
      if(s[i]=='E' && !eed)s[i]=' ',eed=true;
      if(s[i]=='N' && !nd)s[i]=' ',nd=true;
    }
    res.pb(7);
    return true;
  }
  if(strchr(s,'N')){
    bool nd=false, ed=false,id=false,nnd=false;
    for(int i=0;i<n;i++){
      if(s[i]=='N' && !nd)s[i]=' ',nd=true;
      if(s[i]=='I' && !id)s[i]=' ',id=true;
      if(s[i]=='N' && !nnd)s[i]=' ',nnd=true;
      if(s[i]=='E' && !ed)s[i]=' ',ed=true;
    }
    res.pb(9);
    return true;
  }
  return false;
}

void doit() {
  char *s;
  vi res;
  s = new char[MAXN];
  scanf("%s", s);
  int n=strlen(s);
  while(findnext(n,s,res)){};
  sort(res.begin(), res.end());
  for(auto i:res){
    printf("%d",i);
  }
  
}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d: ",i);
    doit();
    printf("\n");
  }
  return 0;
}
