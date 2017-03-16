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

int T, cnt[26];
string s, ans = "";

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &T);
  for(int t=1; t<=T; t++){
    cin >> s;
    for(int i=0; i<s.size(); i++)
      cnt[s[i]-'A']++;
    while(cnt['Z'-'A']){
      ans.push_back('0');
      cnt['Z'-'A']--;
      cnt['E'-'A']--;
      cnt['R'-'A']--;
      cnt['O'-'A']--;
    }
    while(cnt['U'-'A']){
      ans.push_back('4');
      cnt['F'-'A']--;
      cnt['O'-'A']--;
      cnt['U'-'A']--;
      cnt['R'-'A']--;
    }
    while(cnt['W'-'A']){
      ans.push_back('2');
      cnt['T'-'A']--;
      cnt['O'-'A']--;
      cnt['W'-'A']--;
    }
    while(cnt['X'-'A']){
      ans.push_back('6');
      cnt['S'-'A']--;
      cnt['I'-'A']--;
      cnt['X'-'A']--;
    }
    while(cnt['G'-'A']){
      ans.push_back('8');
      cnt['E'-'A']--;
      cnt['I'-'A']--;
      cnt['G'-'A']--;
      cnt['T'-'A']--;
      cnt['H'-'A']--;
    }
    while(cnt['F'-'A']){
      ans.push_back('5');
      cnt['F'-'A']--;
      cnt['I'-'A']--;
      cnt['V'-'A']--;
      cnt['E'-'A']--;
    }
    while(cnt['H'-'A']){
      ans.push_back('3');
      cnt['T'-'A']--;
      cnt['H'-'A']--;
      cnt['R'-'A']--;
      cnt['E'-'A'] -= 2;
    }
    while(cnt['O'-'A']){
      ans.push_back('1');
      cnt['O'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
    }
    while(cnt['V'-'A']){
      ans.push_back('7');
      cnt['S'-'A']--;
      cnt['E'-'A'] -= 2;
      cnt['V'-'A']--;
      cnt['N'-'A']--;
    }
    while(cnt['I'-'A']){
      ans.push_back('9');
      cnt['N'-'A']--;
      cnt['I'-'A']--;
      cnt['N'-'A']--;
      cnt['E'-'A']--;
    }
    sort(ans.begin(), ans.end());
    cout << "Case #" << t << ": ";
    cout << ans << "\n";
    ans.clear();
  }
  return 0;
}
