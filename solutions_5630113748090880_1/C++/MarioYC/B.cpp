#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

int main(){
  int T,N;
  int cont[2501];

  cin >> T;
  
  for(int tc = 1;tc <= T;++tc){
  	cin >> N;
  	memset(cont,0,sizeof cont);

  	for(int i = 0;i < 2*N - 1;++i){
  		for(int j = 0,x;j < N;++j){
  			cin >> x;
  			cont[x] ^= 1;
  		}
  	}

    cout << "Case #" << tc << ":";
    
    int check = 0;

    for(int j = 1;j <= 2500;++j){
    	if(cont[j] == 1){
    		cout << " " << j;
    		++check;
    	}
    }

    assert(check == N);

    cout << "\n";
  }
  
  return 0;
}
