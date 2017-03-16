#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
  int t0, t;
  int n, m, b;
  int table[1000][1000];
  stack<int> st;
  vector<int> r;
  bool flg = false;

  cin >> t0;
  t = t0;
  while(t--){
    flg = false;
    cin >> n;
    cout << "Case #" << t0 - t << ": ";
    for(int i = 0; i < 1000; ++i){
      for(int j = 0; j < 1000; ++j)
        table[i][j] = 0;
    }
    for(int i = 0; i < n; ++i){
      cin >> m;
      for(int j = 0; j < m; ++j){
        cin >> b;
        table[i][b - 1] = 1;
      }
    }
    for(int i = 0; i < n; ++i){
      r.clear();
      st.push(i);
      while(!st.empty()){
        b = st.top();
        st.pop();
        for(int j = 0; j < r.size(); ++j){
          if(r.at(j) == b && b != i){
            cout << "Yes" << endl;
            flg = true;
            break;
          }
        }
        r.push_back(b);
        for(int k = 0; k < n; ++k){
          if(table[b][k] == 1)
            st.push(k);
        }
        if(flg)
          break;
      }
      if(flg)
        break;
    }
    if(!flg)
      cout << "No"<< endl;
    while(!st.empty())
      st.pop();
  }
  return 0;
}
