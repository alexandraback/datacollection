#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  int t;
  cin >> t;
  for (int ti=0; ti < t; ti++)
  {
    int i, res, up;
    string s;
    cin >> i >> s;
    res = 0;
    up = 0;
    for (int j = 0; j < s.size(); j++)
      if (s[j] == '0' && up <= j) {
	res++;
	up++;
      } else {
	up += (s[j] - '0');
      }
    cout << "Case #" << ti+1 << ": " << res << std::endl;
  }
}
