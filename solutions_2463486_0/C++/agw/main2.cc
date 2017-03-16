#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#define ALL(x) (x).begin(), (x).end()
#define EACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++ i)


static const long long lut[] = {
              1,             4,             9,            121,
            484,         10201,         12321,          14641,
          40804,         44944,       1002001,        1234321,
        4008004,     100020001,     102030201,      104060401,
      121242121,     123454321,     125686521,      400080004,
      404090404,   10000200001,   10221412201,    12102420121,
    12345654321,   40000800004, 1000002000001,   1002003002001,
  1004006004001, 1020304030201, 1022325232201,   1024348434201,
  1210024200121, 1212225222121, 1214428244121,   1232346432321,
  1234567654321, 4000008000004, 4004009004004, 100000020000001
};


std::string lltos(long long x)
{
  std::ostringstream oss;

  oss << x;

  return oss.str();
}

class solver_t
{
public:
  solver_t() : a_(lut, lut + sizeof(lut) / sizeof(lut[0])) {};

public:
  int operator()(long long A, long long B) const {
    return std::upper_bound(ALL(a_), B) - std::lower_bound(ALL(a_), A);
  };

private:
  std::vector<long long> a_;
};


int main(int argc, char** argv)
{
  std::istream_iterator<long long> it(std::cin);

  int T, A, B;

  T = *it ++;

  solver_t solver;

  for (int t = 1; t <= T; t ++) {
    A = *it ++;
    B = *it ++;

    std::cout << "Case #" << t << ": " << solver(A, B) << std::endl;
  }

  return 0;
}
