// Ganis Zulfa Santoso
// ganiszulfa [at] gmail [dot] com

#include <stdio.h>
#include <iostream>
#include <fstream>

// OPTIONAL
// #include <cmath>
#include <climits>
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

  int N, ans, all_att;
  int i_day[1000], tot_att[1000], i_west[1000]
    , i_east[1000], i_str[1000], d_day[1000]
    , d_pos[1000], d_str[1000];


  int wall[2001], upgrade[2001]; // -1000, 1000

  bool suc;

  for (int case_no = 1; case_no <= tot_case; ++case_no) {

    read >> N;
    all_att = 0;
    ans = 0;

    for (int i = 0; i < N; ++i) {
      read >> i_day[i] >> tot_att[i] >> i_west[i]
        >> i_east[i] >> i_str[i] >> d_day[i]
        >> d_pos[i] >> d_str[i];
      // i_ = initial, d_ = delta

      // adjust to wall var
      i_west[i]+=1000;
      i_east[i]+=1000;

      all_att += tot_att[i];

    } // end for i 

    // reset wall
    for (int i = 0; i < 2001; ++i) {
      wall[i] = upgrade[i] = 0;
    } // end for i 

    for (int day = 0; day < INT_MAX; ++day) {
      for (int tribe = 0; tribe < N; ++tribe) {
        if(i_day[tribe]==day
            && tot_att[tribe]>0 )
        {
          suc = false;
          for (int pos = i_west[tribe]; pos < i_east[tribe]; ++pos) {
            // attack the wall
            if(wall[pos] >= i_str[tribe])
            {
              // strong enough
            }
            else
            {
              // not strong enough
              suc = true;
              if(upgrade[pos]<i_str[tribe])
                upgrade[pos] = i_str[tribe];
            }
          } // end for pos 
          if(suc)
            ++ans;
          // update for next attack
          i_str[tribe] += d_str[tribe];
          i_east[tribe] += d_pos[tribe];
          i_west[tribe] += d_pos[tribe];
          i_day[tribe] += d_day[tribe];
          --tot_att[tribe];
          --all_att;
        }
      } // end for tribe 
      for (int i = 0; i < 2001; ++i) {
        wall[i] = upgrade[i];
      } // end for i 
      if(!all_att)
        break;
    } // end for day 

    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
    write << ans << endl;
    printf("%d\n", ans);

  } // end for case_no 
  return 0;
}
