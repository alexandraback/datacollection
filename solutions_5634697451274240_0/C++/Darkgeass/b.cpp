#include <iostream>
#include <vector>

using namespace std;

#define MAXN 200
int n;
string pancake;

int main(){
  int t; cin >> t;
  for(int cass = 1; cass <= t; ++cass){
    cin >> pancake;
    n = pancake.size();
    int sol = 0;
    for(int i = 0; i < n-1; ++i) if(pancake[i] != pancake[i+1]) ++sol;
    if(pancake[n-1] == '-') ++sol;
    cout << "Case #" << cass << ": " << sol << '\n';
  }
}