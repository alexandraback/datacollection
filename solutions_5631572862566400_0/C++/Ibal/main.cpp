#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


//! Counting sheep
string bff(
  const std::vector<int> &i_input) {

  //! Initialization of the array of integer seen
  const int N = i_input.size();

  std::vector<int> circles;

  std::vector<int> students(N, 0);

  for (int k = 0; k < N; k++) {

    if (students[k] == 0) {
      //cout << "k = " << k << endl;
      bool keepGoing = true;
      std::vector<int> circle;
      circle.push_back(k + 1);
      students[k] = k + 1;

      while (keepGoing) {
        const int current = circle.back();
        const int next    = i_input[current - 1];
        //cout << "current = " << current << ", next = " << next << endl;
        if (students[next - 1] == 0) {
          circle.push_back(next);
          students[next - 1] = k + 1;
        }
        const int nextNext = i_input[next - 1];
        //cout << "current = " << current << ", next = " << next << ", nextNext = " << nextNext << endl;
        if (students[nextNext - 1] > 0 && (students[nextNext - 1] != k + 1 ||
            (nextNext != current && nextNext != circle.front() && next != circle[circle.size() - 2]))) {
          circle.clear();
          keepGoing = false;
        }
        else if (students[nextNext - 1] > 0) {
          //cout << "add" << endl;
          keepGoing = false;
          //if (nextNext == current) {
            for (int n = 0; n < N; n++) {
              if (students[n] == 0 && (i_input[n] == next || i_input[n] == current)) {
                circle.push_back(n + 1);
                students[n] = k + 1;
                //cout << n + 1 << endl;
                keepGoing = true;
                break;
              }
            }
          //}
        }
      }
      /*for (size_t n = 0; n < circle.size(); n++) {
        cout << circle[n] << " ";
      }
      cout << endl;*/
      circles.push_back(circle.size());
    }
  }

  int res = circles[0];
  for (size_t k = 1; k < circles.size(); k++) {
    res = std::max(res, circles[k]);
  }

  //! Transform the result int to string
  stringstream ss;
  ss << res;
  return ss.str();
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
    std::vector<int> input(N);
    for (int n = 0; n < N; n++) {
      cin >> input[n];
    }

    //! Save the result
    cout << "Case #" << k << ": " << bff(input) << endl;
  }

  return 0;
}
