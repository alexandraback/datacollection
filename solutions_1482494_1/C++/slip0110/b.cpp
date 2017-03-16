#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
bool used[1010][2];

class State{
public:
  int a,b,idx;
  State(int c, int d , int i){
    a = c;
    b = d;
    idx = i;
  }
  bool operator <(const State &o)const{
    if(b != o.b)return b > o.b;
    return a < o.a;
  }
};

typedef pair<int,int> P;
int main(){
  int T;
  cin>>T;
  REP(t,1,T+1){
    memset(used , 0 ,sizeof(used));
    int n;
    cin>>n;
    vector<State> one;
    priority_queue<P> two,two2;

    rep(i,n){
      int a,b;
      cin>>a>>b;
      one.push_back(State(a,b,i));
      two.push(P(-b,i));
    }

    int res = 0;
    int star = 0;
    while(!two.empty() || !two2.empty()){
      //cout<<star<<" "<<one.size()<<" "<<two.size()<<" "<<two2.size()<<endl;
     if(!two.empty()){
        P st = two.top();
        if(used[st.second][0]){
          two2.push(st);
          two.pop();
          continue;
        }
        int next = st.first * -1;
        if(next <= star){
          star += 2;
          res++;
          used[st.second][1] = true;
          two.pop();
          continue;
        }
      }
      if(!two2.empty()){
        P st = two2.top();
        int next = st.first * -1;
        if(next <= star){
          star += 1;
          res++;
          used[st.second][1] = true;
          two2.pop();
          continue;
        }
        
      }

      if(one.empty()){
        break;
      }
      

      bool f = false;
      sort(one.begin() , one.end());
      for(int i = 0 ; i < one.size() ; i++){
        State st = one[i];
        //cout<<st.idx<<", "<<st.a<<", "<<st.b<<endl;
        if(used[st.idx][1]){
          one.erase(one.begin() + i);
          i--;
        }
        else{
          if(st.a <= star){
            used[st.idx][0] = true;
            star += 1;
            res++;
            f = true;
            one.erase(one.begin() + i);
            i--;
            break;
          }
        }
      }
      if(!f){
        break;
      }
    }
    if(two.empty() && two2.empty()){
      printf("Case #%d: %d\n",t,res);
    }
    else{
      printf("Case #%d: Too Bad\n",t);
    }
  }
}
