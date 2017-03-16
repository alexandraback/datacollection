#include<iostream>

using namespace std;
double s[300];
double ss[300];
int main(){
  int cas;
  cin>>cas;
  for(int ca=1; ca<=cas; ++ca){
    int n;
    cin>>n;
    double S = 0;
    for(int i=0 ;i<n; ++i){
      cin>>s[i];
      S+=s[i];
    }

    cout<<"Case #"<<ca<<":";
    double nonneg = 0;
    double negs = 0;
    for(int i=0 ;i<n; ++i){
      ss[i] = 2*S/((double)n)-s[i];
      if (ss[i] < 0) {
        negs+=ss[i];
      }else {
        nonneg++;
      }
    }
    for(int i=0; i<n; ++i){
      if (ss[i]<0){
        ss[i] = 0;
      }else {
        ss[i] += negs/nonneg;
      }
      printf(" %.6f", ss[i]*100/S);
    }
    cout<<endl;
  }
}
