#include <climits>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
const int N=521196;
vector<string> w;
vector<int> lw;
int cost[55];

void run(int case_index) {
  int res=0, d, n;
  string s; cin>>s; n=s.size();
  memset(cost,0,sizeof cost);
  for (int i = n-1; i >=0 ; i--){
    cost[i]=n-i;
    for (int k = 0; k < N; k++){
      if(i+lw[k]<=n){
        d=0; for (int j = 0; j < lw[k]; j++){
          if(abs(s[i+j]-w[k][j])<5)
            d += s[i+j]!=w[k][j];
          else{
            d = 1000; break;
          }
        }
        if(d+cost[i+lw[k]]<cost[i])
          cost[i] = d+cost[i+lw[k]];
      }
    }
  }
  res = cost[0];
  cout << "Case #" << case_index << ": " << res;
  cout << endl;
}

int main(int argc, char* argv[]) {
  ifstream f; f.open ("garbled_email_dictionary.txt");
  w.resize(N), lw.resize(N); 
  for (int i = 0; i < N; i++) f>>w[i], lw[i]=w[i].size();
  f.close();
  int n; 
  cin >> n;
  for(int i = 1; i <= n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
