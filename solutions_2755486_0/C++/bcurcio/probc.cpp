#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;

#define MAX 14000
#define MA2 7000
int height[MAX];

void solve(){
  memset(height,0,sizeof height);
  int n = in();
  int i,j; 
  int ans = 0;
  vector<piiii> attack;
  for(i=0;i<n;i++){
    int di=in();
    int ni=in();
    int wi=in()*2;
    int ei=in()*2;
    int si=in();
    int ddi=in();
    int ddp=in()*2;
    int dds=in();
    
    attack.push_back(piiii(pii(di,si),pii(wi,ei)));
    for(j=2;j<=ni;j++){
      di+=ddi;
      wi+=ddp;
      ei+=ddp;
      si+=dds;
      attack.push_back(piiii(pii(di,si),pii(wi,ei)));
    }
  }
  sort(attack.begin(),attack.end());
  
  #define WEST(a) ((a).second.first)
  #define EAST(a) ((a).second.second)
  #define STR(a) ((a).first.second)
  j=0;
  int k;
  for(i=0;i<attack.size();i++){
    //cerr << WEST(attack[i]) << ' '<< EAST(attack[i]) << ' '<< STR(attack[i]) ;
    if(i && attack[i-1].first.first!=attack[i].first.first){
      for(;j<i;j++){
        for(k=WEST(attack[j]);k<=EAST(attack[j]);k++) height[k+MA2]=max(height[k+MA2],STR(attack[j]));
      }
    }
    
    bool suc=false;
    for(k=WEST(attack[i]);k<=EAST(attack[i]) && !suc;k++) if(height[k+MA2]<STR(attack[i])) suc=true;
    //cerr << suc << endl;
    if(suc) ans++;
  }
  printf("%d\n",ans);
}

int main(){
  for(int i=0,T=in();i<T;i++){
    printf("Case #%d: ",i+1);
      solve();
    }
}
