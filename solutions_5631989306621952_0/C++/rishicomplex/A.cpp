#include <iostream>
#include <string>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;

void handleChar(char c, string &a) {
  int i;
  char start = c;
  for(i = 0; i < (int)a.length(); i++) {
    if(a[i] != c) {
      start = a[i];
      break;
    }
  }
  if(start < c) a.insert(i, string(1, c));
  else a += c;
}

void work(int index) {
  string s;
  cin >> s;
  int i;
  string a;
  for(i = 0; i < (int)s.length(); i++) {
    handleChar(s[i], a);
  }

  cout << "Case #" << index << ": ";
  cout << a;
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
