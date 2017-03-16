#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int A;
    int N;
    cin>>A>>N;
    vector<int> num(N);
    for (int i=0;i<N;i++){
      cin>>num[i];
    }
    sort(num.begin(),num.end());
    int best = N;
    int cur = 0;
    if (A == 1) {
      goto end;
    }
    for (int i=0;i<N;i++){
      while (A<=num[i]){
	A+=(A-1);
	cur++;
      }
      A+=num[i];
      if (cur+N-i-1 < best) {
	best = cur+N-i-1;
      }
    }
  end:
    cout<<"Case #"<<t<<": "<<best<<endl;
  }
}
