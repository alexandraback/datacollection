#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    string s;
    cin >> s;

    for (; !s.empty() && s.back() == '+'; s.pop_back());
    int rje = 0;
    if (!s.empty()) {
      rje = 1;
      int len = (int) s.size();
      for (int i=0; i<len-1; i++)
        if (s[i] != s[i+1])
          rje++;
    }

    printf("Case #%d: %d\n", br, rje);
  }

  return 0;
}

