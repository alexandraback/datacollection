#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
  int N;
  cin>>N;
  for (int n=1;n<=N;n++){
    int T;
    cin>>T;
    vector<double> A(T);
    vector<double> B(T);
    for (int i=0;i<T;i++){
      cin>>A[i];
    }
    for (int i=0;i<T;i++){
      cin>>B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int normalwar=0;
    int bidx=T-1;
    for (int i=T-1;i>=0;i--){
      if (A[i]>B[bidx])
	normalwar++;
      else
	bidx--;
    }
    
    int specialwar=0;
    int bstart=0;
    for (int i=0;i<T;i++){
      if (A[i]>B[bstart]) {
	bstart++;
	specialwar++;
      }
    }
      
    printf("Case #%d: %d %d\n",n,specialwar, normalwar);
  }

}
