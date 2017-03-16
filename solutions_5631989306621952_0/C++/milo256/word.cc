#include <iostream>
#include <string>

using namespace std;

void process(string in, int length) {
  char big = in[0];
  int last = 0;
  for(int i = 1; i < length; i++) {
    if(big < in[i]) {
      big = in[i];
      last = i;
    }
  }
  if(last == 0) {
    for(int i = 0; i < length; i++) {
      if(big == in[i])
        cout << in[i];
    }
    for(int i = 0; i < length; i++) {
      if(big != in[i])
        cout << in[i];
    }
  }
  else {
    for(int i = last; i < length; i++) {
      if(big == in[i])
        cout << in[i];
    }
    process(in, last);
    for(int i = last; i < length; i++) {
      if(big != in[i])
        cout << in[i];
    }
  }
}

int main() {
  int x;
  cin >> x;
  for(int line = 1; line <= x; line++) {
    cout << "Case #" << line << ": ";

    string inp;
    cin >> inp;

    process(inp, inp.length());

    cout << endl;
  }
}