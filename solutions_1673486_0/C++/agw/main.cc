#include <iostream>
#include <iomanip>
#include <vector>


#define ALL(x) (x).begin(), (x).end()


int main(int argc, char** argv)
{
  int T;

  std::cin >> T;

  for (int t = 0; t < T; t ++) {
    int A, B;

    std::cin >> A >> B;

    std::vector<double> p(A), c(A, 0.0);

    for (int i = 0; i < A; i ++)
      std::cin >> p[i];

    c[0] = p[0];

    for (int i = 1; i < A; i ++)
      c[i] = c[i-1] * p[i];

    double s1 = 0.0;

    s1 = ((B - A) + 1 + 0) * c[A-1] + (((B - A) + 1) + (B + 1)) * (1 - c[A-1]);

    double s2 = A + B + 1;

    for (int i = 1; i < A; i ++)
      s2 = std::min((i + (B - A + i) + 1) * c[A-i-1] + (i + (B - A + i) + 1 + B + 1) * (1 - c[A-i-1]), s2);
    
    double s3 = 1 + B + 1;

    std::cout <<
      "Case #" << t + 1 << ": " <<
      std::fixed <<
      std::setprecision(6) <<
      std::min(std::min(s1, s2), s3) << std::endl;
  }
}
