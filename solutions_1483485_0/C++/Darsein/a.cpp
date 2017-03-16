#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

map<char,char> m;

int main(){
  int testcase;

  m[' '] = ' ';
  m['a'] = 'y';
  m['b'] = 'h';
  m['c'] = 'e';
  m['d'] = 's';
  m['e'] = 'o';
  m['f'] = 'c';
  m['g'] = 'v';
  m['h'] = 'x';
  m['i'] = 'd';
  m['j'] = 'u';
  m['k'] = 'i';
  m['l'] = 'g';
  m['m'] = 'l';
  m['n'] = 'b';
  m['o'] = 'k';
  m['p'] = 'r';
  m['q'] = 'z';
  m['r'] = 't';
  m['s'] = 'n';
  m['t'] = 'w';
  m['u'] = 'j';
  m['v'] = 'p';
  m['w'] = 'f';
  m['x'] = 'm';
  m['y'] = 'a';
  m['z'] = 'q';

  cin >> testcase;
  cin.ignore();
  for(int casenum=1;casenum<=testcase;casenum++){
    string ans;
    getline(cin,ans);
    for(int i=0;i<(int)ans.size();i++)ans[i] = m[ans[i]];

    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
