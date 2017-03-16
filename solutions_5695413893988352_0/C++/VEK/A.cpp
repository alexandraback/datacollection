#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

typedef long long unsigned llu;

unsigned testNum, best_left, best_right;

template <typename T>
string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void get_best (string left, string right, unsigned left_num, unsigned right_num,
               unsigned pos, bool one_smaller, bool one_bigger)
{
  if (pos >= left.length ())
    {
      unsigned diff = (left_num>right_num)?(left_num-right_num)
                                          :(right_num-left_num);
      unsigned prev_diff = (best_left>best_right)?(best_left-best_right)
                                                 :(best_right-best_left);
      if (diff < prev_diff || (diff == prev_diff && left_num < best_left) ||
          (diff == prev_diff && left_num == best_left && right_num < best_right))
        {
          best_left = left_num;
          best_right = right_num;
        }
      return;
    }
  if (left[pos] == '?' || right[pos] == '?')
    {
      if (left_num < right_num)
        {
          if (one_smaller || one_bigger)
            return;
          if (left[pos] == '?')
            left[pos] = '9';
          if (right[pos] == '?')
            right[pos] = '0';
        }
      else if (left_num > right_num)
        {
          if (one_smaller || one_bigger)
            return;
          if (left[pos] == '?')
            left[pos] = '0';
          if (right[pos] == '?')
            right[pos] = '9';
        }
      else
        {
          if (left[pos] == '?' && right[pos] == '?')
            {
              if (one_smaller)
                {
                  left[pos] = '0';
                  right[pos] = '1';
                }
              else if (one_bigger)
                {
                  left[pos] = '1';
                  right[pos] = '0';
                }
              else
                {
                  left[pos] = '0';
                  right[pos] = '0';
                }
            }
          else if (left[pos] == '?')
            {
              if (one_smaller)
                {
                  if (right[pos] == '0')
                    return;
                  left[pos] = right[pos]-1;
                }
              else if (one_bigger)
                {
                  if (right[pos] == '9')
                    return;
                  left[pos] = right[pos]+1;
                }
              else
                left[pos] = right[pos];
            }
          else if (right[pos] == '?')
            {
              if (one_smaller)
                {
                  if (left[pos] == '0')
                    return;
                  right[pos] = left[pos]-1;
                }
              else if (one_bigger)
                {
                  if (left[pos] == '9')
                    return;
                  right[pos] = left[pos]+1;
                }
              else
                right[pos] = left[pos];
            }
        }
    }
  left_num *= 10;
  left_num += left[pos]-'0';
  right_num *= 10;
  right_num += right[pos]-'0';
  get_best (left, right, left_num, right_num, pos+1, false, false);
  get_best (left, right, left_num, right_num, pos+1, true, false);
  get_best (left, right, left_num, right_num, pos+1, false, true);
}

int main(int argc, char **argv)
{
  ifstream ifile("B-small-attempt1.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  string left;
  string right;
  getline (ifile, left);

  for (unsigned i = 0; i < testNum; ++i) {
    getline (ifile, left, ' ');
    getline (ifile, right);
    string format_str = "Case #%d: %0";
    format_str += left.length ()+'0';
    format_str += "d %0";
    format_str += right.length ()+'0';
    format_str += "d\n";
    best_left = 0;
    best_right = 1 << 30;
    get_best (left, right, 0, 0, 0, false, false);
    get_best (left, right, 0, 0, 0, true, false);
    get_best (left, right, 0, 0, 0, false, true);
    printf (format_str.c_str (), i+1, best_left, best_right);
    fprintf (ofile, format_str.c_str (), i+1, best_left, best_right);
  }
  ifile.close();
  fclose(ofile);
  return 0;
}
