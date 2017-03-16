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
  int T;
  string cq, jq;
  scanf("%d", &T);
  for(int i=1; i<=T; i++){
    cin >> cq >> jq;
    int len = cq.length();
    vector<int> c(len), j(len);
    vector<int> resc(len), resj(len);
    for(int k=0; k<len; k++)
      c[k] = j[k] = 0;
    int max = 1;
    int diff = 1000;
    for(int k = len; k > 0; k--)
      max *= 10;
    for(int k = 0; k < max; k++){
      int flag = true;
      int kt = k;
      for(int idx = len-1; idx >= 0; idx--){
        c[idx] = (kt % 10);
        kt /= 10;
        if(cq[idx] != '?' && (cq[idx] - '0') != c[idx]){
          flag = false;
          break;
        }
      }
      if(!flag) { flag = true; continue;}
      for(int l = 0; l < max; l++){
        int lt = l;
        for(int idx = len-1; idx >= 0; idx--){
          j[idx] = (lt % 10);
          lt /= 10;
          if(jq[idx] != '?' && (jq[idx] - '0') != j[idx]){
            flag = false;
            break;
          }
        }
        if(!flag) {flag = true; continue;}
        if(diff > abs(k - l)){
          diff = abs(k - l);
          for(int idx = 0; idx <= len-1; idx++){
            resc[idx] = c[idx];
            resj[idx] = j[idx];
          }
        }
      }
    }
    printf("Case #%d: ", i);
    for(int k=0; k<len; k++)
      printf("%d", resc[k]);
    printf(" ");
    for(int k=0; k<len; k++)
      printf("%d", resj[k]);
    printf("\n");
  }
  return 0;
}
