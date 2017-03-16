#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

int freq[128];
int cnt[10];

/*
"ZERO", Z
"SIX", X
"FOUR", U
"EIGHT", G
"THREE", R
"TWO",  W
"ONE", O
"FIVE", F
"SEVEN", V
"NINE" N

 *
 */

int countOccs(const string& digit, char c) {
  int wordCount = freq[c];
  for(int i = 0; i < digit.size(); i++) {
    assert(freq[digit[i]] >= wordCount);
    freq[digit[i]] -= wordCount;
  }
  return wordCount;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  string S;

  for(int tt = 1; tt <= T; tt++) {
    cin >> S;
    for(int i = 0; i < S.size(); i++) {
      ++freq[S[i]];
    }
    cnt[0] = countOccs("ZERO", 'Z');
    cnt[6] = countOccs("SIX", 'X');
    cnt[4] = countOccs("FOUR", 'U');
    cnt[8] = countOccs("EIGHT", 'G');
    cnt[3] = countOccs("THREE", 'R');
    cnt[2] = countOccs("TWO", 'W');
    cnt[1] = countOccs("ONE", 'O');
    cnt[5] = countOccs("FIVE", 'F');
    cnt[7] = countOccs("SEVEN", 'V');
    cnt[9] = countOccs("NINE", 'I');

    int _sum = 0;
    for(int i = 0; i < 128; i++) {
      _sum += freq[i];
    }
    assert(_sum == 0);

    cout << "Case #" << tt << ": ";
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < cnt[i]; j++) {
        cout << i;
      }
    }
    cout << endl;
  }

  return 0;
}
