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
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>
#include <complex>
  
#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define INF_LL 9223372036854775
#define EPS 1e-10
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double 

using namespace std;

#define MAX_T 101
#define MAX_B 55

#define int long long

int TEST_CASE;
int B, M;

int Edge[MAX_B][MAX_B];

void init(){
  memset(Edge, 0, sizeof(Edge));
}

void input(){
  init();
  cin >> B >> M;
}

bool check(){

  int n = 1;
  for(int i = 0; i < B-2 && n < M; i++){
    n *= 2;
  }

  return n == M;

}

signed main(){

  cin >> TEST_CASE;

  for(int testCase = 0; testCase < TEST_CASE; testCase++){
    
    input();
    for(int i = 1; i < B; i++){
      for(int j = i+1; j < B; j++){
	Edge[i][j] = 1;
      }
    }
    /*
    if(check()){
      Edge[0][B-1] = 1;
      M--;
    }
    */
    M--;
    Edge[0][B-1] = 1;
    for(int i = B-2; 1 <= i; i--){
      if(M&1){
	Edge[0][i] = 1;
	M--;
      }
      if(1 < i)
	M >>= 1;
    }
    if(M == 0){
      printf("Case #%lld: POSSIBLE\n", testCase+1);
      for(int i = 0; i < B; i++){
	for(int j = 0; j < B; j++){
	  cout << Edge[i][j];
	}
	cout << endl;
      }
    }
    else{
      printf("Case #%lld: IMPOSSIBLE\n", testCase+1);
    }
  }

  return 0;

}
