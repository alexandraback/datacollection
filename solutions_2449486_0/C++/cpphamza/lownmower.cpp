//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int arr[300][300], colbest[300], rowbest[300];
int R, C;

int main() {
  
//    freopen("/Users/hamza/1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/B-small-attempt0.in", "rt", stdin);
  freopen("/Users/hamza/B-small-attempt0.in", "wt", stdout);
  int tt; cin >> tt;
  for(int t = 1 ; t <= tt; t++){
    memset(colbest, -1, sizeof colbest);
    memset(rowbest, -1, sizeof rowbest);
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++)
      for(int j = 0 ; j < C ; j++){
        cin >> arr[i][j];
        if(rowbest[i] == -1 || arr[i][j] > rowbest[i])
          rowbest[i] = arr[i][j];
        if(colbest[j] == -1 || arr[i][j] > colbest[j])
          colbest[j] = arr[i][j];
      }
    
    bool good = true;
    for(int i = 0 ; i < R ; i++)
      for(int j = 0 ; j < C ; j++)
        if(arr[i][j] != rowbest[i] && arr[i][j] != colbest[j])
          good = false;
    
    cout << "Case #" << t << ": " << (good?"YES":"NO") << endl;
  }
  
  return 0;
}
