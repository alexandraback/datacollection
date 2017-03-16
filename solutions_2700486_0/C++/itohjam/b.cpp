#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = acos(-1);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

typedef pair<int,int> P;

int N, X, Y;
set<P> st;

void show(){
  foreach(iter, st){
    printf("(%d, %d) ", iter->first, iter->second);
  }
  cout << endl;
}

double solve(int id){
  //cout<<id<<" : ";
  //show();

  if(id == N){
    if(st.find(P(X, Y)) == st.end()){
      return 0.0;
    }
    else{
      return 1.0;
    }
  }

  int x = 0;
  int y = 100;

  while(y > 0 && st.find(P(x, y - 2)) == st.end()){
    y -= 2;
  }

  double res = 0;

  if(y == 0){
    st.insert(P(x, y));
    res = solve(id + 1);
    st.erase(P(x, y));
    return res;
  }

  bool lflg = (st.find(P(x - 1, y - 1)) == st.end());
  bool rflg = (st.find(P(x + 1, y - 1)) == st.end());

  if(lflg){
    int nx = x - 1;
    int ny = y - 1;

    while(ny > 0){
      if(st.find(P(nx - 1, ny - 1)) == st.end()){
        nx--;
        ny--;
      }
      else if(st.find(P(nx + 1, ny - 1)) == st.end()){
        nx++;
        ny--;
      }
      else{
        break;
      }
    }

    st.insert(P(nx, ny));
    res += solve(id + 1) / (double)(lflg + rflg);
    st.erase(P(nx, ny));
  }

  if(rflg){
    int nx = x + 1;
    int ny = y - 1;

    while(ny > 0){
      if(st.find(P(nx - 1, ny - 1)) == st.end()){
        nx--;
        ny--;
      }
      else if(st.find(P(nx + 1, ny - 1)) == st.end()){
        nx++;
        ny--;
      }
      else{
        break;
      }
    }

    st.insert(P(nx, ny));
    res += solve(id + 1) / (double)(lflg + rflg);
    st.erase(P(nx, ny));
  }

  if(!lflg && !rflg){
    st.insert(P(x, y));
    res += solve(id + 1);
    st.erase(P(x, y));
  }

  return res;
}

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cin >> N >> X >> Y;
    cout << "Case #" << CASE << ": ";
    st.clear();
    cout << fixed << setprecision(10) << solve(0) << endl;
  }
}
