#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
using namespace std;
int deletion[10] = {0, 8, 3, 4, 2, 6, 7, 5, 1, 9};
int deleteIndex[10][5] = {
  {26, 5, 18, 15, 0}, {15, 14, 5, 0, 0}, {20, 23, 15, 0, 0},
  {20, 8, 18, 5, 5}, {6, 15, 21, 18, 0}, {6, 9, 22, 5, 0},
  {19, 9, 24, 0, 0}, {19, 5, 22, 5, 14}, {5, 9, 7, 8, 20},
  {14, 9, 14, 5}
};
int deleteCenter[10] = {26, 15, 23, 8, 21, 22, 24, 19, 7, 9};
int main(){

  vector<int> alpha(27);
  int T;
  for(int i=0; i<27; i++)
    alpha[i] = 0;
  string s;
  scanf("%d", &T);
  for(int i=1; i<=T; i++){
    vector<int> cnt(10);
    for(int j=0; j<10; j++)
      cnt[j] = 0;
    for(int j=0; j<27; j++)
      alpha[j] = 0;
    cin >> s;
    for(char c : s){
      alpha[(int)(c - 'A' + 1)] += 1;
    }
    for(int j=0; j<10; j++){
      int factor = alpha[deleteCenter[deletion[j]]];
      cnt[deletion[j]] += factor;
      for(int k=0; k<5; k++){
        alpha[deleteIndex[deletion[j]][k]] -= factor;
      }
    }
    printf("Case #%d: ", i);
    for(int j=0; j<10; j++){
      for(int k=0; k<cnt[j]; k++){
        printf("%d", j);
      }
    }
    printf("\n");
  }
  return 0;
}
