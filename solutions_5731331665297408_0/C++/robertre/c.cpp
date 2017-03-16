#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool fly(vector<int> & trip, vector<vector<bool> > & flights) {
  stack<int> loc;
  loc.push(trip[0]);
  for(int p=1;p<trip.size();++p) {
    int to = trip[p];
    while(!loc.empty()) {
      int from = loc.top();
      if(flights[from][to]) {
        break;
      } else {
        loc.pop();
      }
    }
    if(loc.empty()) {
      return false;
    }

    loc.push(to);
  }
  return true;
}

string solve() {
  vector<string> zip;
  vector<int> trip;

  int N, M;
  cin>>N>>M;
  for(int i=0;i<N;++i) {
    string z;
    cin>>z;
    zip.push_back(z);
    trip.push_back(i);
  }
  vector<vector<bool> > flights(N, vector<bool>(N, 0));
  for(int i=0;i<M;++i) {
    int a, b;
    cin>>a>>b;
    a--;
    b--;
    flights[a][b] = 1;
    flights[b][a] = 1;
  }

  string best="";
  do {
    bool ok = fly(trip, flights);
    if(ok) {
      string zips;
      for(int i=0;i<N;++i) {
        zips += zip[trip[i]];
      }
      if(best=="") {
        best = zips;
      }
      else if(zips < best) {
        best = zips;
      }
    }
  } while(next_permutation(trip.begin(), trip.end()));

  return best;
}

int main(int argc, char** argv) {
  int ntc = 0;
  cin>>ntc;

  for(int n=1;n<=ntc;++n) {
    string r = solve();
    cout<<"Case #"<<n<<": ";
    cout<<r;
    cout<<endl;
  }
}
