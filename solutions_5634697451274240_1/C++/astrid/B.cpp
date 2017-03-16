#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

typedef long long int ll;

int main () {
  ll n;
  ll cur;
  ll curcp;
  int seen[10];
  int testnb;
  int ok = 0;
  
  cin >> testnb;
  
  for (int test = 1; test <= testnb; test ++) {
    string S;
    cin >> S;
    int n = S.size();
    int sol = 0;
    FOR(i,1,n) if (S[i] != S[i-1]) sol ++;
    if (S[n-1] == '-') sol ++;
    cout << "Case #" << test << ": " << sol << endl;
  }
  return (1);
}
