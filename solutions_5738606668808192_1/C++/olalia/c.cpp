#include<iostream>
#include<vector>
#include<set>
#include<algorithm>




using namespace std;


typedef long long ll;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int N, J; cin>>N>>J;
    cout<<"Case #"<<tc<<":\n";
    for (int i=0; i<J; ++i){
      cout<<"1";
      for (int j=N/2-2; j>-1; --j){
	if ((1<<j)&i)
	  cout<<"11";
	else
	  cout<<"00";
      }
      cout<<"1 3 2 5 2 7 2 3 2 11\n";
    }

  }
  return 0;
}
