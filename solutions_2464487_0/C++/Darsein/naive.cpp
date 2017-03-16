#include<iostream>
using namespace std;

int main(){
  int r,t,n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> r >> t;
    
    int ans = 0,sum = 0,now = r;
    while(1){
      if((r&1) == (now&1))sum-=now*now;
      else { sum+=now*now; ans++; }
      if(sum>t)break;
      now++;
    }
    cout << "Case #" << i << ": ";
    cout << ans-1 << endl;
  }
}
