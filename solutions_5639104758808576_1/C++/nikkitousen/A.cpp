#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
      cout << "Case #" << caso+1 << ": ";

      int Sm;
      string s;
      cin >> Sm >> s;

      int acum = 0, friends = 0;

      REP(i, SZ(s)) {
        int d = s[i]-'0';
        if(acum + friends < i) {
          friends = i - acum;
        }
        acum += d;
      }

      cout << friends << endl;

  }
}
