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

ll T, ans, t = 0;
string s;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  while(T--){
    cin >> s;
    ans = (s[s.size() - 1] == '-');
    cout << "Case #" << ++t << ": ";
    for(int i=1; i<s.size(); i++)
      ans += (s[i] != s[i-1]);
    cout << ans << "\n";
  }
  return 0;
}
