#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A,B,K;
void solve(){
  cin>>A>>B>>K;
  long long int count = 0;
  for(int a=0;a<A;a++)
    for(int b=0;b<B;b++)
      if ( (a & b) < K)
	count++;
  cout<<count;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
}
