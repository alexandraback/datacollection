#include <iostream>
#include <fstream>
#include <string>
//#include <boost/algorithm/string.hpp>

using namespace std;
int main() {

  ifstream in("a-small.in");
  ofstream out("a-small.out");


  int ncases;
  in >> ncases;
  cout << ncases << endl;
  


  for (int icase = 0; icase < ncases; icase++)
  {
    int n;
    in >> n;
    
    string s;
    in >> s;
    //cout << n << ":" << s << endl;

    int current = 0;
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
      int c = s[i] - '0';
      if (current < i)
      {
        res += i - current;
        current = i;
      }
      current += c;
    }

    out << "Case #"<<(icase+1)<<": " <<res << endl;
  }

  in.close();
  out.close();
  return 0;
}