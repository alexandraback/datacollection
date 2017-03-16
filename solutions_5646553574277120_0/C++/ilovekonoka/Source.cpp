#include <algorithm>
#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int T;
int C, D, V;

const char* input = "input.txt";
const char* output = "output.txt";

vector<vector<bool>> table;
vector<int> coins;

int main()
{
  ifstream in(input);
  ofstream out(output);

  in >> T;
  for (int t = 1; t <= T; ++t)
  {
    cout << "Processing case #" << t << endl;
    in >> C >> D >> V;
    table.clear();
    table.resize(V + 1);
    coins.clear();
    coins.resize(D);
    for (int d = 0; d < D; ++d)
    {
      in >> coins[d];
    }
    int total = 0;
    for (int i = 0; i < coins.size(); ++i)
    {
      int c = coins[i];
      table[c].resize(V + 1, false);
      table[c][c] = true;
    }
    for (int v = 1; v <= V; ++v)
    {
      if (!table[v].empty() && table[v][v])
        continue;
      bool can = false;
      for (int i = 0; i < coins.size(); ++i)
      {
        int c = coins[i];
        if (c < v)
        {
          // check table[v-c]
          int vc = v - c;
          if (!table[vc][c])
          {
            can = true;
            table[v] = table[vc];
            table[v][c] = true;
            break;
          }
        }
      }
      if (!can) // add new coin
      {
        coins.push_back(v);
        table[v].resize(V + 1, false);
        table[v][v] = true;
        ++total;
      }
    }
    out << "Case #" << t << ": " << total << endl;
  }
}