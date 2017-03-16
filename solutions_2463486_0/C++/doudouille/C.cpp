#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int T[128] = {0};
vector<string> P;

void add_palindrom() {
  string S(100, '0');
  for(int i = 0; i < 100; i++) {
    int sum = 0;
    for(int j = 0; j <= i; j++) sum += T[j]*T[i-j];
    S[99-i] = '0'+sum;
  }
  P.push_back(S);
}

bool valid(int n) {
  for(int i = 0; i <= 2*n; i++) {
    int sum = 0;
    for(int j = 0; j <= i; j++) sum += T[j]*T[i-j];
    if(sum > 9) return false;
  }
  return true;
}

void compute(int n, int k) {
  if(2*k > n) {
    add_palindrom();
    return;
  }
  int min = 0; 
  if(k == 0) min = 1;
  for(int c = min; c <= 9; c++) {
    T[k] = T[n - k] = c;
    if(!valid(n)) break;
    compute(n, k+1);
  }
  T[k] = T[n - k] = 0;
}

int main() {
  for(int n = 0; n < 50; n++) compute(n, 0);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    string A, B;
    cin >> A >> B;
    A = string(100 - A.length(), '0') + A;
    B = string(100 - B.length(), '0') + B;
    int nb = 0;
    for(int i = 0; i < P.size(); i++) if(P[i] >= A && P[i] <= B) nb++;
		cout << "Case #" << t << ": " << nb << endl;
  }
}
