#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

unsigned long long reverse(unsigned long long n){
  stringstream ss;
  string s;
  ss << n;
  ss >> s;
  std::reverse(std::begin(s), std::end(s));
  return stoull(s);
}

int main(){
  int T;
  cin >> T;
  for(int t=1; t <=T; ++t){
    unsigned long long N;
    unsigned long long count = 1;
    cin >> N;
    set<unsigned long long> visited;
    vector<unsigned long long> current;
    vector<unsigned long long> next;
    current.push_back(1);
    while(true){
      for(auto n: current){
        if(n==N){
          goto done;
        }
        if(visited.count(n)==0){
          visited.insert(n);
          next.push_back(n+1);
          next.push_back(reverse(n));
        }
      }
      current = next;
      next.clear();
      ++count;
    }
done:
    cout << "Case #" << t << ": "<< count  << endl;
  }
}
