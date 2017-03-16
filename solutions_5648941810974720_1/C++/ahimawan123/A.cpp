#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define N 27

int elim(int a[], char c, string token) {
  c -= 'A';
  int ret = a[c];
  for (int i = 0; i < token.length(); i++) {
    a[token[i] - 'A'] -= ret;
  }
  return ret;
}

int main() {
  int cases;
  string s;
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    printf("Case #%d: ", cas);
    cin >> s;
    int a[N];
    int sol[11];
    memset(sol, 0, sizeof(sol));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.length(); i++) {
      a[s[i]-'A']++;
    }
    sol[0] = elim(a, 'Z', "ZERO");
    sol[2] = elim(a, 'W', "TWO");
    sol[4] = elim(a, 'U', "FOUR");
    sol[5] = elim(a, 'F', "FIVE");
    sol[6] = elim(a, 'X', "SIX");
    sol[7] = elim(a, 'S', "SEVEN");
    sol[8] = elim(a, 'G', "EIGHT");
    sol[9] = elim(a, 'I', "NINE");
    sol[1] = elim(a, 'O', "ONE");
    sol[3] = elim(a, 'R', "THREE");
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < sol[i]; j++) {
	cout << i;
      }
    }
    cout << endl;
  }
  return 0;
}
