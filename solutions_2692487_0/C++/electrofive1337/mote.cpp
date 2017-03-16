#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int tests, rt = 0;
  in >> tests;
  while(tests--){
    ++rt;
    int a, n;
    vector<int> m;
    in >> a >> n;
    for(int i = 1; i <= n; ++i){
      int x;
      in >> x;
      m.push_back(x);
    }

    sort(m.begin(), m.end());

    int ans = 0, p = 0, now = 0;
    while(p < m.size()){
      if(m[p] >= a)
        break;
      a += m[p];
      ++p;
    }
    ans = m.size() - p;

    while(p < m.size()){
      if(a == 1)
        break;
      a += a - 1;
      ++now;
      while(p < m.size() && m[p] < a){
        a += m[p];
        ++p;
      }
      ans = min(ans, now + (int)m.size() - p);
    }

    out << "Case #" << rt << ": " << ans;
    if(tests)
      out << "\n";
  }
}
