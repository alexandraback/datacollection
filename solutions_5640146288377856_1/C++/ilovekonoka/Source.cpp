#include <algorithm>
#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

int T;
int R, C, W;

const char* input = "input.txt";
const char* output = "output.txt";

int main()
{
  ifstream in(input);
  ofstream out(output);

  in >> T;
  for (int t = 1; t <= T; ++t)
  {
    in >> R >> C >> W;
    cout << "Processing case #" << t << endl;
    int total = R * C;
    if (W > 1)
      if (C / W > 1)
        if (C % W != 0)
          total = (R - 1) * (C / W) + (C / W) + W;
        else
          total = (R - 1) * (C / W) + (C / W) + W - 1;
      else
        total = (R - 1) * (C / W) + min(W + 1, C);
    out << "Case #" << t << ": " << total << endl;
  }
}