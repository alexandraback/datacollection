#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int T;
  scanf("%d ", &T);

  string str;
  char lit[30] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

  for (int i = 1; i <= T; i++) {
    getline(cin, str);

    printf("Case #%d: ", i);
    for (int i = 0; str[i]; i++) {
      if (str[i] == ' ') { printf(" "); }
      else { printf("%c", lit[str[i]-'a']); }
    }
    printf("\n");
  }
  return 0;
}
