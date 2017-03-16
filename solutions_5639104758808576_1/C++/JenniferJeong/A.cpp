#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {

  int TC;

  cin >> TC;

  for (int tc = 1; tc <= TC; tc++) {
    int s_max;
    string shyness;

    cin >> s_max;
    cin >> shyness;

    int now = 0;
    int result = 0;
    for (int i = 0; i < s_max+1; i++) {
      if (shyness[i] != '0') {
	int added = 0;
	if (now < i) added += (i - now);
	now += (added + (shyness[i] - '0'));
	result += added;
      }
    }

    printf("Case #%d: %d\n", tc, result);
  }

  return 0;
}
