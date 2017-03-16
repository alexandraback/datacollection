#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    int N;
    cin>>N;
    cout<<"Case #"<<t<<": ";
    if(N==0){
      cout<<"INSOMNIA\n";
      continue;
    }

    int cur = 0, num_of_seen=0;
    vector<int> not_seen(10,1);
    while(num_of_seen<10){
      cur += N;
      for(int c = cur; c; c/=10){
	num_of_seen += not_seen[c%10];
	not_seen[c%10]=0;
      }
    }
    cout<<cur<<endl;
  }
  return 0;
}
