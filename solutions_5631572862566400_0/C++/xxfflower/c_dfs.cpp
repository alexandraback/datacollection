#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void print(const vector<int>& cur, bool link) {
  for(auto v : cur)
    cerr<<v<<" ";
  cerr<<(link ? "}":"|");  
  cerr<<endl;
}

bool is_valid(const vector<int>& cur, const vector<int>& bff)
{
  if(cur.size()==1) return false;

  for(int i=0;i<cur.size();++i)
  {
    int l = ((i-1) + cur.size()) % cur.size();
    int r = (i+1) % cur.size();

    if(bff[cur[i]] != cur[l] && bff[cur[i]] != cur[r]) return false;
  }  

  return true;
}

void dfs(int dep, int s, vector<int>& cur, set<int>& used, int& ans, const vector<int>& bff, const int N) {
  cur.push_back(s);
  used.insert(s);

  if(dep > ans && is_valid(cur, bff)) {
    ans = dep;
    print(cur, true);
  }

  for(int i=1;i<=N;++i)
  {
    if(used.count(i)) continue;
    
    // if(bff[cur.back()] == i 
    // || bff[i] == cur.back() 
    // || bff[i] == cur.front() 
    // || bff[cur.front()] == i) {
      dfs(dep+1, i, cur, used, ans, bff, N);
    // }
  }

  used.erase(s);
  cur.pop_back();
}

int main() {
  int t, N, n;
  int ans = 0;
  string line;


  cin>>t;  
  for(int c=1;c<=t;++c)
  {
    cin>>N;

    vector<int> bff(N+1);

    for(int i=1;i<=N;++i)
      cin>>bff[i];

    int ans = 0;    

    for(int i=1;i<=N;++i)
    {
      vector<int> cur;
      set<int> used;
      dfs(1, i, cur, used, ans, bff, N);    
    }

    cout<<"Case #"<<c<<": "<<ans<<endl;  
  }

  return  0;
}