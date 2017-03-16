#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>

std::string
toString(int n)
{
  std::stringstream out;
  out << n;
  return out.str();
}

bool
isPalyndrome(int n)
{
  std::string s = toString(n);
  int size = s.size();
  int max = size / 2;

  for (int i=0; i<size/2; ++i) {
    if (s[i] != s[size - i - 1]) {
      return false;
    }
  }

  return true;
}

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    int min, max;
    scanf("%d %d\n", &min, &max);

    min = ceil(sqrt(min));
    max = floor(sqrt(max));

    int result =0;
    for (int x=min; x<=max; ++x) {
      if (isPalyndrome(x) && isPalyndrome(x*x)) {
        result++;
      }
    }

    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}
