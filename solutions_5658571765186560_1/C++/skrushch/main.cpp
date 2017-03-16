#include <cstdint>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>

struct TestCase
{
  int x;
  int r;
  int c;
  bool solution;

  TestCase(FILE* input)
  {
    fscanf(input, "%d %d %d\n", &x, &r, &c);
  }

  bool InternalSolve()
  {
    if (r * c < x)
      return false;
    if ((r * c) % x != 0)
      return false;
    if (x <= 2)
      return true;
    if (x == 3)
      return (r > 2) && (c > 1) || (r > 1) && (c > 2);
    if (x == 4)
      return (r > 2) && (c > 2);
    if (x == 5)
      return (r > 2) && (c > 4) || (r > 4) && (c > 2);
    if (x == 6)
      return (r > 3) && (c > 5) || (r > 5) && (c > 3);
    return false;
  }

  void Solve()
  {
    solution = InternalSolve();
  }

  bool Check()
  {
    return true;
  }
};

void main()
{
  std::srand(std::time(0));
  FILE* input = fopen("io/input.txt", "rt");
  int t;
  fscanf(input, "%d\n", &t);
  std::vector<TestCase> testCases;
  testCases.reserve(t);
  for (int i = 0; i < t; ++i)
    testCases.push_back(TestCase(input));
  fclose(input);
  FILE* output = fopen("io/output.txt", "wt");
  for (int i = 0; i < t; ++i)
  {
    testCases[i].Solve();
    fprintf(output, "Case #%d: ", i + 1);
    if (testCases[i].Check())
    {
      if (testCases[i].solution)
        fprintf(output, "GABRIEL", testCases[i].solution);
      else
        fprintf(output, "RICHARD", testCases[i].solution);
      fprintf(output, "\n");
    }
    else
    {
      fprintf(output, "Error!\n");
      break;
    }
  }
  fclose(output);
}