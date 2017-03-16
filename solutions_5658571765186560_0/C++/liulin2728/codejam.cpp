#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
  string name = "D-small-attempt0";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;
    int x, y;
    cin >> x;
    cin >> y;
    bool win = true;
    if ((x*y)%number == 0) {
      if (number == 1 || number == 2) win = false;
      else if (number == 3) {
        if (x*y != 3) win = false;
      }else if (number == 4) {
        if (x*y > 8) win = false;
      }
    } 
    cout << "Case #" << test_case << ": " << (win ? "RICHARD" : "GABRIEL") << endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}
