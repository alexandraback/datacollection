#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int result;

string a, b, resA, resB;

void getAnswer(string a, string b, int i) {
  if (i >= a.size()) {
    if (result > abs(atoi(a.c_str()) - atoi(b.c_str()))) {
      result = abs(atoi(a.c_str()) - atoi(b.c_str()));
      resA = a;
      resB = b;
    }
    return;
  }
  if(a[i] == '?' && b[i] == '?') {
    for(int j = '0'; j <= '9'; j++) {
      for (int k = '0'; k <= '9'; k++) {
        a[i] = j;
        b[i] = k;
        getAnswer(a, b, i + 1);
      }
    }
  } else if (a[i] == '?') {
    for(int j = '0'; j <= '9'; j++) {
      a[i] = j;
      getAnswer(a, b, i + 1);
    }
  } else if (b[i] == '?') {
    for(int j = '0'; j <= '9'; j++) {
      b[i] = j;
      getAnswer(a, b, i + 1);
    }
  } else {
    getAnswer(a, b, i + 1);
  }
  
}

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    cin >> a >> b;
    result = 0x3f3f3f3f;
    getAnswer(a, b, 0);
    printf("Case #%d: %s %s\n", T, resA.c_str(), resB.c_str());
  }
  return 0;
}
