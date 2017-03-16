
#include <iostream>
#include "Solve.h"


using namespace std;

int main(int argc, char **argv, char** envp)
{


  int n;
  cin >> n;
  cin.ignore(100, '\n');

  int c;
  for (c = 0; c < n; c++)
    {
      cout << "Case #" << c+1 << ":";
      Solve* s = new Solve(cin, cout);
      s->solveOne();
      delete(s);
    }

}
