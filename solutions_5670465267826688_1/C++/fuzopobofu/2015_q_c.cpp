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


void solve() {
  init();

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long L, X;
    cin >> L >> X;
    std::string str;
    cin >> str;
    // std::string str;
    // for (int i = 0; i < X; i++) {
    //   str += origstr;
    // }
    
    char temp;
    int temp_sign;

    bool minus_one_p = false;
    temp      = '1';
    temp_sign = 1;
    for (int i = 0; i < L; i++) {
      temp_sign = temp_sign * mmi[temp][str[i]];
      temp      = mm[temp][str[i]];
    }
    if ((X % 2 != 0 && 
	 temp == '1' && temp_sign == -1) ||
	(X % 2 == 0 && X % 4 != 0 &&
	 (temp == 'i' || temp == 'j' || temp == 'k'))) {
      minus_one_p = true;
    }
    if (! minus_one_p) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl; 
      continue;
    }

    std::vector<char > chars(5);
    std::vector<int >  signs(5);
    chars[1] = temp;
    chars[2] = mm[chars[1]][temp];
    chars[3] = mm[chars[2]][temp];
    chars[4] = mm[chars[3]][temp];
    signs[1] = temp_sign;
    signs[2] = temp_sign * signs[1] * mmi[chars[1]][temp];
    signs[3] = temp_sign * signs[2] * mmi[chars[2]][temp];
    signs[4] = temp_sign * signs[3] * mmi[chars[3]][temp];

    temp      = '1';
    temp_sign = 1;
    std::vector<bool > i_exists_p(5, false);
    std::vector<long long > i_indexes(5, LLONG_MAX);
    for (int end = 0; end < L; end++) {
      temp_sign = temp_sign * mmi[temp][str[end]];
      temp      = mm[temp][str[end]];

      if (temp=='i' && temp_sign==1) {
	i_exists_p[0] = true;
	i_indexes[0] = end;
	break;
      } else {
	for (int i = 1; i <= 4; i++) {
	  char c = mm[chars[i]][temp];
	  int  s = signs[i] * temp_sign * mmi[chars[i]][temp];
	  if (c=='i' && s==1) {
	    i_exists_p[i] = true;
	    i_indexes[i]  = L*i+end;
	  }
	}
      }
    }

    if (std::all_of( i_exists_p.begin(), i_exists_p.end(), [=](decltype(*begin(i_exists_p)) x) -> bool {
	    return x == false;
	  })) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }
    long long i_index = *(std::min_element(i_indexes.begin(), i_indexes.end()));

    temp      = '1';
    temp_sign = 1;
    std::vector<bool > k_exists_p(5, false);
    std::vector<long long > k_indexes(5, -1);
    for (int start = L-1; start >= 0; start--) {
      temp_sign = temp_sign * mmi[str[start]][temp];
      temp      = mm[str[start]][temp];

      if (temp=='k' && temp_sign==1) {
	k_exists_p[0] = true;
	k_indexes[0] = L*(X-1)+start;
	break;
      } else {
	for (int i = 1; i <= 4; i++) {
	  char c = mm[temp][chars[i]];
	  int  s = temp_sign * signs[i] * mmi[temp][chars[i]];;
	  if (c=='k' && s==1) {
	    k_exists_p[i] = true;
	    k_indexes[i]  = L*(X-1-i)+start;
	  }
	}
      }
    }

    if (std::all_of( k_exists_p.begin(), k_exists_p.end(), [=](decltype(*begin(k_exists_p)) x) -> bool {
	  return x == false;
	})) {
      std::cout << "Case #" << (t+1) << ": " << "NO" << std::endl;	
      continue;
    }
    long long k_index = *(std::max_element(k_indexes.begin(), k_indexes.end()));

    if (!(i_index < k_index)) {
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
