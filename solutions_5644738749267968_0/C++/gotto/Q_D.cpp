#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T;
int N;
double a[1111];
double b[1111];
int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a,a+N);
    for(int i = 0; i < N; i++) cin >> b[i];
    sort(b,b+N);

    cout << "Case #" << t << ": ";

    int ans = 0;    
    int j = 0;
    for(int i = 0; i < N; i++){
      for(; j < N; j++){
	if(a[j] > b[i]){
	  j++;
	  ans++;
	  break;
	}
      }
    }
    cout << ans << " ";

    ans = 0;
    j = 0;
    for(int i = 0; i < N; i++){
      bool f = false;
      for(; j < N; j++){
	if(a[i] < b[j]){
	  j++;
	  f = true;
	  break;
	}
      }
      if(f) continue;
      if(j >= N) ans++;
    }
    cout << ans << endl;
  }
}
