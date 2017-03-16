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

int T, N;
map<string, int> m1, m2;
pair<string, string> arr[1234];

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &T);
  for(int t=1; t<=T; t++){
    int ans = 0;
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> arr[i].first;
      cin >> arr[i].second;
    }
    sort(arr, arr+N);
    for(int i=0; i<N; i++){
      m1[arr[i].first]++;
      m2[arr[i].second]++;
      if(m1[arr[i].first] > 1 && m2[arr[i].second] > 1){
        ans++;
      }
    }
    m1.clear();
    m2.clear();
    cout << "Case #" << t << ": ";
    cout << ans << "\n";
  }
  return 0;
}
