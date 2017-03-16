#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


//! Rank and File
void rankAndFile(
  std::vector<int> const& i_input,
  std::vector<int> &o_output,
  const int p_N) {

  std::vector<int> numbers(2501, 0);
  for (size_t k = 0; k < i_input.size(); k++) {
    numbers[i_input[k]]++;
  }

  for (size_t k = 1; k < numbers.size(); k++) {
    if (numbers[k] % 2 != 0) {
      o_output.push_back(k);
    }
  }

  std::sort(o_output.begin(), o_output.end());
}




//! Main function
int main()
{
  //! Read the first line of the file to know the total of test
  int T;
  cin >> T;

  //! Print the lines after that
  for (int k = 1; k <= T; k++) {

    //! Read the value
    int N;
    cin >> N;

    std::vector<int> input((2 * N - 1) * N);
    for (int i = 0, n = 0; i < 2 * N - 1; i++) {
      for (int j = 0; j < N; j++, n++) {
        cin >> input[n];
      }
    }

    //! Save the result
    std::vector<int> output;
    rankAndFile(input, output, N);
    cout << "Case #" << k << ":";
    for (int n = 0; n < N; n++) {
      cout << " " << output[n];
    }
    cout << endl;
  }

  return 0;
}
