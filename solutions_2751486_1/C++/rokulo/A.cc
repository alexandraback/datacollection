#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define FOR(i,C) for(int i=0; i<C; i++)
#define FOR_REV(i,C) for(int i=C-1; i>=0; i--)

typedef long long ll_t;

using namespace std;

ll_t ans(string name, int n);
char vow[5] = {'a','e','i','o','u'};

int main(int argc, char* argv[]){
  int T;

  cin >> T;

  // read input
  ll_t c = 0;
  while( cin ){
    if( ++c > T ) return -1;

    string name;
    int n;
    cin >> name >> n;

    // output answer
    cout << "Case #" << c << ": " << ans(name,n) << endl;
  }

  return 0;
}

ll_t ans(string name, int n){

  vector<int> cs;
  int l = name.length();

  bool prevIsC = true;
  for( int j=0; j<5; j++ ){
    if( name.at(0) == vow[j] ){
      prevIsC = false;
      break;
    }
  }

  if( prevIsC ) cs.push_back(1);
  else          cs.push_back(-1);

  for( int i=1; i<l; i++ ){
    bool isC = true;
    for( int j=0; j<5; j++ ){
      if( name.at(i) == vow[j] ){
        isC = false;
        break;
      }
    }

    if( isC == prevIsC ){
      if( isC ) ++cs[cs.size()-1];
      else      --cs[cs.size()-1];
    }
    else{
      if( isC ) cs.push_back(1);
      else      cs.push_back(-1);
    }

    prevIsC = isC;
  }

  for( int i=0; i<cs.size(); i++ ){
    if( cs[i] > 0 && cs[i] < n ){
      cs[i] = -1 * cs[i];
    }
  }

  ll_t N=0;
  for( int i=0; i<cs.size(); i++ ){
    if( cs[i] >= n ){
      ll_t in = ( cs[i] - n + 1 )*( cs[i] - n + 1 ) - ( cs[i]-n )*( cs[i] - n + 1 )/2.0;

      ll_t l_left  = 0;
      for( int j=i-1; j>=0; j-- ){
        if( cs[j] < 0 ){
          l_left += abs(cs[j]);
        }
        else{
          l_left += n-1;
          break;
        }
      } 

      ll_t l_right = 0;
      for( int j=i+1; j<cs.size(); j++ ){
        l_right += abs(cs[j]);
      }

      ll_t left = ( cs[i] - n ) * l_left;
      ll_t right = ( cs[i] - n ) * l_right;
      ll_t both = (l_left + 1) * (l_right + 1);

      N += in + left + right + both - 1;
    }
  }

  return N;
}
 
