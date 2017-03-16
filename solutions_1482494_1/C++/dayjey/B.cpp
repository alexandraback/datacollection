#include <iostream>
#include <cstring>

using namespace std;

int s1[1001];
int s2[1001];
int d1[1001];
int d2[1001];

int main() {
  int tc_cnt;
  cin >> tc_cnt;
  for (int tc = 1; tc <= tc_cnt; tc++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s1[i] >> s2[i];
    }
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    
    int completed = 0;
    int total = 0;
    int played = 0;
    int total_old;
    PLAY: do {
      total_old = total;
      for (int i = 0; i < n; i++) {
        if (d1[i]) continue;
        if (s2[i] <= total) {
          played++;
          total += 2;
          d1[i] = 1;
          d2[i] = 1;
          completed++;
        }
      }
      if (total > total_old) goto PLAY;
      
      for (int i = 0; i < n; i++) {
        if (d2[i] || !d1[i]) continue;
        if (s2[i] <= total) {
          played++;
          total++;
          d2[i] = 1;
          completed++;
          goto PLAY;
        }
      }
      
      int max = -1;
      int max_id = -1;
      for (int i = 0; i < n; i++) {
        if (d1[i]) continue;
        if (s1[i] <= total) {
          if (s2[i] > max) {
            max = s2[i];
            max_id = i;
          }
        }
      }
      if (max_id != -1) {
        played++;
        total++;
        d1[max_id] = 1;
      }
    }
    while (total > total_old);
    
    cout << "Case #" << tc << ": ";
    if (completed < n) {
      cout << "Too Bad";
    } else {
      cout << played;
    }
    cout << endl;
  }
  return 0;
}
