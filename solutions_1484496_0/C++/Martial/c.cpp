#include <climits>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;


void run(int case_index) {
  int n; cin>>n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  map<int,set<int> > m;
  for(int s = 1; s < (1<<n); s++){
    int sum=0;
    for(int i = 0; i < n; i++){
      if((s&(1<<i))!=0){
        sum+=a[i];
      }
    }
    m[sum].insert(s);
  }
  
  cout << "Case #" << case_index << ":";
  cout << endl;
  map<int,set<int> >::iterator it;
  set<int>::iterator ii;
  set<int>::iterator jj;
  int i,j;
  for(it=m.begin(); it!=m.end(); it++){
    for(ii=(it->second).begin(); ii!=(it->second).end(); ii++){
      for(jj=(it->second).begin(); jj!=(it->second).end(); jj++){
        i=*ii, j=*jj;
        if((i&j)==0){
          for(int k = 0; k < n; k++){
            if((i&(1<<k))){
              cout << a[k] << " ";
            }
          }
          cout << endl;
          for(int k = 0; k < n; k++){
            if((j&(1<<k))){
              cout << a[k] << " ";
            }
          }
          cout << endl;
          return;
        }
      }
    }
  }
  cout << "Impossible";
  cout << endl;
}

int main(int argc, char* argv[]) {
  int n; 
  cin >> n;
  for(int i = 1; i <= n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
