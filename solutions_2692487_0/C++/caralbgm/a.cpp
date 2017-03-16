#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define _f(i,x,n) for(int i=x;i<n;i++)
#define _if(i,x,n) for(int i=(n);i>=x;i++)
#define _fv(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

#define _d(var) cout<<"L"<<__LINE__<<": "<<#var<<": "<<var<<endl;
#define _dv(v) cout<<"L"<<__LINE__<<": "<<#v<<": "; di((v).begin(),(v).end());
#define _dvf(v) cout<<"L"<<__LINE__<<": "<<#v<<": "; di((v).begin(),(v).end()); *************************
template<typename it> void di(it i,it f) { cout<<"[ "; while(i!=f) cout<<*(i++)<<" "; cout<<"]"<<endl; }
template<typename it> void dif(it i,it f,string ) { cout<<"[ "; while(i!=f) cout<<*(i++)<<" "; cout<<"]"<<endl; }
#define _ln cout<<"_ln: "<<__LINE__<<endl;

class State{
  public:
    int mote;
    int step;
    int eaten;
    
    State(int m,int s,int e){
      mote = m;
      step = s;
      eaten = e;
    }
    
    string s(){
      stringstream ss;
      ss<<"mote: "<<mote<<" step: "<<step<<" eaten: "<<eaten;
      return ss.str();
    }
};

struct statecmp {
  bool operator() (const State& s1, const State& s2) const{
    if(s1.step == s2.step)
      return s1.eaten > s2.eaten;
    return s1.step > s2.step;
  }
};

int motes[1000000];
int N, A;

int eat(){
  //order motes
  sort(motes,motes+N);
  
  //init state
  State s(A,0,0);
  priority_queue<State, vector<State>, statecmp> q;
  q.push(s);
  while(s.eaten < N){
    s = q.top();
    q.pop();
    //_d("extract:")_d(s.s())
    if(s.eaten >= N) break;
    
    //eat
    if(s.mote > motes[s.eaten]){
      //_d("eat:")_d(State(s.mote + motes[s.eaten], s.step, s.eaten + 1).s())
      q.push(State(s.mote + motes[s.eaten], s.step, s.eaten + 1));
    }
    else{
      //remove the current mote to eat
      //_d("remove")_d(State(s.mote, s.step + 1, s.eaten + 1).s())
      q.push(State(s.mote, s.step + 1, s.eaten + 1));
      //add small motes
      if(s.mote > 1){
        int size = s.mote;
        int steps = 0;
        while(motes[s.eaten] >= size){
          size += (size - 1);
          steps++;
        }
        //_d("add")_d(State(size + motes[s.eaten], s.step + steps, s.eaten + 1).s())
        q.push(State(size + motes[s.eaten], s.step + steps, s.eaten + 1));
      }
    }
  }
  
  return s.step;
}

int main(){
    int T;
    cin>>T;
    _f(tt,1,T+1){
        cin>>A>>N;
        _f(i,0,N)
          cin>>motes[i];
        
        cout<<"Case #"<<tt<<": "<<eat()<<endl;
    }
    return 0;
}
