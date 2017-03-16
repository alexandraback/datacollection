#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 101, maxm = 1000000007;
int t, n;

int V(char ch) {
  return (int)ch-(int)'a'; 
}

int Ans() {
  string str[maxn];
  int exis[26];
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) exis[j] = 0;
    for (int j = 0; j < n; j++)
      if (j != i) {
        for (int k = 0; k < str[j].length(); k++)
          exis[V(str[j][k])] = 1;
      }
    int l = 1, r = str[i].length()-2;
    while (l<str[i].length() && str[i][l]==str[i][l-1]) l++;
    while (r>=0 &&str[i][r]==str[i][r+1]) r--;
    for (int j = l; j <= r; j++) 
      if (exis[(int)str[i][j]-(int)'a'] == 1) return 0;
  }
  for (int i = 0; i < n; i++) str[i][1] = str[i][str[i].length()-1];
  int sum = n<<1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) exis[j] = 0;
    for (int j = 0; j < n; j++)
      if (j!=i && str[j][0]!=str[j][1]) {
        exis[V(str[j][0])]++;
        exis[V(str[j][1])]++;
      }
    if (str[i][0] != str[i][1]) {
      if (exis[V(str[i][0])] > 1) return 1;
      if (exis[V(str[i][1])] > 1) return 1;
    }
    if (exis[V(str[i][0])] > 0) sum--;
    if (exis[V(str[i][1])] > 0) sum--;
  }
  sum = sum>>1;
  int ans = 1;
  for (int i = 1; i < sum; i++) ans = (ans<<1)%maxm;
  return ans;
}

int main()
{
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  cin >> t;
  for (int count = 1; count <= t; count++) {
    cin >> n;
    cout << "Case #" << count << ": " << Ans() << endl;
  }
}
