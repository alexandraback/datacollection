#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;

// state: 0 -> C==J, 1 -> C > J, 2 -> C < J
ll memo[3][20];
char bestc[3][20], bestj[3][20];

string C, J;
int n;

const ll INF = (1LL << 62);

int nextstate(int state, char c1, char c2)
{
  if (state != 0) {
    return state;
  }
  if (c1 > c2) return 1;
  if (c1 < c2) return 2;
  return 0;
}

ll ipow10(int k)
{
  ll a = 1;
  for (int i = 0; i < k; i++) {
    a *= 10;
  }
  return a;
}

ll prefix(char c, char j, int ind)
{
  return ((ll)c - j) * ipow10(n-1-ind);
}

ll go(int state, int ind)
{
  ll &ans = memo[state][ind];
  if (ans != INF)
    return ans;
  if (ind == n) 
    return ans = 0;

  if (C[ind] != '?' && J[ind] != '?') {
    bestc[state][ind] = C[ind];
    bestj[state][ind] = J[ind];
    return ans = prefix(C[ind], J[ind], ind) +
      go(nextstate(state, C[ind], J[ind]), ind+1);
  } else if (C[ind] == '?' && J[ind] != '?') {
    if (state == 1) {
      bestc[state][ind] = '0';
      bestj[state][ind] = J[ind];
      return ans = prefix('0', J[ind], ind) +
	go(nextstate(state, '0', J[ind]), ind+1);
    } else if (state == 2) {
      bestc[state][ind] = '9';
      bestj[state][ind] = J[ind];
      return ans = prefix('9', J[ind], ind) +
	go(nextstate(state, '9', J[ind]), ind+1);
    } else {
      ll temp = INF;
      char bestcc, bestjj;
      for (char Cchar = J[ind]-1; Cchar <= J[ind]+1; Cchar++) {
	if (Cchar >= '0' && Cchar <= '9') {
	  ll t = go(nextstate(state, Cchar, J[ind]), ind+1);
	  t += prefix(Cchar, J[ind], ind);
	  if (llabs(t) < llabs(temp)) {
	    temp = t;
	    bestcc = Cchar;
	    bestjj = J[ind];
	  }
	}
      }
      bestc[state][ind] = bestcc;
      bestj[state][ind] = bestjj;
      return ans = temp;
    }
  } else if (C[ind] != '?' && J[ind] == '?') {
    if (state == 1) {
      bestc[state][ind] = C[ind];
      bestj[state][ind] = '9';
      return ans = prefix(C[ind], '9', ind) +
	go(nextstate(state, C[ind], '9'), ind+1);
    } else if (state == 2) {
      bestc[state][ind] = C[ind];
      bestj[state][ind] = '0';
      return ans = prefix(C[ind], '0', ind) +
	go(nextstate(state, C[ind], '0'), ind+1);
    } else {
      ll temp = INF;
      char bestcc, bestjj;
      for (char Jchar = C[ind]-1; Jchar <= C[ind]+1; Jchar++) {
	if (Jchar >= '0' && Jchar <= '9') {
	  ll t = go(nextstate(state, C[ind], Jchar), ind+1);
	  t += prefix(C[ind], Jchar, ind);
	  if (llabs(t) < llabs(temp)) {
	    temp = t;
	    bestcc = C[ind];
	    bestjj = Jchar;
	  }
	}
      }
      bestc[state][ind] = bestcc;
      bestj[state][ind] = bestjj;
      return ans = temp;
    }
  } else {
    if (state == 1) {
      bestc[state][ind] = '0';
      bestj[state][ind] = '9';
      return ans = prefix('0', '9', ind) +
	go(nextstate(state, '0', '9'), ind+1);
    } else if (state == 2) {
      bestc[state][ind] = '9';
      bestj[state][ind] = '0';
      return ans = prefix('9', '0', ind) +
	go(nextstate(state, '9', '0'), ind+1);
    } else {
      ll temp = INF;
      char bestcc, bestjj;
      for (char Cchar = '0'; Cchar <= '1'; Cchar++) {
	for (char Jchar = '0'; Jchar <= '1'; Jchar++) {
	  ll t = go(nextstate(state, Cchar, Jchar), ind+1);
	  t += prefix(Cchar, Jchar, ind);
	  if (llabs(t) < llabs(temp)) {
	    temp = t;
	    bestcc = Cchar;
	    bestjj = Jchar;
	  }
	}
      }
      bestc[state][ind] = bestcc;
      bestj[state][ind] = bestjj;
      return ans = temp;
    }
  }
}

void trace(int state, int ind, string &s1, string &s2)
{
  if (ind == n) return;
  char cc = bestc[state][ind];
  char jc = bestj[state][ind];
  s1 += cc;
  s2 += jc;

  trace(nextstate(state, cc, jc), ind+1, s1, s2);


}

void solve()
{
  cin >> C >> J;
  n = C.length();
  
  for (int i = 0; i < 3; i++) {
    fill(memo[i], memo[i]+20, INF);
  }
  go(0, 0);

  string s1, s2;
  trace(0,0, s1, s2);
  cout << s1 << ' ' << s2 << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
