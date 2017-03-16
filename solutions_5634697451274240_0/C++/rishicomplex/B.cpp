#include <iostream>
#include <string>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;

void work(int index) {
  string S;
  cin >> S;
  S += "+";
  char prev = S[0];
  int i;
  int count = 0;
  for(i = 0; i < (int)S.length(); i++) {
    if(S[i] != prev) {
      count++;
      prev = S[i];
    }      
  }

  cout << "Case #" << index << ": ";
  cout << count;
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
