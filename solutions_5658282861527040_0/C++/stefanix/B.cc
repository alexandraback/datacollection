#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<climits>

using namespace std;
int main()
{
  ifstream f("B-small-attempt0.in");
  ofstream of("B-small-attempt0.out");
  
  int test_cases = 0;
  f >> test_cases;

  int n;

  int a;
  int b;
  int k;
  for(int tc=0; tc<test_cases; tc++)
  {
    // read from if
    f >> a >> b >> k;

    long long sol = 0;
    for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
      {
        int r = i & j;
        if (r<k) sol++;
      }

    // solve

    // write to of
    of << "Case #" << tc+1 << ": " << sol;
    of << endl;
//    break;
  }

  f.close();
  of.close();
}
