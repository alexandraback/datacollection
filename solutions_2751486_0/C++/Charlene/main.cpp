#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <set>
using namespace std;

int N;
string s;
set<char> vowels;

void init()
{
  cin >> s >> N;
}

long long deal()
{
  vector<pair<int, int> > v;
  vector<int> consonants(s.length(), 0);
  vector<int> posi(s.length(), 0);
  
  if (vowels.find(s[0]) == vowels.end()) consonants[0] = 1;
  
  for (int i = 1; i < s.length(); i ++) {
    if (vowels.find(s[i]) == vowels.end()) {
      consonants[i] = consonants[i - 1] + 1;
    }
  }
  
  int cnt = 0;
  for (int i = 0; i < s.length(); ) {
    while (i < s.length() && consonants[i] < N) {
      cnt ++;
      i ++;
    }
    
    if (cnt > 0) {
      if (i < s.length() && consonants[i] == N) {
        v.push_back(make_pair(cnt - N + 1, -1));
      } else if (i == s.length()) {
        v.push_back(make_pair(cnt - N - 1, -1));
      } else v.push_back(make_pair(cnt, -1));
    }
    cnt = 0;
    
    while (i < s.length() && consonants[i] >= N) {
      cnt ++;
      i ++;
    }
    
    
    if (cnt > 0) {
      if (v.size() == 0) v.push_back(make_pair(0, -1));
      v.push_back(make_pair(N + cnt - 1, 1));
      posi[v.size() - 1] = i;
      cnt = N - 1;
    }
  }
  
  long long ans = 0;
  
  for (int i = 0; i < v.size(); i ++) {
//    cout << v[i].first << ' ' << v[i].second << ' ' << posi[i] << endl;
    if (v[i].second == 1) {
      vector<int> cnts;
//      cout << v[i].first << endl;
      for (int j = N; j <= v[i].first; j ++) {
        cnts.push_back(v[i - 1].first + 1 + j - N);
      }
      
      if (i < v.size() - 1) {
        cnts[cnts.size() - 1] *= (s.length() - posi[i] + 1);
      }
      
      for (int k = 0; k < cnts.size(); k ++) {
        ans += cnts[k];
      }
    }
  }
  
  return ans;
}

int main()
{
//  freopen("/Users/yingjiang/TopCoder/Codejam/3a.in", "r", stdin);
  freopen("/Users/yingjiang/Downloads/A-small-attempt0-2.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/3a.out", "w", stdout);
  
  
  vowels.insert('a');
  vowels.insert('e');
  vowels.insert('i');
  vowels.insert('o');
  vowels.insert('u');
  
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test)
  {
    init();
    cout << "Case #" << test << ": " << deal() << endl;
  }
  return 0;
}