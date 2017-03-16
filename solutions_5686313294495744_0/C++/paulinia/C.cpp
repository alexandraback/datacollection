#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<math.h>
//structures
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<deque>
#include<string>
#include<complex>
#include<sstream>
#include<cctype>
#include<iomanip>
#include<bitset>

using namespace std;

#define REP(i,n)	for(int i=1;i<=n;i++)
#define FOR(i,n)	for(int i=0;i<(int)n;i++)
#define FOB(i,n)	for(int i=n;i>=1;i--)
#define druha(x) ((x)*(x))
#define MP(x,y)	make_pair((x),(y))
#define infinity 2000000999
#define ii pair<int, int>
#define lli long long int
#define lili pair<lli, lli>
#ifdef EBUG
#define DBG	if(1)
#else
#define DBG	if(0)
#endif

int getn()
{
  int h;
  scanf("%d",&h);
  return h;
}

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>&par) {
  cout<<par.first<<" "<<par.second<<endl;
  return out;
}

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  FOR(i, v.size()){
    if(i) cout<<" ";
    cout<<v[i];
  }
  cout<<endl;
  return out;
}

struct post{
  vector<int> one;
  vector<int> lim;
  
  post(vector<int> lm){
    lim = lm;
    one = vector<int>(lm.size(), 0);
  }
  
  bool inc(){
    one[0] ++;
    FOR(i, one.size()){
      if(one[i] >= lim[i]){
        if(i == one.size() - 1) return 0;
        one[i] = 0;
        one[i + 1] ++;
      }
    }
    return 1;
  }
  
};

int main(){
  int t = getn();
  FOR(l, t){
    int n = getn();
    map<string, vector<pair<string, bool> > > prve, druhe;
    vector<int> lim;
    int fake = 0;
    FOR(i, n){
      string f, s;
      cin >> f >> s;/*
      if(prve.find(f) != prve.end()) */prve[f].push_back(MP(s, 0));
      druhe[s].push_back(MP(f, 0));
    }
    
    for(auto &v : prve){
      lim.push_back(v.second.size());
    }
    for(auto &v : druhe){
      lim.push_back(v.second.size());
    }
    
    post P(lim);
    
    do{
      int i = 0;
      for(auto &slovo : prve){
        slovo.second[P.one[i]].second = 1;
        for(auto &hladam : druhe[slovo.second[P.one[i]].first]){
          if(hladam.first == slovo.first) hladam.second = 1;
        }
        i ++;
      }
      
      for(auto &slovo : druhe){
        slovo.second[P.one[i]].second = 1;
        for(auto &hladam : prve[slovo.second[P.one[i]].first]){
          if(hladam.first == slovo.first) hladam.second = 1;
        }
        i ++;
      }
      
      int cur_fake = 0;
      
      for(auto &slovo : prve){
        for(auto &vec : slovo.second){
          if(!vec.second) cur_fake ++;
        }
      }
      
      fake = max(fake, cur_fake);
      
    }while(P.inc());
    
    cout << "Case #" << l + 1 << ": " << fake << endl;
    
  }
}
