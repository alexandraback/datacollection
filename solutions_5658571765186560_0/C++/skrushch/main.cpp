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

  void Solve()
  {
    solution = false;
    if ((r * c) % x != 0)
      return;
    switch (x)
    {
    case 1:
    case 2:
      solution = true;
      break;
    case 3:
      solution = (r >= 2) && (c >= 2);
      break;
    case 4:
      solution = (r >= 3) && (c >= 3);
      break;
    }
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