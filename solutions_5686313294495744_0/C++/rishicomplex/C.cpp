#include <iostream>
#include <string>
#include <map>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;


map<string, int> firsts;
map<string, int> seconds;

struct double_string {
  string first;
  string second;
};



double_string inp[20];

int N;

int setBit(int no, int pos) {
  int ret = (no | (1 << pos));
  return ret;
}

int clearBit(int no, int pos) {
  return no & (~(1 << pos));
}

bool moreThanOne(map<string, int> mymap, string s) {
  if(mymap[s] > 1) return true;
  return false;
}

void incrementHash(map<string, int> &mymap, string s) {
  if(mymap.find(s) == mymap.end()) {
    mymap[s] = 1;
  }
  else mymap[s] += 1;
}


int getAns(int sofar, int consider) {
  if(consider == N) return 0;
  string f = inp[consider].first;
  string s = inp[consider].second;
  int a1 = -1, a2 = -1;
  if(moreThanOne(firsts, f) && moreThanOne(seconds, s)) {
    sofar = setBit(sofar, consider);
    firsts[f] -= 1;
    seconds[s] -= 1;
    a1 = getAns(sofar, consider + 1) + 1;
    firsts[f] += 1;
    seconds[s] += 1;
    
  }
  sofar = clearBit(sofar, consider);
  a2 = getAns(sofar, consider + 1);
  if(a1 > a2) return a1;
  return a2;
  
  
}


void work(int index) {
  firsts.clear();
  seconds.clear();
 
  int i;
  cin >> N;
  string temp;
  for(i = 0; i < N; i++) {
    cin >> inp[i].first;
    incrementHash(firsts, inp[i].first);
    cin >> inp[i].second;
    incrementHash(seconds, inp[i].second);
    
  }

  int fakes = getAns(0, 0);
  

  cout << "Case #" << index << ": ";
  cout << fakes;
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
