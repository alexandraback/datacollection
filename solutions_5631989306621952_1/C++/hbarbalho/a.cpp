#include<iostream>
#include<string>
using namespace std;

int main(){
  long long t,T;
  string S;
  cin >> T;
  for(t=1;t<=T;++t){
    cin >> S;
    string ans(S);
    for(size_t i=1;i<S.size();++i){
      if(S[i]>=ans[0]){
        for(long long j=i-1;j>=0;--j)
          ans[j+1]=ans[j];
        ans[0]=S[i];
      }else
        ans[i]=S[i];
    }
    
    cout << "Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}
