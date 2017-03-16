#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  unsigned int T, currentT=0;
  double num, den;
  char c;
  double input, tmp;
  unsigned int count =0;
  int printImp = 0;
  int morethanhalf = 0;
  int count2=0;

  cin >> T;

  while (currentT != T) {

    currentT++;

    cin >> num >> c >> den;
    input = num/den;
    //    cout << input << endl;

    tmp = input;

    count =0;

//     if (tmp > 0.5) {
//       morethanhalf =1;
//       tmp = tmp - 0.5;
//     } else {
//       morethanhalf = 0;
//     }

    while (tmp < 1.0 && count <= 40) {
      count++;
      tmp = tmp * 2;
    }

    //    cout << tmp << endl;

    count2 = count;

    if (tmp != 1.0) {
      //    cout << tmp << endl;
      while (tmp != 1.0 &&  count2 <= 40) {
	if (tmp > 1.0) {
	  tmp = tmp - 1.0;
	}
	count2++;
	tmp = tmp * 2;
      }
    }
      
//     if (morethanhalf)
//       count--;
    if ( tmp != 1.0 || count2 > 40) {
      printImp = 1;
    } else {
      printImp = 0;
    }
    if (printImp)
      cout << "Case #"<< currentT<<": impossible" << endl;
    else 
      cout << "Case #"<< currentT<<": " << count << endl;
  }

  return 0;
}

