#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 10*1024;
int T;
int E,R,N;
int v[MAXN];


int sol(){
  int total_gain = 0;
  int right;
  int now_E = E;
  for (int left = 1; left <= N; left++){
    int t = now_E;
    int left_gain = 0;
    int left_spend = 0;
    int left_E = now_E;
   
    if (t < E){
      right = left;
      while (t <= E){
        if (right > N)
          break;
        t += R;
        if (v[left] < v[right])
          break;
        right++;
      }
      if (right > N){
        left_spend = now_E;
        total_gain += v[left]*left_spend;
        now_E = R;
        continue;
      }
      if (t >= E){
        left_spend = t-E;
        total_gain += v[left]*left_spend;
        now_E = now_E - left_spend + R;
        continue;
      }
      now_E += R;
      continue;
    }

    for (right = left; right<=N; right++){
      if (left_spend >= E || left_E <= 0 || v[left] < v[right]){
        break;
      }
      int spend = min(min(left_E, R), E-left_spend);
      left_E -= spend;
      left_spend += spend;
    }
    if (right > N){
      left_spend = E;
      left_E = (right-left-1)*R;
    }
    left_gain = v[left]*left_spend;
    total_gain += left_gain;
    now_E = now_E - left_spend + R;
  }
  return total_gain;

}

int main(){
  scanf("%d", &T);
  for (int t = 1; t <= T; t++){
    scanf("%d %d %d", &E, &R, &N);
    for (int i = 1; i <= N; i++){
      scanf("%d", &v[i]);
    }

    int ans = sol();
    printf("Case #%d: %d\n", t, ans);
  }
}

