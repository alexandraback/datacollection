#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void simulate(vector<int> &m, int R, int C, int W, int &count)
{
  for(int i=W-1; i<C; i+=W)
  {
    count++;
    m[i]=1;
  }

  count*=R;

  if(m[C-1]!=1)
    count++;

  count += W-1;
}

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("A-small-attempt0.in");
  ofstream out("A-small-attempt.out");

  //ifstream in("A-large.in");
  //ofstream out("A-large.out");

  in >> T;

  for(int testCase=0; testCase<T; ++testCase)
  {
    int solve = 0; 

    int R,C,W;

    in >> R>> C>>W;

    vector<int> m(C);
    simulate(m,R,C,W,solve);

    out << "Case #"<<testCase+1<<": ";

    out << solve << endl;
  }

  return 0;
}