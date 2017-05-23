// The last word

#include <iostream>
#include <cstdio>
using namespace std;

string solve(const string &str) {
  const int LEN = str.length();
  string result({str[0]});

  for (int i = 1; i < LEN; ++i) {
    if (str[i] >= result[0]) {
      result = str[i] + result;
    } else {
      result = result + str[i];
    }
  }

  return result;
}

int main()
{
  int N;
  string str;

  cin >> N;

  for (int i = 1; i <= N; ++i) {
    cin >> str;
    cout << "Case #" << i << ": " << solve(str) << endl;
  }
  return 0;
}

