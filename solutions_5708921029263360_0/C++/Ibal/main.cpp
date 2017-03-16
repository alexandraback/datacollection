#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int fashionPolice(
  int j,
  int p,
  int s,
  int K,
  std::vector<std::vector<int> > &combination) {

  int N = j * p * s;
  int a = 1, b = 1, c = 1, kc = 1;
  vector<vector<int> > sets;

  for (int n = 0; n < N; n++) {
    vector<int> values;
    values.push_back(a);
    values.push_back(b);
    values.push_back(c);
    //if (kc <= K) {
      sets.push_back(values);
    //}

    if (c == s) {
      //c = (b / K) * K + 1;
      //kc = 1;
      c = 1;
      if (b == p) {
        //b = (a / K) * K + 1;
        b = 1;
        c = 1;
        a++;
        if (a > j) {
          break;
        }
      }
      else {
        b++;
      }
    }
    else {
      c++;
      //kc++;
    }
  }

  a = 1, b = 1; c = 1;
  for (int a = 0; a < j; a++) {
    for (int b = 0; b < p; b++) {
      for (int c = 0; c < std::min(K, s); c++) {
        combination.push_back(sets[a * (p * s) + b * s + (c + b) % s]);
      }
    }
  }


  return combination.size();
}

//! Main function
int main()
{
  //! Read the first line of the file to know the total of test
  int T;
  cin >> T;

  //! Print the lines after that
  for (int n = 1; n <= T; n++) {

    //! Read the value
    int j, p, s, k;
    cin >> j >> p >> s >> k;

    //! Save the result
    vector<vector<int> > combination;
    cout << "Case #" << n << ": " << fashionPolice(j, p, s, k, combination)<< endl;
    for (size_t l = 0; l < combination.size(); l++) {
      for (size_t m = 0; m < combination[l].size(); m++) {
        cout << combination[l][m] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
