#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)

int main(){
  string v[6] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		 "de kr kd eoya kw aej tysr re ujdr lkgc jv",
		 "our language is impossible to understand",
		 "there are twenty six factorial possibilities",
		 "so it is okay if you want to just give up"
  };

  map <char, char> mp;
  mp['y'] = 'a';
  mp['e'] = 'o';
  mp['q'] = 'z';
  mp['z'] = 'q';
  
  REP(i,3) REP(j, v[i].length()) mp[v[i][j]] = v[i+3][j];

  int n;
  string str;
  cin >> n;
  getline(cin, str);
  REP(i, n){
    getline(cin, str);
    REP(j, str.length()) str[j] = mp[str[j]];
    printf("Case #%d: ", i+1);
    cout << str << endl;
  }

  return 0;
}
