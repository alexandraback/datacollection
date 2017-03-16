#include <stdio.h>
#include <set>

using namespace std;

set<char> voyels = { 'a', 'e', 'i', 'o', 'u' };

char name[128];

bool isnth(char* str, int begin, int end, int n)
{
  int counter = 0;
  for (int i=begin; i != end; ++i) {
    if (voyels.find(str[i]) == voyels.end()) {
      counter++;
    } else {
      counter = 0;
    }
    if (counter == n) {
      return true;
    }
  }

  return false;
}

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    int n;
    scanf("%s %d", name, &n);

    int length = 0;
    for (; name[length] != '\0'; ++length);

    int counter = 0;
    for (int start=0; start<length; ++start) {
      for (int end=length; end>0; --end) {
        if (start >= end) {
          break;
        }
        counter += isnth(name, start, end, n);
      }
    }

    printf("Case #%d: %d\n", t, counter);
  }

  return 0;
}
