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

const int q1 = 1;
const int qI = 2;
const int qJ = 3;
const int qK = 4;

int mul_table[5][5] = {
  { 0,   0,   0,   0,   0 },
  { 0,  q1,  qI,  qJ,  qK },
  { 0,  qI, -q1,  qK, -qJ },
  { 0,  qJ, -qK, -q1,  qI },
  { 0,  qK,  qJ, -qI, -q1 },
};

namespace std
{
  template <typename T>
  int sgn(T val)
  {
    return (T(0) < val) - (val < T(0));
  }

  int abs_fast(int a)
  {
    int mask = (a >> (sizeof(int) * CHAR_BIT - 1));
    return (a + mask) ^ mask;
  }
}

struct TestCase
{
  std::string init_s;
  int x;
  bool solution;

  TestCase(FILE* input)
  {
    int l;
    fscanf(input, "%d %d\n", &l, &x);
    init_s.reserve(l);
    for (int i = 0; i < l; ++i)
    {
      char c;
      fscanf(input, "%c", &c);
      init_s.push_back(c);
    }
  }

  int Mul(int a, int b)
  {
    int a_sign = std::sgn(a);
    int a_abs = a_sign * a;
    int b_sign = std::sgn(b);
    int b_abs = b_sign * b;
    return a_sign * b_sign * mul_table[a_abs][b_abs];
  }

  int Combine(std::vector<int8_t>& s, int begin, int end)
  {
    int result = s[begin];
    for (int i = begin + 1; i < end; ++i)
      result = Mul(result, s[i]);
    return result;
  }

  void Solve()
  {
    solution = false;
    std::vector<int8_t> s_template;
    s_template.reserve(init_s.size());
    for (int i = 0; i < init_s.size(); ++i)
    {
      switch (init_s[i])
      {
      case 'i':
        s_template.push_back(qI);
        break;
      case 'j':
        s_template.push_back(qJ);
        break;
      case 'k':
        s_template.push_back(qK);
        break;
      default:
        solution = false;
        return;
      }
    }
    std::vector<int8_t> s;
    s.reserve(x * s_template.size());
    for (int i = 0; i < x; ++i)
      s.insert(s.end(), s_template.begin(), s_template.end());
    if (s.size() < 3)
      return;
    int first = q1;
    for (int s1 = 1; s1 <= s.size() - 2; ++s1)
    {
      first = Mul(first, s[s1 - 1]);
      if (first != qI)
        continue;
      int second = q1;
      int third = Combine(s, s1, s.size());
      for (int s2 = s1 + 1; s2 <= s.size() - 1; ++s2)
      {
        second = Mul(second, s[s2 - 1]);
        third = Mul(-s[s2 - 1], third);
        if (second != qJ)
          continue;
        if (third != qK)
          continue;
        solution = true;
        return;
      }
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
        fprintf(output, "YES", testCases[i].solution);
      else
        fprintf(output, "NO", testCases[i].solution);
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