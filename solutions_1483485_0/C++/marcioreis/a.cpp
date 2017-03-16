/*
  codejam 2012
  marcioreis
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
  int t;
  int caso = 1;
  char c, v[300];
  v['a'] = 'y';
  v['b'] = 'h';
  v['c'] = 'e';
  v['d'] = 's';
  v['e'] = 'o';
  v['f'] = 'c';
  v['g'] = 'v';
  v['h'] = 'x';
  v['i'] = 'd';
  v['j'] = 'u';
  v['k'] = 'i';
  v['l'] = 'g';
  v['m'] = 'l';
  v['n'] = 'b';
  v['o'] = 'k';
  v['p'] = 'r';
  v['q'] = 'z';
  v['r'] = 't';
  v['s'] = 'n';
  v['t'] = 'w';
  v['u'] = 'j';
  v['v'] = 'p';
  v['w'] = 'f';
  v['x'] = 'm';
  v['y'] = 'a';
  v['z'] = 'q';
  v[' '] = ' ';
  
  cin >> t;
  while (t--) {
    cout<<"Case #"<<caso++<<": ";
    scanf (" %c", &c);
    while (c != '\n') {
      cout << v[c];
      scanf ("%c", &c);
    }
    cout << endl;
  }
  return 0;
}

