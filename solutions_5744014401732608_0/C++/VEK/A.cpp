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

unsigned testNum, b, m;

template <typename T>
string num_to_str ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

bool is_connected (unsigned i, unsigned j)
{
  if (i == 0)
    {
      if (m == 1)
        return (j == b-1);

      if (j == 0)
        return false;

      if (m == (unsigned)1 << min (b-2, 18))
        return true;

      if (j == b-1)
        return false;

      /*cout << "|m " << m << "|" << endl;
      cout << "|bit " << ((m >> (b-j-2)) & 1) << "|" << endl;
      cout << "|j " << (j) << "|" << endl;
      cout << "|s " << (b-j-2) << "|" << endl;
      cout << "|s2 " << (m >> (b-j-2)) << "|" << endl;*/

      if ((m >> (b-j-2)) & 1)
        return true;

      return false;
    }

  return (i < j);
}

int main(int argc, char **argv)
{
  ifstream ifile("B-small-attempt1.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  for (unsigned i = 0; i < testNum; ++i) {
    ifile >> b >> m;
    printf ("Case #%d: ", i+1);
    fprintf (ofile, "Case #%d: ", i+1);
    if (m > (unsigned)1 << min (b-2, 18))
      {
        printf ("IMPOSSIBLE\n");
        fprintf (ofile, "IMPOSSIBLE\n");
        continue;
      }
    printf ("POSSIBLE\n");
    fprintf (ofile, "POSSIBLE\n");
    for (unsigned i = 0; i < b; ++i)
      {
        for (unsigned j = 0; j < b; ++j)
          {
            printf ("%d ", is_connected (i, j));
            fprintf (ofile, "%d ", is_connected (i, j));
          }
        printf ("\n");
        fprintf (ofile, "\n");
      }
  }
  ifile.close();
  fclose(ofile);
  return 0;
}
