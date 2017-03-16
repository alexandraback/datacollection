#include <iostream>
#include <algorithm>

using namespace std;

bool used1[20];
bool used2[20];
bool ans;
int data[20];
int n;
int sum1, sum2;

void solve2(int p){
  if(ans) return;
  if(p == n){
    if(sum1 == sum2){
      ans = true;
    }
    return;
  }
  if(!used1[p]){
    used2[p] = true;
    sum2 += data[p];
    solve2(p+1);
    if(ans) return;
    sum2 -= data[p];
    used2[p] = false;
  }
  solve2(p+1);
}

void solve(int p){
  if(ans) return;
  if(p == n){
    solve2(0);
    return;
  }
  used1[p] = true;
  sum1 += data[p];
  solve(p+1);
  if(ans) return;
  sum1 -= data[p];
  used1[p] = false;
  solve(p+1);
}

main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    cin >> n;
    for(int i=0;i<n;i++) cin >> data[i];
    ans = false;
    fill(used1, used1+20, false);
    fill(used2, used2+20, false);
    sum1 = sum2 = 0;
    solve(0);
    cout << "Case #" << t << ":" << endl;
    if(ans){
      bool f = true;
      for(int i=0;i<20;i++){
        if(used1[i]){
          if(!f) cout << " ";
          cout << data[i];
          f = false;
        }
      }
      cout << endl;
      f = true;
      for(int i=0;i<20;i++){
        if(used2[i]){
          if(!f) cout << " ";
          cout << data[i];
          f = false;
        }
      }
      cout << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
}

