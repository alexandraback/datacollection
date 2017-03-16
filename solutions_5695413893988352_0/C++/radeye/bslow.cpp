#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
const long long INF = 5000000000000000000LL ;
long long sdiff, cscore, jscore ;
string cs, js ;
string cres, jres ;
void recur(long long c, long long j, int at) {
  if (at == cs.size()) {
    int diff = abs(c-j) ;
    if (diff < sdiff || (diff == sdiff && (c < cscore || (c == cscore && j < jscore)))) {
      sdiff = diff ;
      cscore = c ;
      jscore = j ;
      cres = cs ;
      jres = js ;
    }
    return ;
  }
  if (cs[at] == '?') {
    for (int dc=0; dc<10; dc++) {
      cs[at] = '0' + dc ;
      recur(c, j, at) ;
    }
    cs[at] = '?' ;
    return ;
  }
  if (js[at] == '?') {
    for (int dc=0; dc<10; dc++) {
      js[at] = dc + '0' ;
      recur(c * 10 + cs[at] - '0', j * 10 + dc, at+1) ;
    }
    js[at] = '?' ;
    return ;
  }
  recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1) ;
}
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
      ll r = 33 ;
      cin >> cs >> js ;
      sdiff = INF ;
      cscore = INF ;
      jscore = INF ;
      recur(0, 0, 0) ;
      cout << "Case #" << kase << ": " << cres << " " << jres << endl ;
   }
}
