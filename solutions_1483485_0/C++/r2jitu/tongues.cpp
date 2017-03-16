#include <iostream>
#include <string>

using namespace std;

char mapping[] = {
  'y', // a
  'h', // b
  'e', // c
  's', // d
  'o', // e
  'c', // f
  'v', // g
  'x', // h
  'd', // i
  'u', // j
  'i', // k
  'g', // l
  'l', // m
  'b', // n
  'k', // o
  'r', // p
  'z', // q
  't', // r
  'n', // s
  'w', // t
  'j', // u
  'p', // v
  'f', // w
  'm', // x
  'a', // y
  'q'  // z
};

int main() {
  int T;
  string str;

  cin >> T;
  getline(cin, str);

  for (int i=0; i<T; i++) {
    cout << "Case #" << i+1 << ": ";

    getline(cin, str);
    for (int j=0; j<str.length(); j++) {
      if (str[j] == ' ') cout << ' ';
      else cout << mapping[str[j]-'a'];
    }

    cout << endl;
  }
}

