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

int C,D,V;

int check(vector<int> coins){
const int MAX = 50;
 int d = coins.size();
    bool dp[MAX][d+1];
    for(int i = 0 ; i < MAX ; i++)for(int j = 0 ; j < d+1 ; j++)dp[i][j] = false;

    bool flag[MAX];
    for(int i = 0 ; i < MAX ; i++)flag[i] = false;

    dp[0][0] = true;
    for(int i = 0 ; i <= V ; i++){
      for(int j = 0 ; j < d ; j++){
	if(!dp[i][j])continue;
	int c = coins[j];
	for(int k = 0 ; k < C ; k++){
	  if(i+c > V)continue;
	  dp[i][j+1] = true;
	  dp[i+c][j+1] = true;
	  flag[i+c] = true;
	  c += coins[j];
	}
      }
    }

    for(int i = 1 ; i <= V ; i++){
      if(!flag[i])return i;
    }

    return -1;
}


int small_solve(){  
  cin >> C >> D >> V;
  vector<int>coins;
  for(int i = 0 ; i < D ; i++){
    int tmp;cin >> tmp;
    coins.push_back(tmp);
  }
  int ret = 0;
  while(1){
    int val = check(coins);
    if(val == -1)break;
    coins.push_back(val);
    ret++;
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  for(int i = 1 ; i <= T ; i++){
    cout << "Case #" << i << ": " << small_solve() << endl;
  }
  return 0;
}
