#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;
typedef long long LL;

LL solver(LL R, LL C, LL W){
  int will_not_miss = (C % W) == 0;

  LL X = ((C/W) * R) + (W - will_not_miss);
  return X;
}

int main(int argc, char *argv[])
{
  string line, M;
  LL T, R, C, W;
  string file_prefix = "large";
  #ifdef TEST
  cout << "Debug run \n";
  file_prefix = "test";
  #endif
  ifstream inputf(file_prefix + "-input.txt");
  ofstream outf(file_prefix + "-output.txt");
  if (inputf.is_open())
    {
      getline (inputf, line);
      T = stoi(line);
      for (int case_no = 1; case_no <= T; ++case_no){
        getline (inputf, line);
        istringstream iss(line);
        iss >> R >> C >> W;

        #ifdef TEST
        cout << "I/O - R:" << R << endl;
        cout << "I/O - C:" << C << endl;
        cout << "I/O - W:" << W << endl;
        #endif

        cout << "Processing test case #" << case_no << endl;
        LL sol = solver(R, C, W);
        outf << "Case #" << case_no << ": " << sol <<  endl;

      }
    }
  else
    cerr << "file not found!\n";
  inputf.close();

  return 1;
}
