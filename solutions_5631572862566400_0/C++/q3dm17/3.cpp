#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
  int t ; cin >> t;
  for(int cse = 1 ; cse <= t; cse ++){
    cout<<"Case #"<<cse<<": ";
    int n ; cin >> n;
    vector<int> f(n);
    vector<int> a;
    int ans= 1;
    for(int i=0; i <n ; i ++){
      cin>>f[i];
      f[i] --;
      a.push_back(i);
    }
    do{
      //for(int i =0 ; i <n ; i ++) cout<<a[i]<<" "; cout<<endl;
      //for(int i =0 ; i <n ; i ++) cout<<f[a[i]]<<" "; cout<<endl;
      for(int len = 2; len <= n ; len++){
        int good = 1;
        for(int i =0 ; good and i <len; i ++){
          if( f[a[i]] == a[(i+1)%len]) continue;
          if( f[a[i]] == a[(i-1+len)%len]) continue;
          //cout<<"breaking "<<a[i]<<endl;
          good = 0;
          break;
        }
        if(good)
          if(ans<len) ans = len;
      }
      //cout<<ans<<endl;
    }while(next_permutation(a.begin(), a.end()));
    cout<<ans<<endl;
  }
}
