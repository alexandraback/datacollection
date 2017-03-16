#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(){
  int T, N;
  scanf("%d", &T);
  for(int t = 1; t<=T; t++){
    scanf("%d", &N);
    vector<string> first(N);
    vector<string> second(N);
    vector<pair<int, int>> index(N);
    vector<int> flip(N);
    vector<int> fcnt(N), scnt(N);
    int maxfake = 0;
    for(int j=0; j<N; j++){
      cin >> first[j] >> second[j];
      pair<int, int> idx;
      idx.first = idx.second = -1;
      for(int k=0; k<=j; k++){
        if((first[k].compare(first[j]) == 0) && idx.first == -1){
          idx.first = k; fcnt[k] += 1;
        }
        if((second[k].compare(second[j]) == 0) && idx.second == -1){
          idx.second = k; scnt[k] += 1;
        }
      }
      index[j] = idx;
    }
    int fake = 0;
    int max = 1;
    vector<int> ftcnt(N), stcnt(N);
    for(int n = N-1; n >= 0; n--)
      max *= 2;
    for(int exc = 0; exc < max; exc++){
      bool flag = true;
      fake = 0;
      ftcnt = fcnt;
      stcnt = scnt;
      int exct = exc;
      for(int n = N-1; n >= 0; n--){
        flip[n] = (exct % 2);
        if(flip[n] == 1) fake += 1;
        exct /= 2;
      }
      for(int n = 0; n <= N-1; n++){
        ftcnt[index[n].first] -= flip[n];
        if(ftcnt[index[n].first] == 0){
          flag = false;
          break;
        }
        stcnt[index[n].second] -= flip[n];
        if(stcnt[index[n].second] == 0){
          flag = false; break;
        }
      }
      if(!flag) continue;
      else if(fake > maxfake){
        maxfake = fake;
      }
    }
    printf("Case #%d: %d\n", t, maxfake);
  }
  return 0;
}
