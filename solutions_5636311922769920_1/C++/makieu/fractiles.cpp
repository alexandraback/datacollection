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
    long long K,C,S;
    cin>>K>>C>>S;
    if(C*S<K) cout<< "IMPOSSIBLE"<<endl;
    else{
      bool first = true;
      long long p=0;
      bool done = false;
      for(int i = 0; i<S && !done;i++){
        long long val = 0;
        for(int j=0;j<C;j++){
          val=val*K+p;
          p= (p+1)%K;
          if(p==0) done = true;
        }
        if (first) first = false;
        else cout << " ";
        cout<< val+1;
      }
      cout<<endl;
    }
  }
	return 0;
}
