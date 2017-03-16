#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char **argv) {
    unsigned int T, N;
    cin>>T;
    for(int c=1; c<=T; c++) {
      cin>>N;
      vector<string> cars(N);
      for(int i=0; i<N; i++) {
	cin>>cars[i];
// 	cout<<cars[i]<<endl;
	string::iterator it=unique(cars[i].begin(), cars[i].end());
	cars[i].resize( distance(cars[i].begin(), it) );
// 	cout<<cars[i]<<endl;
      }
      sort(cars.begin(), cars.end());
      vector<string>::iterator it=unique(cars.begin(), cars.end());
      unsigned long long int np=0, rep=cars.size();
      
      cars.resize( distance(cars.begin(),it) );
      
      rep-=cars.size();
      vector<bool> checked(256);
      do {
	for(int i=0; i<256; i++) checked[i]=false;
	char last=cars[0][0];
	bool posible=true;
	checked[cars[0][0]]=true;
// 	cout<<endl;
	for(int i=0; i<cars.size() && posible; i++) {
	  for(int j=0; j<cars[i].size() && posible; j++) {
// 	    cout<<cars[i][j];
	    if(cars[i][j] != last && checked[cars[i][j]])
	      posible=false;
	    checked[cars[i][j]]=true;
	    last=cars[i][j];
	  }
	}
	if(posible)
	  np++;
      } while( next_permutation(cars.begin(), cars.end()));
      cout<<"Case #"<<c<<": "<<(np*(rep+1))%1000000007<<endl;
    }
    return 0;
}
