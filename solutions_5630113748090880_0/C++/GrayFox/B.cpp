#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif





int main(){
  int c[3000];
  int t;
  cin >> t;
  for(int tt = 1;tt<=t;tt++){
    int n;
    cin >> n;
    int q;
    memset(c,0,sizeof c);
    for(int i=0;i<2*n-1;i++){
      for(int j=0;j<n;j++){
        cin >> q;
        c[q]++;
      }
    }
    vector<int> ans;
    for(int i=0;i<3000;i++){
      if(c[i]%2){
        ans.push_back(i);
      }
    }
    cout<<"case #"<<tt<<": "<<ans[0];
    for (int i=1; i<ans.size(); i++) {
      cout<<" "<<ans[i];
    }
    cout<<endl;
  }


  return 0;
}
