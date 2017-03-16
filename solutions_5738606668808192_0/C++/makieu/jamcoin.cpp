#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;



int main(){
	int nb;
	cin >>nb;
	for(int i=0; i<nb; i++){
    cout << "Case #"<<i+1<<":"<<endl;
    int N,J;
    cin>>N>>J;
    long long num = (1<<(N-1))+1;
    int found =0;
    vector<int> div(15);
    while(num<(1<<N) && found < J){
      bool ok=true;
      for( int b=2;b<11&& ok;b++){
        bool done = false;
        for(int d=2;d<=2000;d++){
          if( d >=num){ok = false; break;}
          int mod=0;
          int v=1;
          for(int i=0;i<N;i++){
            if(num & (1<<i)) mod = (mod+ v)%d;
            v = (v*b)%d;         
          }
          if(mod==0){
            div[b]=d;
            done = true;
            break;
          }
        }
        if(!done) ok = false;
      }
      if (ok){
        for(int i=N-1;i>=0;i--)
          cout<< ((num>>i)& 1);
        cout<<" ";
        for(int i=2;i<11;i++) cout<< div[i]<<" ";
        cout<<endl;
        found++;
      }
      num+=2;
    }
  }
	return 0;
}
