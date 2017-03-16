#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;
int cons[266];
char str[10101010];

int nv(int x,int y){
  int ans =0 ;
  int cur =0;
  int i;
  for(i=x;i<=y;i++){
    if(cons[str[i]]){
      cur++;
    }else{
      ans = max(cur,ans);
      cur = 0;
    }
  }
      ans = max(cur,ans);
  return ans;
}

void solve(){
  scanf("%s",str);
  int N = in();
  int len=strlen(str);
  int i,j,cnt =0;
  
  for(i=0;i<len;i++){
    for(j=i;j<len;j++){
      if(nv(i,j)>=N) cnt++;
    }
  }
  printf("%d\n",cnt);
}

int main(){
  memset(cons,-1,sizeof cons);
  cons['a']=0;
  cons['e']=0;
  cons['i']=0;
  cons['o']=0;
  cons['u']=0;
  for(int i=0,T=in();i<T;i++){
    printf("Case #%d: ",i+1);
      solve();
    }
}
