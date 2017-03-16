#include <iostream>
#include <vector>

#include "abstract_solver.h"

using namespace std;

class CaseSolver : public AbstractCaseSolver
{
public:
  virtual void ReadInput() override final
  {
    cin >> N;
  }

  virtual void Solve() override final
  {
    if (N == 0)
      out << "INSOMNIA" << endl;
    else
    {
      int current = N;
      vector<bool> seen(10, false);

      do
      {
        for (char c : to_string(current))
          seen[c - '0'] = true;
        current += N;
      } while (seen != vector<bool>(10, true));

      out << current - N << endl;
    }
  }

private:
  int N;
};

int main()
{
  int cases;
  cin >> cases;
  ProblemSolver<CaseSolver> solver(cases);
}
