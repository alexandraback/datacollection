#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

int recycle(string n, string B);
string leftShift(string s);

int main ()
{
  int lines;
  cin >> lines;
  string str;
  getline(cin, str);
  string A, B;
  for (int i=0; i<lines; i++) {
    cin >>A>>B;
    getline(cin, str);
    string n = A;
    int result = 0;
    while (n<B) {
      result += recycle(n, B);
      long nValue = atol(n.c_str());
      nValue++;
      stringstream ss;
      ss << nValue;
      n = ss.str();
    }
    cout << "Case #"<<i+1<<": "<<result<<endl;
  }
  return 0;
}

int recycle(string n, string B) {
  int cnt = 0;
  string m = n;
  int length = n.size();
  string record[length];
  int idx = 0;
  for (int i=0; i<length-1; i++) {
    m = leftShift(m);
    bool exist = false;
    if (n<m && m<=B) {
      for (int j=0; j<cnt; j++) {
        if (record[j]==m) {
          exist = true;
        }
      }
      if (!exist) {
        cnt++;
        record[idx++] = m;
      }
    }
  }
  return cnt;
}
string leftShift(string s) {
  char head = s[0];
  s = s.substr(1);
  s += head;
  return s;
}
