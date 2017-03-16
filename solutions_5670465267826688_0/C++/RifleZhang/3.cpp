#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

string s1 = "YES", s2 = "NO"; 
  int m[5][5] = {
    0,0,0,0,0,
    0,1,2,3,4,
    0,2,-1,4,-3,  
    0,3,-4,-1,2,
    0,4,3,-2,-1};

void print (string  s, int tmp) {
  cout << "Case #" << tmp << ": " << s << endl;
}

int turn (char x) {
  switch(x) {
  case 'i': 
    return 2;
  case 'j':
    return 3;
  case 'k':
    return 4;
  }
}
void solve (int tmp) {
  int l, x;
  string s = "", ss;
  int a[200000];
  cin >> l >> x;
  cin >> ss;
  a[0] = turn (ss[0]);
  for (int i=1; i<=x; i++)
    s += ss;
   int len = x * l, pi=-1, pj=-1;
  for (int i=1; i<len; i++)
    a[i] = (a[i-1]/abs(a[i-1]))*m[abs(a[i-1])][turn(s[i])];
  // for (int i=0; i<len; i++) cout << a[i] << " ";

  if (a[len-1] != -1) {
    print (s2, tmp);
    return;
  }
  for (int i=0; i<len; i++)
    if (a[i] == 2) {
      pi = i;
      break;
    }

  for (int i=len-1; i>0; i--)
    if (a[i] == 4) {
      pj = i;
      break;
    }
  if (pi == -1 || pj == -1) {print (s2, tmp); return;}
  if (pi < pj) print (s1, tmp);
  else print (s2, tmp);

    
}

int main () {
  int t, tmp = 0;

  
  cin >> t;
  while (t) {
    t--;
    tmp++;
    solve (tmp);
    // cout << "next ---------------------------------" << endl;
  }
}
