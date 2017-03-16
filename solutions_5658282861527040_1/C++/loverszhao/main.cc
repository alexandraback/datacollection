#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long
get_result();

int
recursion();

int main(int argc, char *argv[])
{
  int case_amount = 0;
  cin >> case_amount;
    
  for (int i = 0; i < case_amount; ++i)
  {
    const long long result = get_result();
    cout << "Case #" << 1 + i << ": " << result << endl;
  }

  return 0;
}

long long
get_result()
{
  long long A, B, K;
  cin >> A >> B >> K;

  {
    int _min = min(A, B);
    int _max = max(A, B);
    A = _min;
    B = _max;
  }

  long long result = 0;

  if (A < K || B < K)
    return A * B;

  result += K * B;

  for (int i = K; i < A; ++i)
  {
    result += K;
    for (int j = K; j < B; ++j)
      if ((i & j) < K)
        result++;
  }
  
  return result;
}

int
recursion()
{
  return 0;
}
