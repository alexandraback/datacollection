#include <cstdint>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
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
  int64_t x;
  bool solution;

  TestCase(FILE* input)
  {
    int l;
    fscanf(input, "%d %I64d\n", &l, &x);
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

  void Solve()
  {
    solution = false;
    int len = init_s.size();
    if (len * x < 3)
      return;
    std::vector<int8_t> chain;
    chain.reserve(len);
    for (int i = 0; i < len; ++i)
    {
      switch (init_s[i])
      {
      case 'i':
        chain.push_back(qI);
        break;
      case 'j':
        chain.push_back(qJ);
        break;
      case 'k':
        chain.push_back(qK);
        break;
      default:
        return;
      }
    }
    std::vector<int8_t> left_products;
    std::vector<int8_t> right_products;
    left_products.reserve(chain.size() + 1);
    right_products.reserve(chain.size() + 1);
    left_products.push_back(q1);
    right_products.push_back(q1);
    int8_t l = q1;
    int8_t r = q1;
    for (int i = 0; i < len; ++i)
    {
      l = Mul(l, *(chain.begin() + i));
      left_products.push_back(l);
      r = Mul(*(chain.rbegin() + i), r);
      right_products.push_back(r);
    }
    std::vector<int8_t> chain_powers;
    chain_powers.push_back(q1);
    int8_t chain_product = q1;
    for (int i = 0; i < 4; ++i)
    {
      chain_product = Mul(chain_product, *left_products.rbegin());
      chain_powers.push_back(chain_product);
    }
    int8_t total_product = chain_powers[x % 4];
    int64_t total_length = x * len;
    for (int left_full_chains = 0; left_full_chains < 4; ++left_full_chains)
    {
      for (int left_chain_remaining_elements = 1; left_chain_remaining_elements <= chain.size(); ++left_chain_remaining_elements)
      {
        int l = left_full_chains * len + left_chain_remaining_elements;
        if (l > total_length - 2)
          break;
        int8_t first = Mul(chain_powers[left_full_chains], left_products[left_chain_remaining_elements]);
        if (first != qI)
          continue;
        for (int right_full_chains = 0; right_full_chains < 4; ++right_full_chains)
        {
          for (int right_chain_remaining_elements = 1; right_chain_remaining_elements <= chain.size(); ++right_chain_remaining_elements)
          {
            int r = right_full_chains * len + right_chain_remaining_elements;
            if (l + r >= total_length)
              break;
            int8_t third = Mul(right_products[right_chain_remaining_elements], chain_powers[right_full_chains]);
            if (third != qK)
              continue;
            int8_t second = Mul(Mul(-first, total_product), -third);
            if (second != qJ)
              continue;
            solution = true;
            return;
          }
        }
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