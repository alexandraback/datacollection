#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_PANCAKES = 9;

struct State {
  vector<int> s;
  int cost;
  string trace;

  bool operator<(State const& lhs) const {
    if(cost != lhs.cost)
      return cost < lhs.cost;
    return s < lhs.s;
  }

  void print() {
    cerr<<"C="<<cost<<" ";
    for(int i=0;i<s.size();++i) {
      cerr<<s[i]<<" ";
    }
    cerr<<endl;
  }
  void print_cout() {
    for(int i=0;i<s.size();++i) {
      cout<<s[i]<<" ";
    }
    cout<<endl;
  }

  void read() {
    s.clear();
    cost = 0;
    int d;
    cin>>d;
    for(int i=0;i<d;++i) {
       int pi;
       cin>>pi;
       s.push_back(pi);
    }
    sort(s.rbegin(), s.rend());
  }

  bool done() {
    return s.size() == 0;
  }

  State eat() {
    State news;
    news.cost = cost + 1;
    for(int i=0;i<s.size();++i) {
      if(s[i]>1) {
        news.s.push_back(s[i]-1);
      }
    }
    //news.trace = trace + " E";
    return news;
  }

  State split(int from, int to, int quantity) {
    State news;
    news.cost = cost + 1;
    for(int i=0;i<s.size();++i) {
      news.s.push_back(s[i]);
    }
    if(to == -1) {
      to = s.size();
      news.s.push_back(0);
    }
    news.s[from] -= quantity;
    news.s[to] += quantity;
    if(news.s[from]==0) {
      news.s.erase(news.s.begin()+from);
    }
    sort(news.s.rbegin(), news.s.rend());
    //news.trace = trace + " " + to_string(from) + ":" + to_string(to) + ":" + to_string(quantity);
    return news;
  }

  int greedy() {
    priority_queue<int> q;
    for(int i=0;i<s.size();++i) {
      q.push(s[i]);
    }

    int maxp = q.top();
    int best = q.top();
    for(int i=1;i<=maxp;++i) {
      int max = q.top();q.pop();
      int move = max/2;
      q.push(move);
      q.push(max-move);
      int res = q.top() + i;
      if(res < best) {
        best = res;
      }
    }
    return best;
  }

  bool dogreedy() {
    if(s[0] == 9) {
      if (s.size()==1) return false;
      if(s[1] == 6 || s[1] <= 3) return false;
    }
    return true;
  }

};

int runtc() {
  State s;
  s.read();
  s.print();

  if(s.dogreedy()) {
    return s.greedy();
  }

  queue<State> q;
  set<State> visited;
  q.push(s);
  while(!q.empty()) {
    State init = q.front(); q.pop();
    init.print();
    if(init.done()) {
      return init.cost;
    }

    { // eat
      State news = init.eat();
      if(visited.find(news) == visited.end()) {
        //cerr<<"-> E     "; news.print();
        q.push(news);
        visited.insert(news);
        if(news.done()) {
          if(s.greedy() != news.cost) {
            //cout<<"Different than greedy!"<<endl;
            //s.print_cout();
            //cout<<news.trace<<endl;
          }
          return news.cost;
        }
      } else {
        //cerr<<"-> E XXX "; news.print();
      }
    }

    for(int from=0;from<init.s.size();++from) {
      //cerr<<"FROM: "<<from<<endl;
      for(int to=-1;to<(signed)init.s.size();++to) {
        //cerr<<" TO:  "<<to<<endl;
        if(from==to) continue;
        for(int quantity=1;quantity<=init.s[from];++quantity) {
          //cerr<<"  Q:  "<<quantity<<endl;
          State news = init.split(from, to, quantity);
          if(visited.find(news) == visited.end()) {
            //cerr<<"-> S     "; news.print();
            q.push(news);
            visited.insert(news);
          } else {
            //cerr<<"-> S XXX "; news.print();
          }
        }
      }
    }

  }
  return 0;
}

int main(int argc, char** argv) {
  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    int res = runtc();
    cout<<"Case #"<<(i+1)<<": "<<res<<endl;
  }
}
