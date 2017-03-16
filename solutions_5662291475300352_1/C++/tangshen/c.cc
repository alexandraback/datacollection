#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
  int T;cin >> T;int idx = 0;
  while(T--){++idx;
    int N; cin >> N;
    vector<long long>Vst,Vsy;
    for(int i=0;i<N;++i){
      long long D,H,M;cin >> D >> H >> M;
      for(int i=0;i<H;++i){
        Vst.push_back((M+i)*(360-D));
        Vsy.push_back((M+i)*360);
      }
    }
    /*
    long long maxv1 = 0 ;
    for(int i=0;i<Vst.size();++i)
      maxv1 = max(maxv1,Vst[i]);
    long long ans = 0;
    for(int i=0;i<Vst.size();++i)
      ans += (maxv1-Vst[i])/Vsy[i];
    cout << ans << endl;
    */

    long long ans = -1;
    for(int i=0;i<Vst.size();++i){
      long long tans = 0;
      for(int j=0;j<Vst.size();++j){
        if(Vst[j]>=Vst[i]) ++tans;
        else {
          tans += (Vst[i]-Vst[j])/Vsy[j];
          if(((Vst[i]-Vst[j])%Vsy[j]==0))--tans;
        }
      }
      if(ans < 0) ans = tans;
      else ans = min(ans,tans);
    }
    for(int i=0;i<Vst.size();++i){
      long long tans = 0;
      for(int j=0;j<Vst.size();++j){
        if(Vst[j]>Vst[i]) ++tans;
        else {
          tans += (Vst[i]-Vst[j])/Vsy[j];
        }
      }
      if(ans < 0) ans = tans;
      else ans = min(ans,tans);
    }
    cout << "Case #" << idx << ": " << ans << endl;
  }
  return 0;
}
