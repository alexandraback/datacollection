#include <iostream>
#include <vector>
#include "abstract_solver.h"
using namespace std;

class CaseSolver : public AbstractCaseSolver
{
public:
  virtual void ReadInput() override final
  {
    cin >> stack;
  }
  
  virtual void Solve() override final
  {
    int n = stack.size() - 1;
    int res = 0;

    Clean(n);
    while (n >= 0)
    {
      if (n == 0)
      {
        ++res;
        n = -1;
      }
      else if (stack[0] == '-')
      {
        ++res;
        for (int i = 0; i <= n; ++i)
          Flip(i);
        Clean(n);
      }
      else
      {
        res += 2;
        for (int i = 0; stack[i] == '+'; ++i)
          Flip(i);
        for (int i = 0; i <= n; ++i)
          Flip(i);
        Clean(n); 
      }
    }
    out << res << endl;
  }

  void Clean(int& n)
  {
    while (n >= 0 && stack[n] == '+')
      --n;
  }

  void Flip(int i)
  {
    stack[i] = stack[i] == '+' ? '-' : '+';
  }

private:
  string stack;
};

int main()
{
  int cases;
  cin >> cases;
  ProblemSolver<CaseSolver> solver(cases);
}
