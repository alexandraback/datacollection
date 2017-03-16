#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits.h>
#include <map>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

typedef long long unsigned llu;

unsigned testNum, a, b, c, k, used_num, max_used_num;
bool used[3][3][3], best_used[3][3][3];
unsigned occ[3][3][3]; // pair#, el1, el2

template <typename T>
string num_to_str ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void get_best (unsigned aa = 0, unsigned bb = 0, unsigned cc = 0)
{
  if (cc >= c)
    {
      if (used_num > max_used_num)
        {
          max_used_num = used_num;
          for (unsigned aa = 0; aa < a; ++aa)
            for (unsigned bb = 0; bb < b; ++bb)
              for (unsigned cc = 0; cc < c; ++cc)
                best_used[aa][bb][cc] = used[aa][bb][cc];
        }
      return;
    }
  unsigned n_aa = aa, n_bb = bb, n_cc = cc;
  ++n_aa;
  if (n_aa >= a)
    {
      n_aa = 0;
      ++n_bb;
      if (n_bb >= b)
        {
          n_bb = 0;
          ++n_cc;
        }
    }
  ++used_num;
  used[aa][bb][cc] = true;
  ++occ[0][aa][bb];
  ++occ[1][aa][cc];
  ++occ[2][bb][cc];
  if (occ[0][aa][bb] <= k && occ[1][aa][cc] <= k && occ[2][bb][cc] <= k)
    get_best(n_aa, n_bb, n_cc);
  --used_num;
  --occ[0][aa][bb];
  --occ[1][aa][cc];
  --occ[2][bb][cc];
  used[aa][bb][cc] = false;
  get_best(n_aa, n_bb, n_cc);
}

int main(int argc, char **argv)
{
  ifstream ifile("C-small-attempt0.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  for (unsigned i = 0; i < testNum; ++i) {
    ifile >> a >> b >> c >> k;
    for (unsigned aa = 0; aa < a; ++aa)
      {
        for (unsigned bb = 0; bb < b; ++bb)
          {
            for (unsigned cc = 0; cc < c; ++cc)
              {
                used[aa][bb][cc] = false;
                occ[aa][bb][cc] = 0;
              }
          }
      }
    used_num = 0;
    max_used_num = 0;
    printf ("Case #%d: ", i+1);
    fprintf (ofile, "Case #%d: ", i+1);
    get_best ();
    printf ("%d\n", max_used_num);
    fprintf (ofile, "%d\n", max_used_num);
    for (unsigned aa = 0; aa < a; ++aa)
      {
        for (unsigned bb = 0; bb < b; ++bb)
          {
            for (unsigned cc = 0; cc < c; ++cc)
              {
                if (best_used[aa][bb][cc])
                  {
                    printf ("%d %d %d\n", aa+1, bb+1, cc+1);
                    fprintf (ofile, "%d %d %d\n", aa+1, bb+1, cc+1);
                  }
              }
          }
      }

  }
  ifile.close();
  fclose(ofile);
  return 0;
}
