#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef vector<int> vi;

const int maxh = 2510;
const int maxn = 100;

int n;
int hei[maxh];

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> n;
    memset(hei,0,sizeof(hei));
    for(int i = 0; i < 2*n-1; ++i){
      for(int j = 0; j < n; ++j){
	int x; cin >> x;
	++hei[x];
      }
    }
    vi sol;
    for(int i = 0; i < maxh; ++i) if(hei[i]%2) sol.push_back(i);
    sort(sol.begin(),sol.end());
    cout << "Case #" << cass << ":";
    for(int i = 0; i < n; ++i){
      cout << ' ' << sol[i];
    }
    cout << '\n';
  }
}