#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

typedef pair<int,int> pii;
typedef pair<int,pii> piii;


void solve(){
  int j = in();
  int p = in();
  int s = in();
  int k = in();
  
  vector<piii> outs;
  vector<piii> sols;
  
  int a,b,c;
  for(a=1;a<=j;a++)
  for(b=1;b<=p;b++)
  for(c=1;c<=s;c++) outs.push_back(piii(a,pii(b,c)));
  
  if(s==0){
    cout << 0 << endl;
    return;
  }
  
  int n = outs.size();
  //~ cerr << " n  " << n << endl;
  
  int i;
  
  for(i=1;i<5000;i++){
    random_shuffle(outs.begin(),outs.end());
    
    bool can = true;
    
    map<int,int> p1;
    map<int,int> p2;
    map<int,int> p3;
    vector<piii> cur;
    
    for(a = 0;can && a<n ; a++){
      
      p1[ outs[a].first*10 + outs[a].second.first]++;
      if(p1[ outs[a].first*10 + outs[a].second.first ] >k) can = false;
      
      p2[ outs[a].first*10 + outs[a].second.second]++;
      if(p2[ outs[a].first*10 + outs[a].second.second ] >k) can = false;
      
      p3[ outs[a].second.first*10 + outs[a].second.second]++;
      if(p3[ outs[a].second.first*10 + outs[a].second.second ] >k) can = false;
      
      if(can) cur.push_back(outs[a]);
      
      if(!can){
        p1[ outs[a].first*10 + outs[a].second.first]--;
        p2[ outs[a].first*10 + outs[a].second.second]--;
        p3[ outs[a].second.first*10 + outs[a].second.second]--;
        can = true;
      }
      
    }
    
    
    if(cur.size()>sols.size()){
      sols.swap(cur);
    }
    
  }
  
  cout << sols.size() << endl;
  for(i=0;i<sols.size();i++){
    cout << sols[i].first << ' ' << sols[i].second.first << ' ' << sols[i].second.second << endl;
  }
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": " ;
      solve();
    }
}
