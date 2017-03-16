/*
  codejam 2012
  marcioreis
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>

using namespace std;

int geral (int A, int B) {
  if (B < 10)
    return 0;
  int a, b, conta, x = B;
  int casas;
  
  casas = 1;
  for (a = A; a/10; a = a/10)
    casas++;
  
  conta = 0;
  while (x > A) {
    set <int> s;
    b = x%10*pow(10,casas-1)+x/10;
    for (int i = 0; i < casas; i++) {
      if (b >= A && b <= B && b < x)
        s.insert(b);
      b = b%10*pow(10,casas-1)+b/10;
    }
    conta += s.size();
    x--;
  }
  return conta;
}


int main () {
  int t, caso = 1;
  int A, B;
  
  cin >> t;
  while (t--) {
    cin >> A >> B;
    cout << "Case #" << caso++ << ": " << geral (A, B) << endl;
  }
  return 0;
}

