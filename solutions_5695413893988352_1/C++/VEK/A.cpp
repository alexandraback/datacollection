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

llu testNum, best_left, best_right;

template <typename T>
string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void get_best (string left, string right, llu left_num, llu right_num,
               llu pos, bool one_smaller, bool one_bigger, bool change=true)
{
  if (!change && (one_bigger || one_smaller))
      return;
  if (pos >= left.length ())
    {
      llu diff = (left_num>right_num)?(left_num-right_num)
                                          :(right_num-left_num);
      llu prev_diff = (best_left>best_right)?(best_left-best_right)
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
  change = !(one_bigger || one_smaller);
  get_best (left, right, left_num, right_num, pos+1, false, false, change);
  get_best (left, right, left_num, right_num, pos+1, true, false, change);
  get_best (left, right, left_num, right_num, pos+1, false, true, change);
}

int main(int argc, char **argv)
{
  ifstream ifile("B-large.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  string left;
  string right;
  getline (ifile, left);

  for (llu i = 0; i < testNum; ++i) {
    getline (ifile, left, ' ');
    getline (ifile, right);
    string format_str = "Case #%lld: %0";
    format_str += NumberToString(left.length ());
    format_str += "lld %0";
    format_str += NumberToString(right.length ());
    format_str += "lld\n";
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
