#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

typedef long long LL;

using namespace std;

int main()
{
  ifstream in;
  in.open("A-small-attempt0.in");
  ofstream out;
  out.open("output.txt");
  // Number of Test cases
  int T, circles = 0;
  LL r, ml, lost;
  // Set test cases (first input)
  in >> T;


  // cycle through the test cases
  for(int t = 1; t <= T; t++)
  {
    circles = 0;
    in >> r >> ml;
    while(((r+1)*(r+1) - r*r) <= ml)
    {
      lost = ((r+1)*(r+1) - r*r);
      ml -= lost;
      r+=2;
      circles++;
    }
    out << "Case #" << t << ": " << circles << endl;
  }


  return 0;
}