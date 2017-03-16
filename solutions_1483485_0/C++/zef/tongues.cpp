#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char map[256];

void init_map()
{
  map[' '] = ' ';
  map['a'] = 'y';
  map['b'] = 'h';
  map['c'] = 'e';
  map['d'] = 's';
  map['e'] = 'o';
  map['f'] = 'c';
  map['g'] = 'v';
  map['h'] = 'x';
  map['i'] = 'd';
  map['j'] = 'u';
  map['k'] = 'i';
  map['l'] = 'g';
  map['m'] = 'l';
  map['n'] = 'b';
  map['o'] = 'k';
  map['p'] = 'r';
  map['q'] = 'z';
  map['r'] = 't';
  map['s'] = 'n';
  map['t'] = 'w';
  map['u'] = 'j';
  map['v'] = 'p';
  map['w'] = 'f';
  map['x'] = 'm';
  map['y'] = 'a';
  map['z'] = 'q';
}

int main()
{
  init_map();

  int ncases;
  string line;

  cin >> ncases;
  getline(cin, line);

  for (int caseno = 1; caseno <= ncases; caseno++) {
    getline(cin, line);
    printf("Case #%i: ", caseno);
    for (int i = 0; i < line.length(); i++)
      printf("%c", map[line[i]]);
    printf("\n");
  }
}
