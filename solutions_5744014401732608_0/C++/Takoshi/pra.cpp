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
#define MAX_B 6

int TEST_CASE;
int B, M;

int Edge[MAX_B][MAX_B];

void init(){
  memset(Edge, 0, sizeof(Edge));
}

void input(){
  cin >> B >> M;
}

pair<int, int> next(int x, int y){
  if(x < B-1){
    return pair<int, int>(x+1, y);
  }
  else{
    return pair<int, int>(y+2, y+1);
  }
}

bool used[MAX_B];

int _solve(int pos){

  if(pos == B-1)
    return 1;

  int ret = 0;

  for(int i = 0; i < B; i++){
    if(Edge[pos][i] == 1){
      ret += _solve(i);
    }
  }

  return ret;

}

bool solve(int x, int y){

  if(y > B-2){
    return _solve(0) == M;
  }
  else{
    pair<int, int> Next = next(x, y);
    Edge[y][x] = 0;
    if(solve(Next.first, Next.second))
      return true;
    Edge[y][x] = 1;
    if(solve(Next.first, Next.second))
      return true;
    Edge[y][x] = 0;
    return false;
  }

}

int main(){

  cin >> TEST_CASE;

  for(int testCase = 0; testCase < TEST_CASE; testCase++){
    
    input();

    if(solve(1,0)){
      printf("Case #%d: POSSIBLE\n", testCase+1);
      for(int i = 0; i < B; i++){
	for(int j = 0; j < B; j++){
	  cout << Edge[i][j];
	}
	cout << endl;
      }
    }
    else{
      printf("Case #%d: IMPOSSIBLE\n", testCase+1);
    }

  }

  return 0;

}
