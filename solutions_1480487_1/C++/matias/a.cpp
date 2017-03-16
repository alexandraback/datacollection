#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N;
    cin>>N;
    vector<int> nums(N);
    int sum=0;
    for (int i=0;i<N;i++){
      cin>>nums[i];
      sum+=nums[i];
    }
    cout<<"Case #"<<t<<": ";

    vector<int> sorted = nums;
    
    sort(sorted.begin(),sorted.end());
    reverse(sorted.begin(),sorted.end());

    double origsum=sum;

    int j;
    for (j=0;j<N;j++){
      if (sorted[j]>((sum+origsum)/(N-j))){
	sum-=sorted[j];
	continue;
      }
      break;
    }
    double needed=(sum+origsum)/(N-j);
    for (int i=0;i<N;i++){
      if (nums[i]>needed)
	cout<<0.0<<' ';
      else{
	cout<<100.0*(needed-nums[i])/origsum<<' ';
      }
    }
    cout<<endl;
  }
}
