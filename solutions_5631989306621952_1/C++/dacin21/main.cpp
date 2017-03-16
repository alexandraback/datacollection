#include <bits/stdc++.h>

using namespace std;

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin.tie(0);
  int T;
  cin >> T;
  for(int i=0;i<T;++i){
      cout << "Case #"<<i+1<<": ";
    string s;
    cin >> s;
    deque<char> d;
    for(auto &e:s){
      if(d.empty())d.push_back(e);
      else if(e >=d.front())d.push_front(e);
      else d.push_back(e);
    }
    while(!d.empty()){
      cout << d.front();
      d.pop_front();
    }
    cout << "\n";
  }


  return 0;
}





