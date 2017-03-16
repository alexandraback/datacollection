#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define LL long long
using namespace std;

ostream& operator<<(ostream& s, const vector<int>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}



// motes sorted, init = initial size of mote
int sim(vector<int> motes, int init){

  int motes_eaten = 0;
  int size = init;
  int moves = 0;

  // Eacn time we add a mote, we have the option of deleting everything
  vector<int> delete_everything;

  while(motes_eaten < motes.size()){

    // Eat the next mote if we can
    int next_mote = motes[motes_eaten];
    if(next_mote < size){
      size += next_mote;
      motes_eaten++;
    }
    else{

      // Option of just deleting everything instead of adding this mote
      delete_everything.push_back(motes.size() - motes_eaten);

      // Make an exception if adding a mote doesn't help
      if(size == 1){
        return motes.size();
      }

      // Oh no we can't. Add a mote.
      int added_mote = size-1;
      size += added_mote;
      moves++;
    }

  }

  int minmoves = moves;
  for(int i=0; i<delete_everything.size() ; i++){
    int pos = i + delete_everything[i];
    if(pos < minmoves) minmoves = pos;
  }

  return minmoves;

}



main(){

  int nc;
  cin>>nc;
  for(int i=1;i<=nc;i++){

    int init;
    int nm;
    cin>>init>>nm;

    vector<int> motes;

    while(nm--){
      int m;
      cin>>m;
      motes.push_back(m);
    }

    sort(motes.begin(),motes.end());
    int ans = sim(motes,init);
    cout << "Case #" << i << ": " << ans << endl;
  }

}

