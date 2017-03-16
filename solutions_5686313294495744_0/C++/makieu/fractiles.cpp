#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int main(){
	int nb;
	cin >>nb;
	for(int cases=0; cases<nb; cases++){
    cout << "Case #"<<cases+1<<": ";
    int N;
    cin>> N;
    
    set<string> rmap;
    set<string> lmap;
    vector<pair<string,string>> input(N);
    for(int i=0; i<N; i++){
      cin >>input[i].first>> input[i].second;
      lmap.insert(input[i].first);
      rmap.insert(input[i].second);
    }
    
    int worst =0;
    for(int i=0; i<(1<<N);i++){
      int tot =0;
      set<string> trmap;
      set<string> tlmap;
      for(int j=0; j<N;j++){
        if( i & 1<<j){
          tlmap.insert(input[j].first);
          trmap.insert(input[j].second);
        }else tot++;        
      }
      if(trmap.size() == rmap.size() && tlmap.size() == lmap.size() && worst < tot) worst = tot;
    }
  cout<<worst<<endl;
  }
	return 0;
}
