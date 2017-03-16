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
  
  string str, sub;
  int n, cnt, mx, ans;
  char voc[] = {'a','i','u','e','o'};
  bool consonant;

  for (int case_no = 1; case_no <= tot_case; ++case_no) {

    read >> str >> n;
    ans=0;

    for (int i = 0; i < str.length(); ++i) {
      for (int j = 1; j <= str.length()-i; ++j) {
        sub = str.substr(i,j);
        cnt=0;
        mx=0;
        //checking the substring
        for (int k = 0; k < sub.length(); ++k) {
          consonant = true;
          for (int l = 0; l < 5; ++l) {
            if( sub[k] == voc[l] )
            {
              consonant = false;
              break;
            }
          } // end for l 
          if (consonant)
            ++cnt;
          else
            cnt=0;
          mx = max(mx, cnt);
        } // end for k 
        if(mx>=n)
          ++ans;
      } // end for j 
    } // end for i 

    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
    printf("%d\n", ans);
    write << ans << endl;

  } // end for case_no 
  return 0;
}
