#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;
int cons[266];
char str[1010010];


void solve(){
  scanf("%s",str);
  int N = in();
  int len= strlen(str);
  long long ans = 0;
  
  long long ant = 0;
  int acum = 0;
  long long cant = 0;
  long long last = 0;
  long long i;
  for(i=0;i<len;i++){
    if(cons[str[i]]){
      acum++;
      if(acum<N){
        ans+=last;
        //cerr << 'a' <<ans << endl;
      }else{
        cant++;
        last=(i-N+2);
        ans+=last;
        //cerr << 'b' <<ans << endl;
      }
    }else{
      acum=0;
      ans+=last;
        //cerr << 'c' <<ans << endl;
    }
  }
  
  printf("%lld\n",ans);
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
