#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool
cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return ((a.second > b.second) || (a.first > b.first));
}

int
solve(int S, int p, const vector<int>& t) {
  int result = 0;
  vector<pair<int, int> > max_score(t.size());
  int ds[] = {1, 1, 2};
  int d[] = {0, 1, 1};
  
  for(int i = 0; i < t.size(); i++) {
    if(t[i] > 2) {
      max_score[i] = make_pair(t[i]/3+ds[t[i]%3], t[i]/3+d[t[i]%3]);
    } else if(t[i] == 2) {
      max_score[i] = make_pair(t[i], 1);
    } else {
      max_score[i] = make_pair(-1, t[i]);
    }
  }
  
  sort(max_score.begin(), max_score.end(), cmp);
  
  vector<pair<int, int> >::iterator i = max_score.begin();
  while(i != max_score.end()) {
    if((*i).second >= p) {
      result++;
    } else if(((*i).first >= p) && (S > 0)) {
      result++;
      S--;
    } else {
      break;
    }
    i++;
  }
  
  return result;
}

int
main() {
  int T;
  int S;
  int p;
  int N;
  
  cin >> T;
  
  for(int i = 1; i <= T; i++) {
    cin >> N >> S >> p;
    
    vector<int> t(N);
    for(int j = 0; j < N; j++) {
      cin >> t[j];
    }
    
    cout << "Case #" << i << ": " << solve(S, p, t) << endl;
  }
  
  return 0;
}
