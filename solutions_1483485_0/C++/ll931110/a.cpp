
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string s[6] = {"ejpmysljylckdkxveddknmcrejsicpdrysi",
"rbcpcypcrtcsradkhwyfrepkymveddknkmkrkcd",
"dekrkdeoyakwaejtysrreujdrlkgcjv",
"ourlanguageisimpossibletounderstand",
"therearetwentysixfactorialpossibilities",
"soitisokayifyouwanttojustgiveup"};

map<char,char> mp;

int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < s[i].size(); j++) mp[s[i][j]] = s[i + 3][j];
  mp['y'] = 'a';
  mp['e'] = 'o';
  mp['q'] = 'z';
  mp['z'] = 'q';

  int T;
  scanf("%d\n", &T);
  for (int it = 1; it <= T; it++) {
    char text[105];
    gets(text);
    for (int i = 0; i < strlen(text); i++)
      if (mp.count(text[i])) text[i] = mp[text[i]];
    printf("Case #%d: %s\n", it, text);
  }
}
