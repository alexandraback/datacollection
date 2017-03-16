#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

ll T, n, arr[10], cnt, t = 0;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  while(T--){
    cin >> n;
    memset(arr, 0, sizeof arr);
    cnt = 0;
    cout << "Case #" << ++t << ": ";
    if(n == 0){
      puts("INSOMNIA");
      continue;
    }
    ll x, i;
    for(i=1; cnt<10; i++){
      x = i * n;
      while(x){
        int a = x % 10;
        x /= 10;
        cnt += !arr[a];
        arr[a] = 1;
      }
    }
    cout << n * --i << "\n";
  }
  return 0;
}
