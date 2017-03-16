#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rep(a,b) fr(a,0,b)
#define fst first
#define snd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
 
const int oo = 0x3f3f3f3f;
 
typedef long long ll;
typedef pair<int,int> pii;

int cnt[26];

int main() {
  vector<int> order = {0,2,4,6,5,7,1,9,3,8};
  vector<string> eng =
      {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  
  int T;
  cin >> T;
  fr(caso,1,T+1) {
    memset(cnt, 0, sizeof cnt);
    
    string inp;
    cin >> inp;
    for (char c : inp) ++cnt[c - 'A'];
    
    vector<int> numbers;
    for (int i = 0; i < order.size(); ) {
      int x = order[i];
      bool found = true;
      for (char c : eng[x]) found &= (cnt[c - 'A'] > 0);
      if (found) {
        numbers.push_back(x);
        for (char c : eng[x]) --cnt[c - 'A'];
      } else {
        ++i;
      }
    }
    
    for (int i = 0; i < 26; ++i) assert(cnt[i] == 0);
    
    
    printf("Case #%d: ", caso);
    sort(numbers.begin(), numbers.end());
    for (int x : numbers) printf("%d", x);
    printf("\n");
  }
  
  return 0;
}