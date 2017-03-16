#include <iostream>
#include <vector>
#include "abstract_solver.h"
using namespace std;

class CaseSolver : public AbstractCaseSolver
{
public:
  virtual void ReadInput() override final
  {
    cin >> K >> C >> S;
  }

  virtual void Solve() override final
  {
    int needed = K / C + (K % C == 0 ? 0 : 1);
    if (S >= needed)
    {
      vector<long long> positions;
      for (int i = 0; i < needed; ++i)
      {
        long long x = i * min(K, C) + 1;
        long long position_in_original = x;
        long long previous = x - 1;
        for (int j = 1; j < C; ++j)
        {
          if (position_in_original < K)
            ++position_in_original;
          x = previous * K + position_in_original;
          previous = x - 1;
        }
        positions.push_back(x);
      }

      for (int i = 0; i < positions.size(); ++i)
      {
        if (i > 0)
          out << " ";
        out << positions[i];
      }
      out << endl;
    }
    else
      out << "IMPOSSIBLE" << endl;
  }

private:
  long long K;
  long long C;
  long long S;
};

int main()
{
  int cases;
  cin >> cases;
  ProblemSolver<CaseSolver> solver(cases);
}
