// Ganis Zulfa Santoso
// ganiszulfa [at] gmail [dot] com

#include <stdio.h>
#include <iostream>
#include <fstream>

// OPTIONAL
// #include <cmath>
// #include <climits>
#include <algorithm>
#include <string>
// #include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  ifstream read("input.txt");
  ofstream write;
  write.open ("output.txt");
  // STARTS HERE

  int tot_case;
  read >> tot_case;

  int x, y, cur_x, cur_y, cost;
  string ans;

  for (int case_no = 1; case_no <= tot_case; ++case_no) {

    read >> x >> y;
    cur_x = cur_y = 0;
    cost = 0;
    ans = "";

    while (cur_x != x)
    {
      if( cur_x < x )
      {
        ans += "WE";
        ++cur_x;
      }
      else
      {
        ans += "EW";
        --cur_x;
      }
      cost+=2;
    }

    while (cur_y != y) {
      if( cur_y < y )
      {
        ans += "SN";
        ++cur_y;
      }
      else
      {
        ans += "NS";
        --cur_y;
      }
      cost+=2;
    } // end while  
    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
    write << ans << endl;

  } // end for case_no 
  return 0;
}
