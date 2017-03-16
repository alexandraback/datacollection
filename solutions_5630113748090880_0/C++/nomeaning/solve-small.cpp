#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > lists;
vector<vector<int> > map;
vector<bool> used;
int N;
vector<int> rcandi;

bool greater_l(const vector<int> &a, const vector<int> &b) {
  for(int i = 0; i < N; i++) {
    if(a[i] <= b[i]) return false;
  }
  return true;
}
void solve(int row) {
  if(map.size() == N) {
    // check it
    vector<bool> uc = used;
    int candi = -1;
    for(int j = 0; j < N; j++) {
      bool found = false;
      for(int i = 0; i < lists.size(); i++) {
        if(uc[i] == false) {
          bool matched = true;
          for(int k = 0; k < N; k++) {
            if(map[k][j] != lists[i][k]) {
              matched=  false;
            }
          }
          if(matched) {
            uc[i] = true;
            found = true;
            break;
          }
        }
      }
      if(!found) {
        if(candi == -1) {
          candi = j;
        }else {
          candi = -1;break;
        }
      }
    }
    if(candi != -1) {
      rcandi.clear();
      for(int i = 0; i < N; i++) {
        rcandi.push_back(map[i][candi]);
      }
    }
  }else if(row == lists.size()) {
    return;
  }else{
    solve(row + 1);
    if(map.size() == 0 || greater_l(lists[row], map.back())){
      used[row] = true;
      map.push_back(lists[row]);
      solve(row+1);
      map.pop_back();
      used[row] = false;
    }
  }
}
int main() {
  int T;
  cin >>T;
  for(int caze = 1; caze <= T; caze++) {
    cout << "Case #" << caze << ":";
    cin >> N;
    lists = vector<vector<int>>(N*2-1);
    for(int i = 0; i < N * 2 - 1; i++) {
      lists[i] = vector<int>(N);
      for(int j = 0; j < N; j++) {
        cin >> lists[i][j];
      }
    }
    sort(lists.begin(), lists.end());
    map.clear();
    used = vector<bool>(N*2-1);
    solve(0);
    for(int i = 0; i < N; i++) {
      cout << " " << rcandi[i];
    }
    cout << endl;
  }
}
