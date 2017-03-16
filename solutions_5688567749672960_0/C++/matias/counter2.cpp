#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int flip(int in) {
  int sum=0;
  while(in) {
    sum*=10;
    sum+=in%10;
    in/=10;
  }
  return sum;
}

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N;
    cin>>N;
    vector<int> nums(N+10,-1);
    nums[1]=1;
    queue<int> Q;
    Q.push(1);
    while(true) {
      int cur = Q.front();
      if (cur==N) break;
      Q.pop();
      if (nums[cur+1] == -1) {
	nums[cur+1] = nums[cur]+1;
	Q.push(cur+1);
      }
      int fl = flip(cur);
      if (fl <= N && nums[fl] == -1) {
	nums[fl] = nums[cur]+1;
	Q.push(fl);
      }
    }
    cout<<"Case #"<<t<<": "<<nums[N]<<endl;
  }
}
