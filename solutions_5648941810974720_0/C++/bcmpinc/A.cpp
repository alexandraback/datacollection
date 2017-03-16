#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;

char in[2005];
int counts[256];
int xx[15];
char result[2005];

void foo(char id, int v, const char * name) {
  int x = counts[(int)id];
  xx[v] = x;
  for (const char * s = name; *s; s++) {
    counts[(int)*s]-=x;
  }  
}

void dostep() {
  cin >> in;
  fill(counts, counts+256, 0);
  for (char * s = in; *s; s++) {
    counts[(int)*s]++;
  }  
  
  foo('Z',0,"ZERO");
  foo('W',2,"TWO");
  foo('G',8,"EIGHT");
  foo('H',3,"THREE");
  foo('X',6,"SIX");
  foo('U',4,"FOUR");
  foo('O',1,"ONE");
  foo('F',5,"FIVE");
  foo('S',7,"SEVEN");
  foo('I',9,"NINE");

  char * r = result;
  for (int j=0; j < 10; j++) {
    for (int i=0; i < xx[j]; i++) {
      *r++ = j + '0';
    }
  }
  *r++ = 0;
  cout << result << endl;
  for (int i=0; i<256; i++) {
    if (counts[i] > 0) {
      fprintf(stderr, "Error: '%c' %d\n", i, counts[i]);
    }
  }
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ": ";
    dostep();
  }
  return 0;
}
 
