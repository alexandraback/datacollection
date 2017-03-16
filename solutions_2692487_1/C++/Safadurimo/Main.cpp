#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 

using namespace std;



int main() 
{
  int T,N,A;
  vector<int> motes;
  
  cin >> T;
  for(int i=1;i<=T;i++){
    cin >> A >> N;
    motes.clear();
    motes.resize(N);
    for(int j=0;j<N;j++) cin>> motes[j];
    sort(motes.begin(),motes.end());
    int best=motes.size();
    int current=0;
    while(current<best && motes.size()>0){
      if(motes[0]<A){
        A+=motes[0];
        motes.erase(motes.begin());
      }  
      else {
        A+=A-1;
        current++;
      }
      best=min(current+(int)motes.size(),best);
    }
    cout << "Case #" << i << ": " << best <<  endl;
  }

}
