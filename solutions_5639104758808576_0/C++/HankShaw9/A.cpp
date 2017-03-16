#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int s_max; 
    scanf("%d", &s_max);
    std::string str;
    int added = 0;
    int stand = 0;
    for (int j = 0; j <= s_max;) {
      char c;
      scanf("%c", &c);
      if (c >= '0' && c <= '9') {
        int cnt = static_cast<int>(c - '0');
        // fprintf(stderr, "j = %d, cnt = %d, stand = %d\n", j, cnt, stand);
        if (added < j - stand)
          added = j - stand;
        ++j;
        stand += cnt;
      }
    }
    // fprintf(stderr, "\n");
    printf("Case #%d: %d\n", i + 1, added);
  }
}
