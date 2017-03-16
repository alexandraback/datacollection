#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int mem[10000000];

int MAX=10000000;

int reverse(int n) {
  int n2=0;
  while(n) {
    n2=n2*10+n%10;
    n=n/10;
  }
  return n2;
}

void init() {
  queue<int> q;
  q.push(1);
  mem[1]=1;
  while(q.size()) {
    int val=q.front();
    q.pop();
    if(val+1<MAX)
    if(mem[val+1]==0) {
      q.push(val+1);
      mem[val+1]=mem[val]+1;
    }
    int val2=reverse(val);
    if(val2<MAX)
    if(mem[val2]==0) {
      q.push(val2);
      mem[val2]=mem[val]+1;
    }
  }
}

int doit(int N) {
  return mem[N];
}

int main() {
  int tests;
  cin >> tests;
  init();
  for(int i = 0; i < tests; i++) {    
    int N;
    cin >> N;
    cout << "Case #" << (i+1) << ": " << doit(N) << endl;
  }
  return 0;
}
