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
void recur(long long c, long long j, int at, int jsup) {
  if (jsup && j < c)
    return ;
  if (!jsup && j > c)
    return ;
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
  // they are already different; minimize the diff
  if (c != j) {
    if (cs[at] == '?') {
      cs[at] = jsup ? '9' : '0' ;
      recur(c, j, at, jsup) ;
      cs[at] = '?' ;
      return ;
    }
    if (js[at] == '?') {
      js[at] = jsup ? '0' : '9' ;
      recur(c, j, at, jsup) ;
      js[at] = '?' ;
      return ;
    }
    recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1, jsup) ;
    return ;
  }
  // same so far.  max diff is one, and there's a specific direction.
  // if both are ?, then we use 0 or 1, that's it.
  if (cs[at] == '?' && js[at] == '?') {
    cs[at] = '0' ;
    js[at] = '0' ;
    recur(c*10, j*10, at+1, jsup) ;
    if (jsup) {
      js[at]++ ;
    } else {
      cs[at]++ ;
    }
    recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1, jsup) ;
    cs[at] = '?' ;
    js[at] = '?' ;
    return ;
  }
  // if one is ? and the other isn't, we try same, then try with one >.
  if (cs[at] == '?' || js[at] == '?') {
    int oldc = cs[at] ;
    int oldj = js[at] ;
    if (cs[at] == '?') {
      cs[at] = oldj ;
    } else {
      js[at] = oldc ;
    }
    recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1, jsup) ;
    if (oldj == '?') {
      if (jsup) {
	js[at]++ ;
      } else {
	js[at]-- ;
      }
    } else {
      if (jsup) {
	cs[at]-- ;
      } else {
	cs[at]++ ;
      }
    }
    if ('0' <= cs[at] && cs[at] <= '9' &&
	'0' <= js[at] && js[at] <= '9')
      recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1, jsup) ;
    cs[at] = oldc ;
    js[at] = oldj ;
    return ;
  }
  recur(c*10+cs[at]-'0', j*10+js[at]-'0', at+1, jsup) ;
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
      recur(0, 0, 0, 1) ;
      recur(0, 0, 0, 0) ;
      cout << "Case #" << kase << ": " << cres << " " << jres << endl ;
   }
}
