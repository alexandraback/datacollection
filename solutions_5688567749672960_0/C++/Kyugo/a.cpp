#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
// #define DEBUG

using namespace std;

// typedef pair<int,int>P;
// typedef complex<double>P;

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 1e9;
const double EPS=1e-9;

ll reverse(ll num){
  stringstream s;
  s << num;
  string tmp;
  s >> tmp;
  reverse(tmp.begin(),tmp.end());
  stringstream s2;
  s2 << tmp;
  ll ret;
  s2 >> ret;
  return ret;
}

ll solve_small(){
  ll N;
  cin >> N;

  int MAX = N+1;
  int memo[MAX];
  for(int i = 0 ; i < MAX ; i++)memo[i] = INF;
  memo[0] = 0;
  for(int i = 0 ; i <= N ; i++){
    memo[i+1] = min(memo[i+1],memo[i]+1);
    ll num = reverse(i);
    if(num > N)continue;
    memo[num] = min(memo[num],memo[i]+1);
  }
  return memo[N];
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  for(int i = 1 ; i <= t ; i++){
    cout << "Case #" << i << ": " << solve_small() << endl;
  }
  return 0;
}
