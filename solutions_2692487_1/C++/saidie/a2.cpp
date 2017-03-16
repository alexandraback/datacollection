#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main(void){
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t){
    int A, N;
    cin >> A >> N;
    int a[N];
    for(int i = 0; i < N; ++i)
      cin >> a[i];

    sort(a, a+N);
    int ans = INT_MAX;
    ll cur = A;
    int cnt = 0;
    for(int i = 0; i < N; ++i){
      if(cur > a[i]){
        cur += a[i];
      }
      else if(cur == 1){
        ans = N;
        goto end;
      }
      else{
        ans = min(ans, cnt + N - i);
        cur += cur - 1;
        --i;
        ++cnt;
      }
    }
    ans = min(ans, cnt);
  end:

    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
