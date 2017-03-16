#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

int main(int argc,char**argv){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N;
    cin>>N;
    vector<long long> nums(N);
    for (int i=0;i<N;i++){
      cin>>nums[i];
    }
    vector<int> test(2000000,0);
    int done=0;
    for (int i=1;i<(1<<N);i++){
      int tmpsum=0;
      for (int j=0;j<N;j++){
	if (i&(1<<j))
	  tmpsum+=nums[j];
      }
      if (test[tmpsum]!=0){
	int othi = test[tmpsum];
	int com = othi&i;
	othi^=com;
	i^=com;
	cout<<"Case #"<<t<<":"<<endl;
	for (int j=0;j<N;j++){
	  if (i&(1<<j))
	    cout<<nums[j]<<' ';
	}
	cout<<endl;
	for (int j=0;j<N;j++){
	  if (othi&(1<<j))
	    cout<<nums[j]<<' ';
	}
	cout<<endl;
	done=1;
	break;
      }
      else{
	test[tmpsum]=i;
      }
    }
    if (!done)
      cout<<"Case #"<<t<<": Impossible"<<endl;
  }
}
	    
