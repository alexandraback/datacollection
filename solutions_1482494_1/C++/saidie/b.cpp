#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;

int n;
pair<int, int> p[N];
int state[N];

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t; ++k){
    cin >> n;
    fill_n(state, n, 0);
    for(int i = 0; i < n; ++i)
      cin >> p[i].first >> p[i].second;
    sort(p, p+n);

    int star = 0, cnt = 0, comp = 0;
    while(comp < n){
      int tar = -1;
      for(int i = 0; i < n && p[i].first <= star; ++i){
        if(state[i] != 2 && p[i].second <= star){
          star += state[i] == 0 ? 2 : 1;
          state[i] = 2;
          tar = -2;
          ++cnt;
          ++comp;
          break;
        }
        if(state[i] == 0){
          if(tar == -1 || p[i].second > p[tar].second)
            tar = i;
        }
      }

      if(tar == -1)
        break;
      if(tar != -2){
        state[tar] = 1;
        ++star;
        ++cnt;
      }
    }

    cout << "Case #" << k+1 << ": ";
    if(comp != n)
      cout << "Too Bad" << endl;
    else
      cout << cnt << endl;
  }

  return 0;
}
