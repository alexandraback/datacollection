#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  //ifstream in("A-small-attempt0.in");
  //ofstream out("A-small-attempt0.out");

  ifstream in("A-large.in");
  ofstream out("A-large.out");

  in >> T;

  for(int i=0; i<T; ++i)
  {
    int solve = 0, count = 0; 
    int n;
    in >> n;

    string str;

    in >> str;

    count += str[0]-'0';

    for(int j=1; j<=n; j++)
    {
      char v = str[j]-'0';

      if (j > count)
      {
        solve += j-count;
        count += j-count;
      }

      count += v;
    }

    out << "Case #"<<i+1<<": ";

    out << solve << endl;
  }

  return 0;
}