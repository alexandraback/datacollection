#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>
#include <ctime>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
  int TC; cin >> TC;
  srand(time(NULL));
  for (int t = 1; t <= TC; t++) {
    
    printf("Case #%d:\n", t);
    int R, N, M, K; cin >> R >> N >> M >> K;
    for(int i = 0; i < R; ++i) {
      vi nums(M+1, 0);
      for(int j = 0; j < K; ++j) {
        int num; cin >> num;
        for(int l = 2; l <= M; ++l) {
          int count = 0;
          while(num % l == 0) {
            count++;
            num /= l;
          }
          nums[l] = max(nums[l], count);
        }
      }
      int count = 0;
      for(int j = 3; j <= M; ++j) {
        for(int l = 0; l < nums[j]; ++l) {
          cout << j;
          count++;
        }
      }
      while(count < N && nums[2]) {
        int num = 1;
        int used = 0;
        for(int j = 0; j < nums[2] && num*2 <= M; ++j) {
          num *= 2;
          used++;
        }
        cout << num;
        count++;
        nums[2] -= used;
      } 
      while (count < N) {
        cout << rand() % (M-1) + 2;
        count++;
      }
      cout << endl;
    }
  }


  return 0;
}
