#include "common.h"

using namespace std;

bool completely_determined(int product, vector<int> &digits)
{
  if (product == 125) {
    digits[2] = digits[1] = digits[0] = 5;
    return true;
  } else if (product == 100) {
    digits[2] = digits[1] = 5;
    digits[0] = 4;
    return true;
  } else if (product == 75) {
    digits[2] = digits[1] = 5;
    digits[0] = 3;
    return true;
  } else if (product == 50) {
    digits[2] = digits[1] = 5;
    digits[0] = 2;
    return true;
  } else if (product == 27) {
    digits[2] = digits[1] = digits[0] = 3;
    return true;
  } else if (product == 60) {
    digits[2] = 5;
    digits[1] = 4;
    digits[0] = 3;
    return true;
  } else if (product == 45) {
    digits[2] = 5;
    digits[1] = 3;
    digits[0] = 3;
    return true;
  } else if (product == 30) {
    digits[2] = 5;
    digits[1] = 3;
    digits[0] = 2;
    return true;
  } 

  return false;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    exit(1);
  }

  ifstream ifs(argv[1]);

  int T;
  ifs >> T;
  cout << "Case #1:" << endl;

  int R, N, M, K;
  ifs >> R >> N >> M >> K;

  vector<int> products(K, 0);
  vector<int> digits(N, 0);
  vector<int> possible(M - 1, 0);
  for (int i = 2; i <= M; ++i)
  {
    possible[i - 2] = i;
  }

  int digit_next;
  map<int, int> digit_counts;
  for (int i = 0; i < R; ++i)
  {
    // Setup
    digit_counts[2] = digit_counts[3] = digit_counts[4] = digit_counts[5] = 0;
    for (int j = 0; j < K; ++j)
      ifs >> products[j];
    for (int j = 0; j < N; ++j)
      digits[j] = 2;

    // Refine
    for (int j = 0; j < K; ++j)
    {
      if (products[j] == 1) // Easy check for something that gives no information
        continue;

      // Products which completely determine the answer
      if (completely_determined(products[j], digits))
        break;

      // Products which give some clues
      if (products[j] % 5 == 0) {
        digits[0] = 5;
        digit_counts[5] = max(digit_counts[5], 1);
      }
      if (products[j] == 25)
      {
        digits[0] = digits[1] = 5;
        digit_counts[5] = max(digit_counts[5], 2);
      }

      if (products[j] % 3 == 0)
      {
        digits[2] = 3;
        digit_counts[3] = max(digit_counts[3], 1);
      }
      if (products[j] % 9 == 0)
      {
        digits[1] = digits[2] = 3;
        digit_counts[3] = max(digit_counts[3], 2);
      }
    }

    // Output
    for (int j = 0; j < N; ++j)
    {
      cout << digits[j];
    }
    cout << endl;
  }

  return 0;
}
