#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
 
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
int main(){
  int n_case;
  cin >> n_case;
  string line;
  getline( cin, line );
  map<char,char> map_of_alphabet;
  map_of_alphabet['a'] ='y';
  map_of_alphabet['b'] ='h';
  map_of_alphabet['c'] ='e';
  map_of_alphabet['d'] ='s';
  map_of_alphabet['e'] ='o';
  map_of_alphabet['f'] ='c';
  map_of_alphabet['g'] ='v';
  map_of_alphabet['h'] ='x';
  map_of_alphabet['i'] ='d';
  map_of_alphabet['j'] ='u';
  map_of_alphabet['k'] ='i';
  map_of_alphabet['l'] ='g';
  map_of_alphabet['m'] ='l';
  map_of_alphabet['n'] ='b';
  map_of_alphabet['o'] ='k';
  map_of_alphabet['p'] ='r';
  map_of_alphabet['q'] ='z';
  map_of_alphabet['r'] ='t';
  map_of_alphabet['s'] ='n';
  map_of_alphabet['t'] ='w';
  map_of_alphabet['u'] ='j';
  map_of_alphabet['v'] ='p';
  map_of_alphabet['w'] ='f';
  map_of_alphabet['x'] ='m';
  map_of_alphabet['y'] ='a';
  map_of_alphabet['z'] ='q';
  for( int i = 0; i  < n_case ; i++ ){
    getline( cin, line );
    int size = line.size();
    for( int j = 0 ; j < size; j++ ){
      if( line[j] >= 'a' && line[j] <= 'z' ){
        line[j] = map_of_alphabet[line[j]];
      }
    }
    cout << "Case #" << i+1 << ": " << line<<endl;
  }
  return 0;
}

