#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>

#define FOR(i,C) for(int i=0; i<C; i++)
#define FOR_REV(i,C) for(int i=C-1; i>=0; i--)

typedef long long ll_t;

using namespace std;

string ans(ll_t x, ll_t y);

int main(int argc, char* argv[]){
  int T;

  cin >> T;

  // read input
  ll_t c = 0;
  while( cin ){
    if( ++c > T ) return -1;

    ll_t x,y;
    cin >> x >> y;

    // output answer
    cout << "Case #" << c << ": " << ans(x,y) << endl;
  }
}

string ans(ll_t x, ll_t y){

  vector<int> t1_step(1,0);
  vector<int> t2_step(1,0);

  ll_t t1,t2;
  if( abs(x) <= abs(y) ){
    t1 = abs(x);
    t2 = abs(y);
  }
  else{
    t1 = abs(y);
    t2 = abs(x);
  }

  ll_t val = 0;
  ll_t n=1;
  while( val < t1 ){
    val += n;
    t1_step.push_back(1);
    n++;
  }

  for( int i=0; i<t1_step.size(); i++ ){
    t2_step.push_back(-1);
  }

  int val2 = 0;;
  if( val - t1 > 0 ){
    t1_step[val-t1] = -1;
    t2_step[val-t1] = 1;
    val2 = val-t1;
  }
  val = val2;

  while( val < t2 ){
    val += n;
    t2_step.push_back(1);
    n++;
  }

  while( val != t2 ){
    ll_t diff = abs(val - t2);
    ll_t s = ll_t( sqrt(diff) );
    if( (s+1)*(s+1)-diff < diff-s*s ) s = s+1;

    if( val - t2 > 0 ){
      for( int i=0; i<s; i++ ){
        val += n;
        t2_step.push_back(1);
        n++;
      }
      for( int i=0; i<s; i++ ){
        val -= n;
        t2_step.push_back(2);
        n++;
      }
    }
    else{
      for( int i=0; i<s; i++ ){
        val -= n;
        t2_step.push_back(2);
        n++;
      }
      for( int i=0; i<s; i++ ){
        val += n;
        t2_step.push_back(1);
        n++;
      }
    }
  }

  vector<int> ans;
  int sign_t1, sign_t2;
  if( t1 == abs(x) ){
    sign_t1 = 1;
    sign_t2 = 2;
    if( t1 != x ) sign_t1 = -1;
    if( t2 != y ) sign_t2 = -2;
  }
  else{
    sign_t1 = 2;
    sign_t2 = 1;
    if( t1 != y ) sign_t1 = -2;
    if( t2 != x ) sign_t2 = -1;
  }

  int i=1;
  for( ; i<t1_step.size(); i++ ){
    if( t1_step[i] == 1 ) ans.push_back( sign_t1 );
    else ans.push_back( sign_t2 );
  } 
  i++;
  for( ; i<t2_step.size(); i++ ){
    if( t2_step[i] == 1 ) ans.push_back( sign_t2 );
    else ans.push_back( (-1)*sign_t2 );
  }

  stringstream ss;

  for( int i=0; i<ans.size(); i++ ){
    if( ans[i] == 1 ) ss << 'E';
    else if( ans[i] == -1 ) ss << 'W';
    else if( ans[i] == 2 ) ss << 'N';
    else if( ans[i] == -2 ) ss << 'S';
    else {
      cerr << 'something is wrong.' << endl;
      exit(-1);
    }
  }

  return ss.str();
}
