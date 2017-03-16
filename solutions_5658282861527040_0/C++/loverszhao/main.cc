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

int
get_result();

int
recursion();

int main(int argc, char *argv[])
{
  int case_amount = 0;
  cin >> case_amount;
    
  for (int i = 0; i < case_amount; ++i)
  {
    const int result = get_result();
    cout << "Case #" << 1 + i << ": " << result << endl;
  }

  return 0;
}

int
get_result()
{
  int A, B, K;
  cin >> A >> B >> K;

  int result = 0;

  for (int i = 0; i < A; ++i)
  {
    for (int j = 0; j < B; ++j)
    {
      if ((i & j) < K)
        result++;
    }
  }
  
  
  return result;
}

int
recursion()
{
  return 0;
}
