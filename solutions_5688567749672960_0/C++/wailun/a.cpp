#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

const int MAXN = 1000010;
int dist[1000010];

int flip(int x){
  int ans = 0;
  while(x > 0){
    ans *= 10;
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
    

int main(){
  int ntest = 0;
  cin >> ntest;

  int N = MAXN - 1;
  memset(dist, -1, sizeof dist);
  dist[1] = 1;
  for(int i = 2; i <= N; ++i){
    if(dist[i] == -1){
      dist[i] = dist[i-1] + 1;
    }
    else{
      if(dist[i-1] + 1 < dist[i]){
	dist[i] = dist[i-1] + 1;
      }
    }
    int fi = flip(i);
    if(fi > i && fi < MAXN && dist[fi] == -1){
      dist[fi] = dist[i] + 1;
    }
  }

  
  for(int test = 1; test <= ntest; ++test){
    //int N;
    cin >> N;

    /*
    for(int i = 1; i < N; ++i){
      cout << i << " " << dist[i] << "\n";
    }
    cout << "\n";
    */
    
    cout << "Case #" << test << ": ";

    cout << dist[N];

    cout << "\n";
  }

  return 0;
}
