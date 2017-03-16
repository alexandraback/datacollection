#include <iostream>
#include <vector>
using namespace std;

void fill(vector<int> &a, int n) {
  while(n) {
    a[n%10] = 1;
    n /= 10;
  }
}

int done(vector<int> &a) {
  for(int i=0;i<10;i++) if (a[i] == 0) return 0;
  return 1;
}

int main() {
  int c;
  cin >> c;
  for(int cn=1;cn<=c;cn++) {
    int st = 0, it;
    cin >> it;
    if (it == 0) {
      cout << "Case #" << cn << ": INSOMNIA" << endl;
      continue;
    }
    int i = it;
    vector<int> a(10,0);
    do {
      ++st;
      fill(a,it);
      if (done(a)) break;
      it += i;
    } while(true);
    cout << "Case #" << cn << ": " << it << endl;
  }
}
