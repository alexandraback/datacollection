#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = 99999999;

struct node {
  int level;
  int id;
  int req; // star requirement
};

class comp{
public:
  bool operator()(const node &lhs, const node &rhs){
    if(lhs.req != rhs.req)
      return lhs.req < rhs.req;
    
    return lhs.level < rhs.level;
  }
};

int main(){

  ifstream in;
  ofstream out;
  
  in.open("b.in");
  
  out.open("b.out");
  
  int T;
  in >> T;

  for(int tt=1; tt<=T; tt++){
    cout << "doing test " << tt << endl;
    int N;
    in >> N;
    
    
    int level1req[N];
    int level2req[N];
    
    for(int i=0; i<N; i++)
      in >> level1req[i] >> level2req[i];
    
    int best = inf;
      
    for(int z=0; z <(1<<N); z++){  
      vector<node> v;
      v.resize(N);
      for(int i=0; i<N; i++){
        v[i].id = i;
        v[i].level = 2;
        v[i].req = level2req[i];    
      }
      for(int i=0; i<N; i++){
        if((1<<i) & z){
          node x;
          x.id = i;
          x.level = 1;
          x.req = level1req[i];
          v.push_back(x);
        }
      }
      sort(v.begin(), v.end(), comp());
      int stars = 0;
      int tries = 0;
      bool pass = true;
      bool seenlevel1[N];
      bool seenlevel2[N];
      memset(seenlevel1,false,N);
      memset(seenlevel2,false,N);
      for(int i=0; i<v.size(); i++){
        if(v[i].req > stars)
          pass = false;
        if(v[i].level == 1){
          stars++;
          seenlevel1[v[i].id] = true;
        }
        if(v[i].level == 2){
          if(!seenlevel1[v[i].id])
            stars+=2;
          else
            stars++;
          seenlevel2[v[i].id] = true;
        }
        tries++;
      }
      if(!pass)
        continue;
      best = min(best,tries);
    }
    if(best == inf)
      out << "Case #" << tt << ": " << "Too Bad" << endl;
    else
      out << "Case #" << tt << ": " << best << endl; 
  }
}
