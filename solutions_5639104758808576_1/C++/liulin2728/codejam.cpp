#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string name = "A-large";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;
    
    string audi;
    cin >> audi;

    int total = audi[0] - '0';
    int sum = 0;
    for (int i = 1; i <= number; i++) {
      if (total < i) {
        sum += i - total;
        total = i + audi[i] - '0'; 
      }
      else total +=  audi[i] - '0';
    }

    cout << "Case #" << test_case << ": " << sum << endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}