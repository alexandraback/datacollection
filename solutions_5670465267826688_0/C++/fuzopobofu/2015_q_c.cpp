#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

std::map<char, std::map<char, char> > mm;
std::map<char, std::map<char, int> > mmi;

void init() {
  mm['1']['1'] = '1';
  mm['1']['i'] = 'i';
  mm['1']['j'] = 'j';
  mm['1']['k'] = 'k';

  mm['i']['1'] = 'i';
  mm['i']['i'] = '1'; // -
  mm['i']['j'] = 'k';
  mm['i']['k'] = 'j'; // -

  mm['j']['1'] = 'j';
  mm['j']['i'] = 'k'; // -
  mm['j']['j'] = '1'; // -
  mm['j']['k'] = 'i';

  mm['k']['1'] = 'k';
  mm['k']['i'] = 'j';
  mm['k']['j'] = 'i'; // -
  mm['k']['k'] = '1'; // -


  mmi['1']['1'] = 1; 
  mmi['1']['i'] = 1; 
  mmi['1']['j'] = 1; 
  mmi['1']['k'] = 1; 

  mmi['i']['1'] = 1; 
  mmi['i']['i'] = -1; // -
  mmi['i']['j'] = 1; 
  mmi['i']['k'] = -1; // -

  mmi['j']['1'] = 1; 
  mmi['j']['i'] = -1; // -
  mmi['j']['j'] = -1; // -
  mmi['j']['k'] = 1; 
		   
  mmi['k']['1'] = 1; 
  mmi['k']['i'] = 1; 
  mmi['k']['j'] = -1; // -
  mmi['k']['k'] = -1; // -
}

// std::vector< std::vector<char> > vvc(10000, std::vector<char>(10000));
// std::vector< std::vector<int>  > vvi(10000, std::vector<int>(10000));

// bool reducable_helper(char c, int start, int end, string& str) {
//   char result = str[start];
//   int result_sign = 1;
  
//   int s = start;
//   if (vvb[start][end-1]) {
//     result = vvc[start][end-1];
//     result_sign = vvi[start][end-1];
//     s = end-2;
//   }

//   for (int i = s+1; i < end; i++) {
//     cerr << "  " << result << "*" << str[i] << "=";

//     result_sign = result_sign * mmi[result][str[i]];
//     result      = mm[result][str[i]];

//     cerr << result_sign << " " << result << endl;
//   }

//   cerr << start << "..." << end << "=" << str.substr(start, end-start) << ": " << result_sign << " " << result << endl;

//   vvb[start][end] = true;
//   vvc[start][end] = result;
//   vvi[start][end] = result_sign;

//   return (c == result && result_sign == 1) ? true : false;
// }

// bool reducable(char c, int start, int end, string& str) {
//   if (vvb[start][end]) {
//     cerr << start << "..." << end << "=" << str.substr(start, end-start) << ":(cached) " << vvc[start][end] << " " << vvi[start][end] << endl;
//     return (c == vvc[start][end] && vvi[start][end] == 1) ? true : false;
//   } else {
//     return reducable_helper(c, start, end, str);
//   }
// }


void solve() {
  init();

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int L, X;
    cin >> L >> X;
    std::string origstr;
    cin >> origstr;
    std::string str;
    for (int i = 0; i < X; i++) {
      str += origstr;
    }
    
    cerr << "PROBLEM " << t << endl;

    char temp      = '1';
    char temp_sign = 1;

    bool i_exists_p = false;
    int  i_index = 0;
    for (int end = 0; end < L*X; end++) {
      temp_sign = temp_sign * mmi[temp][str[end]];
      temp      = mm[temp][str[end]];

      if (temp=='i' && temp_sign==1) {
	i_exists_p = true;
	i_index = end;
	break;
      }
    }
    if (! i_exists_p) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }

    temp      = '1';
    temp_sign = 1;
    bool k_exists_p = false;
    int k_index = 0;
    for (int start = L*X-1; start >= 0; start--) {
      temp_sign = temp_sign * mmi[str[start]][temp];
      temp      = mm[str[start]][temp];

      if (temp=='k' && temp_sign==1) {
	k_exists_p = true;
	k_index = start;
	break;
      }
    }
    if (! k_exists_p) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }
    if (!(i_index < k_index)) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }

    bool minus_one_p = false;
    temp      = '1';
    temp_sign = 1;
    for (int i = 0; i < L*X; i++) {
      temp_sign = temp_sign * mmi[temp][str[i]];
      temp      = mm[temp][str[i]];
    }
    if (temp=='1' && temp_sign==-1) {
      minus_one_p = true;
    }
    if (! minus_one_p) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }

    std::cout << "Case #" << (t+1) << ": " << "YES" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
