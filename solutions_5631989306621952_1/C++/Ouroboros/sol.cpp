#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
  int T;
  cin >> T;
  for (int t = 1;t <= T;t++) {
    string st;
    cin >> st;
    vector<pair<char,int>> letter;
    vector<bool> left(st.size(),false);
    for (size_t i = 0;i < st.size();i++) {
      letter.push_back({st[i],i});
    }
    sort(letter.begin(), letter.end());

//    for (size_t i = 0;i < st.size();i++) {
//      cout << letter[i].first << ":" << letter[i].second << endl;
//    }


    int last = st.size()+1;
    for (int i = st.size()-1;i >= 0;i--) {
      if (letter[i].second < last) {
        last = letter[i].second;
        left[letter[i].second] = true;
      }
    }

    //process
    deque<char> ans;
    for (size_t i = 0;i < st.size();i++) {
      if (left[i])
        ans.push_front(st[i]);
      else
        ans.push_back(st[i]);
    }

    printf("Case #%i: ",t);
    while (ans.empty() == false) {
      cout << ans.front();
      ans.pop_front();
    }
    cout << endl;




  }
} 
