#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
char s[N];

vector <string> rem = {"ZERO", "SIX", "TWO", "SEVEN", "EIGHT", "FOUR", "ONE", "FIVE", "THREE", "NINE"};
vector <int> val = {0, 6, 2, 7, 8, 4, 1, 5, 3, 9};

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    scanf("%s", s);
    int n = strlen(s);
    
    int cnt[26] = {0};
    
    for(int i = 0; i < n; ++i) {
      int x = s[i] - 'A';
      cnt[x]++;
    }
    int cnt1[10] = {0};
    for(int i = 0; i < 10; ++i) {
      while(true) {
        bool good = true;
        for(int j = 0; j < rem[i].size(); ++j) {
          if(cnt[rem[i][j] - 'A'] <= 0) {
            good = false;
            break;
          }
        }
        if(!good) break;
        cnt1[i]++;
        for(int j = 0; j < rem[i].size(); ++j) {
          cnt[rem[i][j] - 'A']--;
        }
      }
    }
    for(int i = 0; i < 26; ++i) {
      assert(cnt[i] == 0);
    }
    printf("Case #%d: ", tt);
    vector <int> ans;
    for(int i = 0; i < 10; ++i) {
      while(cnt1[i]--) {
        ans.push_back(val[i]);
      }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); ++i) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return (0);
}
