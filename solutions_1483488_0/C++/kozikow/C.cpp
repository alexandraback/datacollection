#include <iostream>
#include <deque>
using namespace std;

deque<int> rozloz(int x) {
  deque<int> sol;
  while(x) {
    sol.push_front(x%10);
    x /= 10;
  }
  return sol;
}

int zloz(const deque<int>& deq) {
  int sol = 0;
  for(int i=0; i<deq.size(); i++) {
    sol *= 10;
    sol += deq[i];
  }
  return sol;
}

int len(int x) {
  int sol = 0;
  while(x) {
    sol++;
    x /= 10;
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(0);
  int tests;
  cin >> tests;
  for(int t=1; t<=tests; t++) {
    int A, B;
    cin >> A >> B;
    int ile = len(B);
    int sol = 0;
    for(int i=A; i<=B; i++) {
      deque<int> deq = rozloz(i); 
      for(int j=1; j<ile; j++) {
        deq.push_front(deq.back());
        deq.pop_back();        
        int y = zloz(deq);
        if(y == i)
          break;
        if(A <= y && y <= B)
          sol++;
      }
    }
    cout << "Case #" << t << ": " << sol/2 << '\n';
  }
  
  return 0;
}